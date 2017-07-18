require 'euler/problems'
require 'euler/implementation'
require 'yaml'

module Euler
  class Solutions
    attr_accessor :problems, :languages
    def initialize problems, languages, solutions_dir=nil
      @solutions_dir = solutions_dir
      @problems = problems
      @languages = languages
      @solutions = {}
    end

    def load_all(solutions_dir)
      @solutions_dir = solutions_dir
      @problems.each do |problem|
        solution = Solution.new problem, @languages
        solution.load solutions_dir

        @solutions[problem] = solution
      end
    end

    def each
      @solutions.keys.sort.each do |p|
        yield @solutions[p]
      end
    end

    # returns a solution, n is either a Problem or a problem number
    def [] n
      @solutions[n] || @solutions[@problems[n]]
    end
  end

  class Solution
    attr_accessor :problem

    def initialize problem, languages, solutions_dir=nil
      @solutions_dir = solutions_dir
      @problem = problem
      @languages = languages
      @implementations = {}
    end

    def load solutions_dir=@solutions_dir
      @solutions_dir = solutions_dir
      @languages.each do |ext, lang|
        path = File.join(solutions_dir, @problem.make_path(ext))
        if Dir.exists? path
          @implementations[ext] = Implementation.new(@problem, path, lang)
        end
      end
    end

    def implemented?
      @implementations.length != 0
    end

    def [] lang
      @implementations[lang]
    end

    def create_implementation ext
      path = File.join(@solutions_dir, @problem.make_path(ext))

      if Dir.exists? path then
        raise "Directory for implementation exists: #{path}"
      elsif not @languages[ext] then
        raise "Language #{ext} unknown"
      else
        # create directory for implementation
        Dir.mkdir path
        @implementations[ext] = Implementation.new(@problem, path, @languages[ext])
      end

      @implementations[ext]
    end

    def each
      @implementations.values.each do |impl|
        yield impl
      end
    end

    def move new_slug
      saved = nil

      @implementations.values.each do |implementation|
        path = implementation.path
        ext = implementation.lang['ext']
        newpath = File.join(@solutions_dir, Problem.make_path(@problem.number, new_slug, ext))
        begin
          File.rename(path, newpath)
        rescue e
          saved = e
        end
      end

      raise saved if saved
      true
    end
  end
end
