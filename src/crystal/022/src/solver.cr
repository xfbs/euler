module Solver
  def self.solve(names)
    names
      .sort
      .each_with_index
      .map { |line| name, index = line; weight(name) * (index + 1) }
      .sum
  end

  def self.weight(name)
    name
      .bytes
      .map { |n| n.to_u32 - 'A'.bytes[0] + 1 }
      .sum
  end
end
