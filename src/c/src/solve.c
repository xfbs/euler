#include "solve.h"
#include "all.h"

#define default_arg(type, name, val)                                           \
  type name = val

#define typefmt(t) _Generic( (t),                                              \
  int: "%i",                                                                   \
  uint32_t: "%u",                                                              \
  uint64_t: "%llu")

#define solution(val)                                                          \
  sprintf(result, typefmt(val), val);                                          \
  return result

static char result[256];

const char *solve001(map_t *data) {
  default_arg(uint32_t, max, 999);
  default_arg(uint32_t, div1, 3);
  default_arg(uint32_t, div2, 5);
  solution(solve_001(max, div1, div2));
}

const char *solve002(map_t *data) {
  default_arg(uint64_t, max, 4000000);
  solution(solve_002(max));
}

const char *solve003(map_t *data) {
  default_arg(uint64_t, num, 600851475143ULL);
  solution(solve_003(num));
}

const char *solve004(map_t *data) {
  default_arg(uint32_t, digits, 3);
  solution(solve_004(digits));
}

const char *solve005(map_t *data) {
  default_arg(uint32_t, digits, 20);
  solution(solve_005(digits));
}

const char *solve006(map_t *data) {
  default_arg(uint32_t, n, 100);
  solution(solve_006(n));
}

const char *solve007(map_t *data) {
  default_arg(uint32_t, pos, 10001);
  solution(solve_007(pos));
}

const char *solve008(map_t *data) {
  /* FIXME
  if (argc < 2) {
    fsprintf(result, stderr, "no datafile specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");
  vec8_t v = vec8_new(0, 0);

  while (!feof(data_file)) {
    uint8_t c = fgetc(data_file);
    if (c < '0' || c > '9')
      continue;
    vec8_push(&v, c - '0');
  }

  sprintf(result, "%llu", solve_008(&v, 13));


  */
  return "FIXME";
}

const char *solve009(map_t *data) {
  default_arg(uint32_t, n, 1000);
  solution(solve_009(n));
}

const char *solve010(map_t *data) {
  default_arg(uint64_t, n, 2000000);
  solution(solve_010(n));
}

const char *solve011(map_t *data) {
  /* FIXME
  if (argc < 2) {
    fsprintf(result, stderr, "no datafile specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");
  vecp_t grid = vecp_new(0, NULL);
  vec_push(&grid, (void *)vec8_alloc(0, 0));

  while (true) {
    int peek = ' ';
    unsigned int num = 0;

    while (peek == ' ' && 1 == fscanf(data_file, "%u", &num)) {
      vec8_push(vec_get(&grid, vec_len(&grid) - 1), num);
      peek = fgetc(data_file);
    }

    if (feof(data_file))
      break;
    vec_push(&grid, (void *)vec8_alloc(0, 0));
  }

  sprintf(result, "%llu", solve_011(&grid, 4));

  return 0
  */
  return "FIXME";}

const char *solve012(map_t *data) {
  default_arg(size_t, max, 500);
  solution(solve_012(max));
}

const char *solve013(map_t *data) {
  /*
  if (argc < 2) {
    fsprintf(result, stderr, "no data file specified");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");
  vecp_t v = vecp_new(0, NULL);
  char *str;

  while (true) {
    str = malloc(256);

    if (1 == fscanf(data_file, "%255[0-9]%*255[^0-9]", str)) {
      vec_push(&v, str);
    } else {
      break;
    }
  }

  sprintf(result, "%llu", solve_013(&v));
  vec_free(&v);


  */

  return "FIXME";
}

const char *solve014(map_t *data) {
  default_arg(uint32_t, limit, 1000000);
  solution(solve_014(limit));
}

const char *solve015(map_t *data) {
  default_arg(size_t, x, 20);
  default_arg(size_t, y, 20);
  solution(solve_015(x, y));
}

const char *solve016(map_t *data) {
  default_arg(size_t, exp, 1000);
  solution(solve_016(exp));
}

const char *solve017(map_t *data) {
  default_arg(uint32_t, num, 1000);
  solution(solve_017(num));
}

