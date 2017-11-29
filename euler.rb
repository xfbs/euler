#!/usr/bin/env ruby
# yes, this script is what you would call ugly. it's a mess. but it's not meant
# to be seen, or to win any beauty contests — it's supposed to kinda do it's
# job while still being flexible enough so that you can change it around and
# hack something together if you need to. if you proceed from here... you have
# been warned.

require 'optparse'


class Problem
  BASEDIR = "src"
  attr_accessor :path, :num, :slug

  def self.all
    Pathname.new(BASEDIR).children
      .select{|entry| File.directory? entry}
      .map{|entry| Problem.new entry.to_s}
      .sort
  end

  def initialize p
    p = Dir["#{BASEDIR}/#{p}*"][0] unless p.class == String
    throw "invalid problem" unless File.exists?(File.join(p, "problem.md"))
    @path = p
    @slug = File.basename(p)
    @num = @slug.scan(/(\d\d\d).*/)[0][0]
  end

  def implementations
    Pathname.new(@path).children
      .select{|entry| File.directory? entry}
      .map{|entry| Implementation.new entry.to_s}
  end

  def has_solution?
    !Dir["#{@path}/.solution.bcrypt"].empty?
  end

  def check_solution sol
    return false unless has_solution?
    hash = File.read(File.join(@path, ".solution.bcrypt"))
    p = BCrypt::Password.new(hash)
    p.is_password? sol
  end

  def <=> other
    num <=> other.num
  end
end

class Implementation
  attr_accessor :path, :problem, :lang

  def self.all
    impls = []

    Problem.all.each do |prob|
      prob.implementations.each do |impl|
        impls.unshift impl
      end
    end

    impls.sort
  end

  def initialize path
    @path = path
    @problem = Problem.new File.dirname(@path)
    @lang = File.basename(@path)
  end

  def solve
    stdout, _, status = Open3.capture3("cd \"#{@path}\" && make solve")

    # throw exception if stderr is not empty?
    return nil if status != 0
    stdout.chomp
  end

  def build
    _, _, status = Open3.capture3("cd \"#{@path}\" && make")
    status == 0
  end

  def test
    _, _, status = Open3.capture3("cd \"#{@path}\" && make test")
    status == 0
  end

  def clean
    _, _, status = Open3.capture3("cd \"#{@path}\" && make clean")
    status == 0
  end

  def check
    build
    solution = solve
    @problem.check_solution solution if solution
  end

  def <=> other
    rough = problem <=> other.problem

    if rough == 0
      lang <=> other.lang
    else
      rough
    end
  end
end

class ActionCheck
  class Formatter
    def initialize
    end

    def verbose
      @verbose = true
    end

    def color
      @color = true
    end

    def setup
    end

    def result _, _
    end

    def done
    end
  end

  class Standard < Formatter
    def initialize
      super
    end

    def setup
      puts "checking euler solutions"
    end

    def result impl, result
      if result.nil?
        print "error "
      elsif !result
        print "wrong "
      else
        print "right "
      end

      puts impl.path
    end
  end

  class Summary < Formatter
    def initialize
      super
    end

    def setup
      ps = Problem.all.each_slice(20).to_a
      ps.each do |line|
        line.each do |p|
          print "#{p.num} "
        end
        puts
      end
    end
  end

  def initialize
    require 'pathname'
    require 'open3'
    require 'bcrypt'
  end

  def setup
    OptionParser.new do |opts|
      opts.banner = "Usage: #{__FILE__} build [options]"
      opts.version = "1.0.0"
      opts.on('-v', 'verbose') do |o|
        @verbose = true
      end
      opts.on('-s', 'summary') do |o|
        @summary = true
      end
      opts.on('-c', 'color') do |o|
        @color = true
      end
    end.parse!

    if @summary
      @formatter = Summary.new
    else
      @formatter = Standard.new
    end

    @formatter.color if @color
    @formatter.verbose if @verbose

    self
  end

  def run
    @formatter.setup
    Implementation.all.each do |impl|
      result = impl.check
      @formatter.result(impl, result)
    end
    @formatter.done
  end
end

class ActionBuild
  def initialize
    require 'pathname'
    require 'open3'
  end

  def setup
  end

  def run
    Implementation.all.each do |impl|
      result = impl.build

      if !result
        print "error "
      else
        print "built "
      end

      puts impl.path
    end
  end
end

class ActionClean
  def initialize
    require 'pathname'
    require 'open3'
  end

  def setup
    self
  end

  def run
    Implementation.all.each do |impl|
      result = impl.clean

      if !result
        print "error "
      else
        print "cleaned "
      end

      puts impl.path
    end
  end
end

class ActionTest
  def initialize
    require 'pathname'
    require 'open3'
  end

  def setup
    self
  end

  def run
    Implementation.all.each do |impl|
      result = impl.test

      if !result
        print "error "
      else
        print "tested "
      end

      puts impl.path
    end
  end
end

def find_command
  OptionParser.new do |opts|
    opts.banner = "Usage: euler.rb [command] [options]"
    opts.version = "1.0.0"
    opts.separator ""
    opts.separator <<HELP
Commonly used commands are:
  build:  builds all solutions
  check:  checks the solutions
  clean:  cleans the build cache
   test:  runs tests for all solutions

See 'euler.rb COMMAND --help' for more information.
HELP
  end.order!
  ARGV.shift
end

actions = {
  'check' => ActionCheck,
  'build' => ActionBuild,
  'clean' => ActionClean,
  'test' => ActionTest
}

command = find_command
begin
  actions[command].new.setup.run
rescue Exception => e
  puts "error while executing the command"
  puts e
  puts e.backtrace
end
