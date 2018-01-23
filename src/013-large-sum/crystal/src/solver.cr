module Solver
  def self.solve(nums)
    nums.map { |n| n[0..10].to_u64 }.sum.to_s[0..9].to_u64
  end
end
