Dir[File.join(File.dirname(__FILE__), "*")].select do |test|
  test != __FILE__
end.each do |test|
  require_relative File.basename(test)
end
