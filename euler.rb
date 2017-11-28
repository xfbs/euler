#!/usr/bin/env ruby

require 'pathname'
require 'open3'
require 'bcrypt'

class Problem
  BASEDIR = "src"
  attr_accessor :path

  def self.all
    Pathname.new(BASEDIR).children
      .select{|entry| File.directory? entry}
      .map{|entry| Problem.new entry.to_s}
  end

  def initialize p
    p = Dir["#{BASEDIR}/#{p}*"][0] unless p.class == String
    throw "invalid problem" unless File.exists?(File.join(p, "problem.md"))
    @path = p
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
end

class Implementation
  attr_accessor :path

  def self.all
    impls = []

    Problem.all.each do |prob|
      prob.implementations.each do |impl|
        impls.unshift impl
      end
    end

    impls
  end

  def initialize path
    @path = path
    @problem = Problem.new File.dirname(@path)
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
end

Implementation.all.each do |impl|
  result = impl.check

  if result.nil?
    print "error "
  elsif result
    print "right "
  else
    print "wrong "
  end

  puts impl.path
end

