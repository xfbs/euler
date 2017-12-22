require_relative 'date'

module Solver
  def self.solve s, e
    count = (s.day == 1 && s.weekday == Date::SUNDAY) && 1 || 0
    s.next_month!

    while s < e
      count += 1 if s.weekday == Date::SUNDAY
      s.next_month!
    end

    count
  end
end
