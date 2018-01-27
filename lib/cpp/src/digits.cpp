#include <euler/digits.hpp>
using namespace euler;

digits::digits(uint64_t _num) : num(_num), pos(1) {
  while ((10 * pos) <= num)
    pos *= 10;
  if (num == 0)
    pos = 0;
}

digits &digits::operator++() {
  num -= **this * pos;
  pos /= 10;
  return *this;
}

digits digits::operator++(int) {
  digits old = *this;
  ++(*this);
  return old;
}

bool digits::operator==(digits other) const {
  return pos == other.pos && num == other.num;
}

bool digits::operator!=(digits other) const {
  return pos != other.pos || num != other.num;
}

digits::reference digits::operator*() const { return this->num / this->pos; }

reverse_digits::reverse_digits(uint64_t _cur) : cur(_cur) {}

reverse_digits &reverse_digits::operator++() {
  cur /= 10;
  return *this;
}

reverse_digits reverse_digits::operator++(int) {
  reverse_digits old = *this;
  ++(*this);
  return old;
}

bool reverse_digits::operator==(reverse_digits other) const {
  return cur == other.cur;
}

bool reverse_digits::operator!=(reverse_digits other) const {
  return cur != other.cur;
}

reverse_digits::reference reverse_digits::operator*() const {
  return this->cur % 10;
}

unique_digits::unique_digits(uint64_t _num)
    : reverse_digits(_num), seen(2 << **this) {}

bool unique_digits::saw(uint64_t digit) {
  bool res = (seen & (2 << digit)) && true;
  seen |= 2 << digit;
  return res;
}

unique_digits &unique_digits::operator++() {
  reverse_digits::operator++();
  while (saw(**this)) {
    reverse_digits::operator++();
  }

  return *this;
}

unique_digits unique_digits::operator++(int) {
  unique_digits cur = *this;
  ++(*this);
  return cur;
}
