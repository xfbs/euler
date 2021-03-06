#include <array>
#include <iostream>
#include <range/v3/all.hpp>
#include <vector>

using std::cout;
using std::endl;
using namespace ranges;

auto is_six = [](int i) -> bool { return i == 6; };
auto doub = [](int i) -> int { return 2 * i; };

int main() {
  std::vector<int> v{6, 2, 3, 4, 5, 6};
  auto c = count_if(v, is_six);
  cout << "count-sixes: " << c << endl;

  auto s = accumulate(v, 0);
  cout << "sum-vetor: " << s << endl;

  auto cand = view::ints(1) | view::transform(doub);
  auto e = find_if(cand, is_six);
  cout << "find-six: " << *e << endl;

  auto odd_perfect_square =
      front(view::ints
            // make perfect squares
            | view::transform([](int a) { return a * a; })
            // keep odd ones only
            | view::filter([](int a) { return a % 2 == 1; })
            // ignore first two
            | view::drop_exactly(2));

  cout << odd_perfect_square << endl;
}
