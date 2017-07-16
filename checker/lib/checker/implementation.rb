require 'pathname'
require 'fileutils'

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

    def link_data_file solutions_dir, data_dir
      implementation_dir = Pathname.new @path
      implementation_data = File.join(implementation_dir, @problem.data)

      # make sure we don't overwrite something
      if File.exists?(implementation_data)
        return false
      end

      data_file_name = "#{problem.number.to_s.rjust(3,'0')}-#{@problem.data}"
      data_file = Pathname.new File.join(data_dir, data_file_name)

      FileUtils.symlink(data_file.relative_path_from(implementation_dir), implementation_data)

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
