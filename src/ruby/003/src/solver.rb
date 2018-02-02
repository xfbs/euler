module Solver
  def self.solve(num)
    cur = 2
    until is_prime?(num)
      if (num % cur) == 0
        num /= cur
      else
        cur += 1
        cur += 1 until is_prime?(cur)
      end
    end

    num
  end

  def self.is_prime?(num)
    return false if num < 2
    return false if num > 2 && num.even?

    max_check = Math.sqrt(num)
    (3..max_check).step(2) do |d|
      return false if (num % d) == 0
    end

    true
  end
end
