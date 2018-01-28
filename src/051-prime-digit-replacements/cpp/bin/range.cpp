// This example counts element of a range that match a supplied predicate.
// output
// vector:   2
// array:    2
#include <range/v3/algorithm/count_if.hpp>   //specific includes
#include <vector>
#include <array>
#include <iostream>
using std::cout;
auto is_six = [](int i) -> bool { return i == 6; };
int main() {
  std::vector<int> v {6, 2, 3, 4, 5, 6};
  auto c = ranges::count_if( v, is_six );
  cout << "vector:   " << c << "\n"; //2
  std::array<int, 6> a {6, 2, 3, 4, 5, 6};
  c = ranges::count_if( a, is_six );
  cout << "array:    " << c << "\n"; //2
}
