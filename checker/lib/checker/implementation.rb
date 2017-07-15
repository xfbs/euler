module Checker
  class Implementation
    attr_reader :path, :lang
    def initialize path, lang
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
        Dir[File.join(skeleton, '*')].each{ |f| FileUtils.cp(f, @path) }
      end

      true
    end
  end
end
