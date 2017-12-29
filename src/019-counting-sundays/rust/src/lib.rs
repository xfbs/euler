use std::cmp::PartialOrd;
use std::cmp::PartialEq;
use std::cmp::Ordering;

#[derive(Debug)]
pub struct Date {
    weekday: u32,
    day: u32,
    month: u32,
    year: u32,
}

impl Date {
    pub fn new(weekday: u32, day: u32, month: u32, year: u32) -> Self {
        Date {weekday: weekday, day: day, month: month, year: year}
    }

    pub fn is_leap_year(&self) -> bool {
        (self.year % 400 == 0) || (self.year % 4 == 0 && self.year % 100 != 0)
    }

    pub fn month_length(&self) -> u32 {
        match self.month {
            8 | 3 | 5 | 10 => 30,
            1 => {
                if self.is_leap_year() {
                    29
                } else {
                    28
                }
            },
            _ => 31,
        }
    }

    pub fn next_month(&self) -> Date {
        Date {
            day: 1,
            year: if self.month == 11 {
                self.year + 1
            } else {
                self.year
            },
            month: (self.month + 1) % 12,
            weekday: (self.weekday + (self.month_length() - self.day + 1)) % 7
        }
    }
}

impl PartialEq for Date {
    fn eq(&self, other: &Self) -> bool {
        if self.year == other.year {
            if self.month == other.month {
                if self.day == other.day {
                    return true;
                }
            }
        }

        return false;
    }
}


impl PartialOrd for Date {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        match self.year.partial_cmp(&other.year) {
            Some(Ordering::Less) => Some(Ordering::Less),
            Some(Ordering::Greater) => Some(Ordering::Greater),
            Some(Ordering::Equal) => match self.month.partial_cmp(&other.month) {
                Some(Ordering::Less) => Some(Ordering::Less),
                Some(Ordering::Greater) => Some(Ordering::Greater),
                Some(Ordering::Equal) => match self.day.partial_cmp(&other.day) {
                    Some(Ordering::Less) => Some(Ordering::Less),
                    Some(Ordering::Greater) => Some(Ordering::Greater),
                    Some(Ordering::Equal) => Some(Ordering::Equal),
                    _ => None
                },
                _ => None
            },
            _ => None
        }
    }
}

pub fn solve(start: Date, end: Date) -> u32 {
    let mut cur = start;
    let mut cnt = 0;

    if cur.day == 1 && cur.weekday == 6 {
        cnt += 1;
    }

    cur = cur.next_month();

    while cur < end {
        if cur.weekday == 6 {
            cnt += 1;
        }

        cur = cur.next_month();
    }

    cnt
}

/*
  def with_year(year)
    Date.new(Date::MONDAY, 1, Date::JANUARY, year)
  end

  def with_month(month)
    Date.new(Date::MONDAY, 1, month, 1900)
  end

  def with_leap_month(month)
    Date.new(Date::MONDAY, 1, month, 1904)
  end
*/

#[test]
fn test_month_length() {
    assert_eq!(Date::new(0, 1, 0, 1900).month_length(), 31);
    assert_eq!(Date::new(0, 1, 1, 1900).month_length(), 28);
    assert_eq!(Date::new(0, 1, 2, 1900).month_length(), 31);
    assert_eq!(Date::new(0, 1, 3, 1900).month_length(), 30);
    assert_eq!(Date::new(0, 1, 4, 1900).month_length(), 31);
    assert_eq!(Date::new(0, 1, 5, 1900).month_length(), 30);
    assert_eq!(Date::new(0, 1, 6, 1900).month_length(), 31);
    assert_eq!(Date::new(0, 1, 7, 1900).month_length(), 31);
    assert_eq!(Date::new(0, 1, 8, 1900).month_length(), 30);
    assert_eq!(Date::new(0, 1, 9, 1900).month_length(), 31);
    assert_eq!(Date::new(0, 1, 10, 1900).month_length(), 30);
    assert_eq!(Date::new(0, 1, 11, 1900).month_length(), 31);
}

#[test]
fn test_leap_month_length() {
    assert_eq!(Date::new(0, 1, 0, 1904).month_length(), 31);
    assert_eq!(Date::new(0, 1, 1, 1904).month_length(), 29);
    assert_eq!(Date::new(0, 1, 2, 1904).month_length(), 31);
    assert_eq!(Date::new(0, 1, 3, 1904).month_length(), 30);
    assert_eq!(Date::new(0, 1, 4, 1904).month_length(), 31);
    assert_eq!(Date::new(0, 1, 5, 1904).month_length(), 30);
    assert_eq!(Date::new(0, 1, 6, 1904).month_length(), 31);
    assert_eq!(Date::new(0, 1, 7, 1904).month_length(), 31);
    assert_eq!(Date::new(0, 1, 8, 1904).month_length(), 30);
    assert_eq!(Date::new(0, 1, 9, 1904).month_length(), 31);
    assert_eq!(Date::new(0, 1, 10, 1904).month_length(), 30);
    assert_eq!(Date::new(0, 1, 11, 1904).month_length(), 31);
}

#[test]
fn test_leap_year() {
    assert_eq!(Date::new(0, 1, 6, 1900).is_leap_year(), false);
    assert_eq!(Date::new(0, 1, 6, 2000).is_leap_year(), true);
    assert_eq!(Date::new(0, 1, 6, 1904).is_leap_year(), true);
    assert_eq!(Date::new(0, 1, 6, 1907).is_leap_year(), false);
    assert_eq!(Date::new(0, 1, 6, 1912).is_leap_year(), true);
    assert_eq!(Date::new(0, 1, 6, 1601).is_leap_year(), false);
}

#[test]
fn test_next_month() {
    let mut date = Date::new(4, 1, 0, 2016);
    assert_eq!(date, Date::new(4, 1, 0, 2016));

    date = date.next_month();
    assert_eq!(date, Date::new(0, 1, 1, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(1, 1, 2, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(4, 1, 3, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(6, 1, 4, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(2, 1, 5, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(4, 1, 6, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(0, 1, 7, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(3, 1, 8, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(5, 1, 9, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(1, 1, 10, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(3, 1, 11, 2016));
    date = date.next_month();
    assert_eq!(date, Date::new(6, 1, 0, 2017));
}
