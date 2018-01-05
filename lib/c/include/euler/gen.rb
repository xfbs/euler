require 'fileutils'

Dir["../../../../src/*/c/*.h"]
  .select{|n| n.scan(/solve.h/).length == 0}
  .each{|f| FileUtils.symlink(f, '.')}
