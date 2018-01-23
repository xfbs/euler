module Solver
  def self.solve(divisors)
    substrdiv(divisors).sum
  end

  def self.substrdiv(divs)
    divs.unshift(1)
    (0..999).step(divs[-1]).map do |n|
      nums = [n/100, (n/10) % 10, n % 10]
      if nums.uniq == nums
        substrdiv_step(divs[0..-2], nums)
      else
        [] of Int64
      end
    end.flatten
  end

  def self.substrdiv_step(divs, nums)
    if divs.empty?
      [nums.reduce(0i64) { |m, c| m*10 + c }]
    else
      (0..9)
        .select { |n| ((100*n + 10*nums[0] + nums[1]) % divs[-1]) == 0 }
        .select { |n| !nums.includes? n }
        .map { |n| substrdiv_step(divs[0..-2], [n] + nums).as(Array(Int64)) }
        .flatten
    end
  end
end
