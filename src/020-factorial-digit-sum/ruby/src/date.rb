class Date
  attr_accessor :day, :weekday, :month, :year
  # weekday constants
  MONDAY    = 0
  TUESDAY   = 1
  WEDNESDAY = 2
  THURSDAY  = 3
  FRIDAY    = 4
  SATURDAY  = 5
  SUNDAY    = 6
  WEEKDAY_MAX = 7

  # month constants
  JANUARY   = 0
  FEBRUARY  = 1
  MARCH     = 2
  APRIL     = 3
  MAY       = 4
  JUNE      = 5
  JULY      = 6
  AUGUST    = 7
  SEPTEMBER = 8
  OCTOBER   = 9
  NOVEMBER  = 10
  DECEMBER  = 11
  MONTH_MAX = 12

  def initialize weekday, day, month, year
    @weekday = weekday
    @day = day
    @month = month
    @year = year
  end

  def leap_year?
    # it's a leap year if the year is divisible by 4. unless it's divisible by
    # 100, then it's not a leap year. unless it's also divisible by 400, then
    # it's a leap year regardless.
    ((@year % 400) == 0) || (((@year % 4) == 0) && ((@year % 100) != 0))
  end

  def month_length
    case @month
    when SEPTEMBER, APRIL, JUNE, NOVEMBER
      30
    when FEBRUARY
      if leap_year?
        29
      else
        28
      end
    when JANUARY, MARCH, MAY, JULY, AUGUST, OCTOBER, DECEMBER
      31
    end
  end

  def next_month!
    distance = month_length
    distance -= @day - 1

    @day = 1
    @weekday = (@weekday + distance) % WEEKDAY_MAX

    if @month == DECEMBER
      @year += 1
    end

    @month = (@month + 1) % MONTH_MAX
  end

  def <(other)
    return true if @year < other.year
    return false if @year > other.year

    return true if @month < other.month
    return false if @month > other.month

    return true if @day < other.day
    return false if @day > other.day

    false
  end

  def ==(other)
    @year == other.year &&
      @month == other.month &&
      @day == other.day &&
      @weekday == other.weekday
  end
end
