require 'fileutils'

Dir["../../src/*/c/src/euler/*.h"]
  .each{|f| puts "symlinking #{f}..."; FileUtils.symlink("../../#{f}", 'include/euler/')}

Dir["../../src/*/c/src/*.c"]
  .select{|f| f.scan(/solve.c/).length == 0}
  .select{|f| f.scan(/main.c/).length == 0}
  .each{|f| puts "symlinking #{f}..."; FileUtils.symlink("../#{f}", 'src/')}
