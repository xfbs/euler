module Solver
  def self.solve names
    names
      .sort
      .each_with_index
      .map{|name, index| weight(name) * (index + 1)}
      .inject(:+)
  end

  def self.weight name
    name.bytes.map{|n| n - 'A'.bytes[0] + 1}.inject(:+)
  end
end
