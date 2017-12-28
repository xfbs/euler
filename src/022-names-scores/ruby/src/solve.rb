require_relative 'solver'

throw "no data file supplied" unless ARGV[0]
names = File.open(ARGV[0]).read
puts Solver.solve(names.split(',').map{|n| n[1..-2]})
