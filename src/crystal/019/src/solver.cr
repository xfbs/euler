require "./date"

module Solver
  def self.solve(s, e)
    count = 0

    if s.day == 1 && s.weekday == Date::SUNDAY
      count = 1
    end

    s.next_month!

    while s < e
      count += 1 if s.weekday == Date::SUNDAY
      s.next_month!
    end

    count
  end
end
