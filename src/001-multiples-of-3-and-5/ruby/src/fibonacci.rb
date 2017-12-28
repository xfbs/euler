module Fibonacci
  PHI = (1 + Math.sqrt(5)) / 2
  ROOT5 = Math.sqrt(5)

  def self.nth n
    (PHI**n / ROOT5).round
  end
end

