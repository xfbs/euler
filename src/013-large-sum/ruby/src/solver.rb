module Solver
  def self.solve(nums)
    nums.map{|n| n[0..10].to_i}.inject(0, :+).to_s[0..9].to_i
  end
end
