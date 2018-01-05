require 'fileutils'

Dir["../../src/*/c/src/euler/*.h"]
  .select{|f| !File.exists? "include/euler/#{File.basename(f)}"}
  .each{|f| puts "symlinking #{f}..."; FileUtils.symlink("../../#{f}", 'include/euler/')}

Dir["../../src/*/c/src/*.c"]
  .select{|f| f.scan(/solve.c/).length == 0}
  .select{|f| f.scan(/main.c/).length == 0}
  .select{|f| !File.exists? "src/#{File.basename(f)}"}
  .each{|f| puts "symlinking #{f}..."; FileUtils.symlink("../#{f}", 'src/')}
