module Euler
  PHI = (Math.sqrt(5) + 1) / 2
  ROOT5 = Math.sqrt(5)

  def self.fibonacci(n)
    (PHI**n / ROOT5).round
  end
end

