module Solver
  # find the p that is 1 <= p <= max such that there is a maximum amount of
  # solutions {a, b, c} that are pythagorean triplets and a + b + c = p
  def self.solve(max)
    (1..max)
      .to_a
      .sort_by{|n| number_of_solutions(n)}
      .last
  end

  # how many {a, b, c} are there, such that
  # a + b + c = p,
  # a < b < c
  # a^2 + b^2 = c^2
  # are all fulfilled?
  def self.number_of_solutions(p)
    (1..((p-3)/3))
      .count{|a| ((p * (2 * a - p)) % (2 * (a - p))) == 0}
  end
end