const char *solve018(map_t *data) {
  /*
  if (argc < 2) {
    fsprintf(result, stderr, "no data file specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");

  size_t buffer_len = 256;
  uint32_t *buffer = calloc(buffer_len, sizeof(uint32_t));

  size_t rows = 0;
  size_t elements = 0;

  do {
    size_t prev_elements = elements;
    for (size_t e = 0; e <= rows; e++) {
      // always make sure buffer is big enough
      if (elements == buffer_len) {
        buffer_len *= 2;
        buffer = realloc(buffer, buffer_len * sizeof(uint32_t));
      }

      // read next element, break out of loop if we get junk
      if (1 != fscanf(data_file, "%4d", &buffer[elements])) {
        break;
      }

      elements++;
    }

    // only if we got a complete row do we signal this, otherwise we stop
    // here because there is junk in the data.
    if ((elements - prev_elements) == (rows + 1)) {
      rows++;
    } else {
      break;
    }
  } while (!feof(data_file));

  triangle_t t = {buffer, rows};
  sprintf(result, "%i", solve_018(&t));


  */
  return "FIXME";
}

const char *solve019(map_t *data) {
  // TODO
  date_t start = {MONDAY, 1, JANUARY, 1900};

  // find 1st Jan 1901
  for (size_t i = 0; i < 12; i++) {
    start = next_month(start);
  }

  // i guessed the weekday here, but it shouldn't matter anyways.
  date_t end = {MONDAY, 31, DECEMBER, 2000};

  solution(solve_019(start, end));
}

const char *solve020(map_t *data) {
  default_arg(uint32_t, exp, 100);
  solution(solve_020(exp));
}

const char *solve021(map_t *data) {
  default_arg(uint32_t, max, 10000);
  solution(solve_021(max));
}

const char *solve022(map_t *data) {
  /*
  if (argc < 2) {
    fsprintf(result, stderr, "no datafile specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");
  vecp_t v = vecp_new(0, NULL);
  char *str;

  while (!feof(data_file)) {
    str = malloc(256);

    if (1 == fscanf(data_file, "%*[^A-Z]%255[A-Z]", str)) {
      vec_push(&v, str);
    } else {
      break;
    }
  }

  sprintf(result, "%llu", solve_022(&v));
  vec_free(&v);


  */
  return "FIXME";}

const char *solve023(map_t *data) {
  default_arg(size_t, max, 28123);
  solution(solve_023(max));
}

const char *solve024(map_t *data) {
  default_arg(uint32_t, n, 999999);
  solution(solve_024(n));
}

const char *solve025(map_t *data) {
  default_arg(uint32_t, max, 1000);
  solution(solve_025(max));
}

const char *solve027(map_t *data) {
  default_arg(int32_t, max, 1000);
  solution(solve_027(max));
}

const char *solve028(map_t *data) {
  default_arg(uint64_t, max, 1001);
  solution(solve_028(max));
}

const char *solve029(map_t *data) {
  default_arg(uint32_t, a, 100);
  default_arg(uint32_t, b, 100);
  solution(solve_029(a, b));
}

const char *solve030(map_t *data) {
  solution(solve_030());
}

const char *solve031(map_t *data) {
  default_arg(uint32_t, value, 200);
  solution(solve_031(value));
}

const char *solve032(map_t *data) {
  solution(solve_032());
}

const char *solve033(map_t *data) {
  solution(solve_033());
}

const char *solve034(map_t *data) {
  default_arg(uint64_t, max, 2540160);
  solution(solve_034(max));
}

const char *solve035(map_t *data) {
  default_arg(size_t, max, 1000000);
  solution(solve_035(max));
}

const char *solve036(map_t *data) {
  default_arg(uint32_t, max, 1000000);
  solution(solve_036(max));
}

const char *solve037(map_t *data) {
  default_arg(size_t, max, 11);
  solution(solve_037(max));
}

const char *solve038(map_t *data) {
  solution(solve_038());
}

const char *solve039(map_t *data) {
  default_arg(uint32_t, max, 1000);
  solution(solve_039(max));
}

const char *solve040(map_t *data) {
  solution(solve_040());
}

const char *solve041(map_t *data) {
  default_arg(uint8_t, max, 9);
  solution(solve_041(max));
}

const char *solve042(map_t *data) {
  /*
  if (argc < 2) {
    fsprintf(result, stderr, "no datafile specified\n");
    return -1;
  }

  FILE *data_file = fopen(argv[1], "r");
  vecp_t v = vecp_new(0, NULL);
  char *str;

  while (!feof(data_file)) {
    str = malloc(256);

    if (1 == fscanf(data_file, "%*[^A-Z]%255[A-Z]", str)) {
      vec_push(&v, str);
    } else {
      break;
    }
  }

  sprintf(result, "%llu", solve_042(&v));
  vec_free(&v);


  */
  return "FIXME";}

