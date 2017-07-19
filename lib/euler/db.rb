require 'yaml'

# note: for dumping the data to yaml, might have a look at
# http://www.rubydoc.info/gems/psych/Psych#to_json-class_method
# as well as
# http://yaml4r.sourceforge.net/doc/page/type_families.htm
# for coming up with some nicer ways to dump these :)

# note: do we need a language class?

module Euler
  class DB
    def initialize file
      @db_file = file
    end

    def read
      raise "db read already" if @db

      # read in database
      File.open(file, 'r') do |fh|
        # parse database
        @db = YAML.load(db)
      end

      @db['langs'] ||= {}
      @db['probs'] ||= {}

      true
    end

    def language lang={}
      return @db['langs'] if @db['langs'][lang]
    end


  end
end
