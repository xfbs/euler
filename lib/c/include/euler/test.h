#include <assert.h>
#include <stdio.h>
#define RUN(t)                                                                 \
  printf("  - %s: ", #t);                                                      \
  t();                                                                         \
  printf("success.\n")
#define TESTS()                                                                \
  const char *_get_file_name() { return __FILE__; }                            \
  void _tests()

void _tests();
const char *_get_file_name();

int main(int argc, char *argv[]) {
  printf("Running %s...\n", _get_file_name());
  _tests();
  return 0;
}
