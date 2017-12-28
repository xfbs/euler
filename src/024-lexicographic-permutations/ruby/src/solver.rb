module Solver
  def self.solve array, index
    return array if array.length < 2
    p = permutations(array.length - 1)
    o = index / p
    c = array.delete_at(o)
    [c] + solve(array, index % p)
  end

  def self.permutations len
    (1..len).inject(1, :*)
  end
end
