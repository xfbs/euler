module Solver
  def self.solve(nums)
    nums.map{|n| n[0..10].to_i}.inject(0, :+).to_s[0..9].to_i
  end
end

if __FILE__ == $0
  throw "no data file supplied" unless ARGV[0]
  numbers = File.open(ARGV[0]).read.split("\n")
  puts Solver.solve(numbers)
end
