module Solver
  def self.solve(num)
    cur = 2
    while !is_prime?(num)
      if (num % cur) == 0
        num /= cur
      else
        cur += 1
        while !is_prime?(cur)
          cur += 1
        end
      end
    end

    num
  end

  def self.is_prime?(num)
    return false if num < 2
    return false if num > 2 && (num % 2) == 0

    max_check = Math.sqrt(num)
    (3..max_check).step(2) do |d|
      return false if (num % d) == 0
    end

    true
  end
end
