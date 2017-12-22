require_relative 'solver'

s = Date.new(Date::MONDAY, 1, Date::JANUARY, 1900)

# proceed one year
12.times do
  s.next_month!
end

e = Date.new(Date::MONDAY, 31, Date::DECEMBER, 2000)

puts Solver.solve(s, e)
