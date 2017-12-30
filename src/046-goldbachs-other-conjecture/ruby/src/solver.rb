require "euler/prime"

module Solver
  def self.solve
    p = Euler::Prime.new

    (3..Float::INFINITY)
      .step(2)
      .lazy
      .map{|n| n.to_i}
      .select{|n| p.index(n).nil?}
      .find{|n|
      !p.lazy
        .drop(1)
        .take_while{|p| p < n}
        .map{|p| (n - p) / 2}
        .any?{|i| Math.sqrt(i).to_i**2 == i}}
  end
end
