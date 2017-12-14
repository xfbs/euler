module Solver
  def self.solve(array, index)
    return array if array.size < 2
    p = permutations(array.size - 1)
    o = index / p
    c = array.delete_at(o)
    [c] + solve(array, index % p)
  end

  def self.permutations(len)
    (1..len).reduce(1_u64){|a, b| a * b}
  end
end
