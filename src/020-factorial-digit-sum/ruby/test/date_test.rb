require 'minitest/autorun'
require_relative '../src/date'

class DateTest < MiniTest::Test
  def with_year year
    Date.new(Date::MONDAY, 1, Date::JANUARY, year)
  end

  def with_month month
    Date.new(Date::MONDAY, 1, month, 1900)
  end

  def with_leap_month month
    Date.new(Date::MONDAY, 1, month, 1904)
  end

  def test_month_length
    assert_equal with_month(0).month_length, 31
    assert_equal with_month(1).month_length, 28
    assert_equal with_month(2).month_length, 31
    assert_equal with_month(3).month_length, 30
    assert_equal with_month(4).month_length, 31
    assert_equal with_month(5).month_length, 30
    assert_equal with_month(6).month_length, 31
    assert_equal with_month(7).month_length, 31
    assert_equal with_month(8).month_length, 30
    assert_equal with_month(9).month_length, 31
    assert_equal with_month(10).month_length, 30
    assert_equal with_month(11).month_length, 31
  end

  def test_leap_month_length
    assert_equal with_leap_month(0).month_length, 31
    assert_equal with_leap_month(1).month_length, 29
    assert_equal with_leap_month(2).month_length, 31
    assert_equal with_leap_month(3).month_length, 30
    assert_equal with_leap_month(4).month_length, 31
    assert_equal with_leap_month(5).month_length, 30
    assert_equal with_leap_month(6).month_length, 31
    assert_equal with_leap_month(7).month_length, 31
    assert_equal with_leap_month(8).month_length, 30
    assert_equal with_leap_month(9).month_length, 31
    assert_equal with_leap_month(10).month_length, 30
    assert_equal with_leap_month(11).month_length, 31
  end

  def test_leap_year
    assert_equal with_year(1900).leap_year?, false
    assert_equal with_year(2000).leap_year?, true
    assert_equal with_year(1904).leap_year?, true
    assert_equal with_year(1907).leap_year?, false
    assert_equal with_year(1912).leap_year?, true
    assert_equal with_year(1601).leap_year?, false
  end

  def test_next_month
    date = Date.new(Date::FRIDAY, 1, Date::JANUARY, 2016)
    assert_equal date, Date.new(4, 1, 0, 2016)

    date.next_month!
    assert_equal date, Date.new(0, 1, 1, 2016)
    date.next_month!
    assert_equal date, Date.new(1, 1, 2, 2016)
    date.next_month!
    assert_equal date, Date.new(4, 1, 3, 2016)
    date.next_month!
    assert_equal date, Date.new(6, 1, 4, 2016)
    date.next_month!
    assert_equal date, Date.new(2, 1, 5, 2016)
    date.next_month!
    assert_equal date, Date.new(4, 1, 6, 2016)
    date.next_month!
    assert_equal date, Date.new(0, 1, 7, 2016)
    date.next_month!
    assert_equal date, Date.new(3, 1, 8, 2016)
    date.next_month!
    assert_equal date, Date.new(5, 1, 9, 2016)
    date.next_month!
    assert_equal date, Date.new(1, 1, 10, 2016)
    date.next_month!
    assert_equal date, Date.new(3, 1, 11, 2016)
    date.next_month!
    assert_equal date, Date.new(6, 1, 0, 2017)
  end
end
