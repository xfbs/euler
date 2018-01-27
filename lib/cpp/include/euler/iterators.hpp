#include <algorithm>
#include <iostream>
#include <vector>

namespace euler {
template <class InputIt>
using value_type = typename std::iterator_traits<InputIt>::value_type;

template <class InputIt>
using iterator_category =
typename std::iterator_traits<InputIt>::iterator_category;

template <class InputIt>
using difference_type = typename std::iterator_traits<InputIt>::difference_type;

template <class InputIt>
using pointer = typename std::iterator_traits<InputIt>::pointer;

template <class InputIt>
using reference = typename std::iterator_traits<InputIt>::reference;

template <class IterType, class Fun>
class map_iter
    : public std::iterator<iterator_category<IterType>, value_type<IterType>,
                           difference_type<IterType>, pointer<IterType>,
                           reference<IterType>> {
  IterType iter;
  Fun fun;

public:
  map_iter(IterType _iter, Fun f) : iter(_iter), fun(f) {}
  map_iter &operator++() {
    ++iter;
    return *this;
  }
  map_iter operator++(int) {
    map_iter prev = *this;
    ++iter;
    return prev;
  }
  bool operator==(map_iter other) const { return iter == other.iter; }
  bool operator!=(map_iter other) const { return iter != other.iter; }
  bool operator==(IterType other) const { return iter == other; }
  bool operator!=(IterType other) const { return iter != other; }
  reference<IterType> operator*() const {
    return fun(*iter);
  }
};

template<class IterType, class Fun>
map_iter(IterType it, Fun f) -> map_iter<IterType, Fun>;

}
