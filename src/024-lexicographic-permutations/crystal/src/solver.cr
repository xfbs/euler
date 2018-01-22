require "euler/factorial"

module Solver
  def self.solve(array, index)
    permutation(array.dup, index).join("")
  end

  def self.permutation(array, nth)
    return array if array.size < 2
    p = Euler.factorial64(array.size - 1)
    o = nth / p
    c = array.delete_at(o)
    [c] + permutation(array, nth % p)
  end
end
