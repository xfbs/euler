require "euler/version"
require "euler/problems"
require "euler/implementation"
require "euler/solutions"
require 'yaml'

module Euler
  module Languages
    def self.load file
      f = File.open(file, 'r')
      langs = YAML.load(f.read)
      f.close

      raise "Error loading languages" unless langs && langs.class == Hash

      langs.each do |ext, lang|
        lang['ext'] = ext
        lang['name'] = lang['name'] || ext
      end

      langs
    end
  end
  # Your code goes here...
end
