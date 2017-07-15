require 'bcrypt'
require 'yaml'

module Checker
  class Problems
    def initialize(problems, opts={})
      @problems = problems
      @file = opts[:file]
    end

    def self.load(file)
      problems_raw = YAML.load(File.open(file, 'r').read)
      problems = {}
      problems_raw.each do |number, props|
        name = props['name']
        solution = props['solution']
        problems[number.to_i] = Problem.new(number.to_i, name, solution)
      end
      Problems.new(problems, :file => file)
    end

    def to_s
      data = {}

      @problems.each do |number, problem|
        if problem.name
          data[number] = {"name" => problem.name}
          if problem.solution
            data[number]['solution'] = problem.solution.to_s
          end
        end
      end

      data.to_yaml
    end

    def save(file=@file)
      f = File.open(file, 'w')
      f.write(self.to_s)
      f.close
    end

    def [] n
      unless @problems[n]
        @problems[n] = Problem.new(n, nil, nil)
      end

      @problems[n]
    end

    def each
      @problems.each_value do |problem|
        yield problem
      end
    end
  end

  class Problem
    attr_reader :number
    attr_accessor :name

    def initialize(number, name, solution=nil)
      @number = number
      @name = name
      @solution = BCrypt::Password.new(solution) if solution
    end

    def check(solution)
      @solution.is_password? solution.to_s
    end

    def solution=(solution)
      @solution = BCrypt::Password.create(solution.to_s)
    end

    def solution
      @solution.to_s if @solution
    end

    def slug
      @name.downcase.gsub(/[^0-9a-z ]/, '').gsub(' ', '-') if @name
    end

    def exists?
      @name
    end

    def <=> other
      @number <=> other.number
    end

    def make_path ext
      "#{@number.to_s.rjust(3, '0')}-#{slug}.#{ext}"
    end
  end
end
