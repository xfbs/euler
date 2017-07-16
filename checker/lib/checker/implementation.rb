module Checker
  class Implementation
    attr_reader :path, :lang, :problem

    def initialize problem, path, lang
      @problem = problem
      @path = path
      @lang = lang

      # commands to do certain things with implementation
      @build = lang['build'] || "make build"
      @init  = lang['init']  || "make init"
      @test  = lang['test']  || "make test"
      @solve = lang['solve'] || "make solve"
    end

    def create skeleton_dir
      skeleton = File.join(skeleton_dir, "skeletons", lang['name'])
      if not Dir.exists? skeleton
        return false
      else
        # copy skeleton files over
        FileUtils.cp_r(File.join(skeleton, '.'), @path)
      end

      true
    end

    def solve
      `cd #{path} && #{@solve}`
    end

    def check
      @problem.check(solve.chomp)
    end
  end
end
