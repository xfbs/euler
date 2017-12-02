module Solution
  def self.solve max
    (1..max).map{|n| [n, reciprocal_cycle(n)]}.max_by{|n| n[1]}[0]
  end

  def self.reciprocal_cycle num
    num /= 2 while (num % 2) == 0
    num /= 5 while (num % 5) == 0
    return 0 if num == 1

    cycle = 1
    cycle += 1 while ((10**cycle - 1) % num) != 0
    cycle
  end
end