const char *solve043(map_t *data) {
  solution(solve_043());
}

const char *solve044(map_t *data) {
  solution(solve_044());
}

const char *solve045(map_t *data) {
  default_arg(uint32_t, t, 285);
  default_arg(uint32_t, p, 165);
  default_arg(uint32_t, h, 143);
  solution(solve_045(t, p, h));
}

const char *solve046(map_t *data) {
  solution(solve_046());
}

const char *solve047(map_t *data) {
  default_arg(uint8_t, count, 4);
  solution(solve_047(count));
}

const char *solve048(map_t *data) {
  default_arg(uint64_t, max, 1000);
  default_arg(uint64_t, digits, 10);
  solution(solve_048(max, digits));
}

const char *solve049(map_t *data) {
  default_arg(uint32_t, avoid, 1487);
  solution(solve_049(avoid));
}

const char *solve050(map_t *data) {
  default_arg(uint64_t, max, 1000000);
  solution(solve_050(max));
}

const char *solve052(map_t *data) {
  solution(solve_052());
}

struct solve_s solve[] = {
  [  0] = {NULL, NULL},
  [  1] = {
    solve001,
    "solves the multiples of 3 and 5.\n"
    "  --help   shows this text\n"
    "  --max    sets maximum number\n"
    "  --div1   first divisor\n"
    "  --div2   second divisor"},
  [  2] = {
    solve002,
    "TODO"},
  [  3] = {
    solve003,
    "TODO"},
  [  4] = {
    solve004,
    "TODO"},
  [  5] = {
    solve005,
    "TODO"},
  [  6] = {
    solve006,
    "TODO"},
  [  7] = {
    solve007,
    "TODO"},
  [  8] = {
    solve008,
    "TODO"},
  [  9] = {
    solve009,
    "TODO"},
  [ 10] = {
    solve010,
    "TODO"},
  [ 11] = {
    solve011,
    "TODO"},
  [ 12] = {
    solve012,
    "TODO"},
  [ 13] = {
    solve013,
    "TODO"},
  [ 14] = {
    solve014,
    "TODO"},
  [ 15] = {
    solve015,
    "TODO"},
  [ 16] = {
    solve016,
    "TODO"},
  [ 17] = {
    solve017,
    "TODO"},
  [ 18] = {
    solve018,
    "TODO"},
  [ 19] = {
    solve019,
    "TODO"},
  [ 20] = {
    solve020,
    "TODO"},
  [ 21] = {
    solve021,
    "TODO"},
  [ 22] = {
    solve022,
    "TODO"},
  [ 23] = {
    solve023,
    "TODO"},
  [ 24] = {
    solve024,
    "TODO"},
  [ 25] = {
    solve025,
    "TODO"},
  [ 26] = {
    NULL,
    NULL},
  [ 27] = {
    solve027,
    "TODO"},
  [ 28] = {
    solve028,
    "TODO"},
  [ 29] = {
    solve029,
    "TODO"},
  [ 30] = {
    solve030,
    "TODO"},
  [ 31] = {
    solve031,
    "TODO"},
  [ 32] = {
    solve032,
    "TODO"},
  [ 33] = {
    solve033,
    "TODO"},
  [ 34] = {
    solve034,
    "TODO"},
  [ 35] = {
    solve035,
    "TODO"},
  [ 36] = {
    solve036,
    "TODO"},
  [ 37] = {
    solve037,
    "TODO"},
  [ 38] = {
    solve038,
    "TODO"},
  [ 39] = {
    solve039,
    "TODO"},
  [ 40] = {
    solve040,
    "TODO"},
  [ 41] = {
    solve041,
    "TODO"},
  [ 42] = {
    solve042,
    "TODO"},
  [ 43] = {
    solve043,
    "TODO"},
  [ 44] = {
    solve044,
    "TODO"},
  [ 45] = {
    solve045,
    "TODO"},
  [ 46] = {
    solve046,
    "TODO"},
  [ 47] = {
    solve047,
    "TODO"},
  [ 48] = {
    solve048,
    "TODO"},
  [ 49] = {
    solve049,
    "TODO"},
  [ 50] = {
    solve050,
    "TODO"},
  [ 51] = {
    NULL,
    NULL},
  [ 52] = {
    solve052,
    "TODO"},
  [ 53] = {
    NULL,
    NULL},
};

size_t solve_max = sizeof(solve);
