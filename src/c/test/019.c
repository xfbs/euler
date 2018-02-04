
#include "solve.h"
#include <euler/test.h>

void test_leap_year() {
  assert(is_leap_year((date_t){FRIDAY, 15, JULY, 2016}) == true);
  assert(is_leap_year((date_t){FRIDAY, 15, JULY, 2000}) == true);
  assert(is_leap_year((date_t){FRIDAY, 15, JULY, 1900}) == false);
  assert(is_leap_year((date_t){FRIDAY, 15, JULY, 2004}) == true);
}

void test_month_length() {
  assert(month_length((date_t){FRIDAY, 15, JANUARY, 2016}) == 31);
  assert(month_length((date_t){MONDAY, 15, FEBRUARY, 2016}) == 29);
  assert(month_length((date_t){TUESDAY, 15, MARCH, 2016}) == 31);
  assert(month_length((date_t){FRIDAY, 15, APRIL, 2016}) == 30);
  assert(month_length((date_t){SUNDAY, 15, MAY, 2016}) == 31);
  assert(month_length((date_t){WEDNESDAY, 15, JUNE, 2016}) == 30);
  assert(month_length((date_t){FRIDAY, 15, JULY, 2016}) == 31);
  assert(month_length((date_t){MONDAY, 15, AUGUST, 2016}) == 31);
  assert(month_length((date_t){THURSDAY, 15, SEPTEMBER, 2016}) == 30);
  assert(month_length((date_t){SATURDAY, 15, OCTOBER, 2016}) == 31);
  assert(month_length((date_t){TUESDAY, 15, NOVEMBER, 2016}) == 30);
  assert(month_length((date_t){THURSDAY, 15, DECEMBER, 2016}) == 31);
}

bool eq(date_t d, weekday_t w, int j, month_t m, int y) {
  return (d.weekday == w) && (d.day == j) && (d.month == m) && (d.year == y);
}

void test_next_month() {
  date_t date = {FRIDAY, 1, JANUARY, 2016};
  assert(eq(date, FRIDAY, 1, JANUARY, 2016));

  date = next_month(date);
  assert(eq(date, MONDAY, 1, FEBRUARY, 2016));

  date = next_month(date);
  assert(eq(date, TUESDAY, 1, MARCH, 2016));

  date = next_month(date);
  assert(eq(date, FRIDAY, 1, APRIL, 2016));

  date = next_month(date);
  assert(eq(date, SUNDAY, 1, MAY, 2016));

  date = next_month(date);
  assert(eq(date, WEDNESDAY, 1, JUNE, 2016));

  date = next_month(date);
  assert(eq(date, FRIDAY, 1, JULY, 2016));

  date = next_month(date);
  assert(eq(date, MONDAY, 1, AUGUST, 2016));

  date = next_month(date);
  assert(eq(date, THURSDAY, 1, SEPTEMBER, 2016));

  date = next_month(date);
  assert(eq(date, SATURDAY, 1, OCTOBER, 2016));

  date = next_month(date);
  assert(eq(date, TUESDAY, 1, NOVEMBER, 2016));

  date = next_month(date);
  assert(eq(date, THURSDAY, 1, DECEMBER, 2016));

  date = next_month(date);
  assert(eq(date, SUNDAY, 1, JANUARY, 2017));
}

void test_solve_019() {
  date_t start = {FRIDAY, 1, JANUARY, 2016};
  date_t end = {THURSDAY, 1, DECEMBER, 2016};
  assert(solve_019(start, end) == 1);
}

