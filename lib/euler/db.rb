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
      @file = file
    end

    def read
      raise "db read already" if @db

      # read in database
      File.open(@file, 'r') do |fh|
        # parse database
        @db = YAML.load(fh)
      end

      @db['probs'].map! do |num, prop|
        prop['name'] ||= "Unknown"
        prop['number'] = num
        Problem.new prop
      end

      @db['langs'].map! do |ext, lang|
        lang['ext'] = ext
      end

      true
    end

    def save!(to: @file)
      File.open(to, 'w').write(to_yaml)
    end

    def lang param={}
      @db['langs'].find do |ext, lang|
        param.all? do |key, value|
          lang[key] == value
        end
      end
    end

    def path name=nil
      if name
        @db['paths'][name]
      else
        @db['paths']
      end
    end

    def problem query={}
      @db['probs'].find do |num, prob|
        {
          'number' => prob.number,
          'name' => prob.name,
          'slug' => prob.slug,
          'data' => prob.data
        }.map do |p, val|
           val == query[p] if query[p]
        end.compact.all?
      end
    end

    def to_yaml
    end

    def init_with
    end

  end
end

Psych.add_tag('!euler.xfbs.net/db', Euler::DB)
