#include "solve.h"
#include "all.h"

const char *solve001(map_t *data) {
  uint32_t max = 999;
  uint32_t div1 = 3;
  uint32_t div2 = 5;

  static char result[256];
  sprintf(result, "%i", solve_001(max, div1, div2));
  return result;
}

const char *solve002(map_t *data) {
  printf("%llu\n", solve_002(4000000));
}

const char *solve003(map_t *data) {
  printf("%llu\n", solve_003(600851475143ULL));
}

const char *solve004(map_t *data) {
  printf("%i\n", solve_004(3));
}

const char *solve005(map_t *data) {
  printf("%i\n", solve_005(20));
}

const char *solve006(map_t *data) {
  printf("%i\n", solve_006(100));
}

const char *solve007(map_t *data) {
  printf("%llu\n", solve_007(10001));
}

const char *solve008(map_t *data) {
  /* FIXME
  if (argc < 2) {
    fprintf(stderr, "no datafile specified\n");
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

  printf("%llu\n", solve_008(&v, 13));


  */}

const char *solve009(map_t *data) {
  printf("%u\n", solve_009(1000));
}

const char *solve010(map_t *data) {
  printf("%llu\n", solve_010(2000000));
}

const char *solve011(map_t *data) {
  /* FIXME
  if (argc < 2) {
    fprintf(stderr, "no datafile specified\n");
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

  printf("%llu\n", solve_011(&grid, 4));

  return 0
  */
  return "FIXME";}

const char *solve012(map_t *data) {
  printf("%i\n", solve_012(500));
}

const char *solve013(map_t *data) {
  /*
  if (argc < 2) {
    fprintf(stderr, "no data file specified");
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

  printf("%llu\n", solve_013(&v));
  vec_free(&v);


  */

  return "FIXME";}

const char *solve014(map_t *data) {
  printf("%i\n", solve_014(1000000));
}

const char *solve015(map_t *data) {
  printf("%llu\n", solve_015(20, 20));
}

const char *solve016(map_t *data) {
  printf("%llu\n", solve_016(1000));
}

const char *solve017(map_t *data) {
  printf("%u\n", solve_017(1000));
}

const char *solve018(map_t *data) {
  /*
  if (argc < 2) {
    fprintf(stderr, "no data file specified\n");
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
  printf("%i\n", solve_018(&t));


  */
  return "FIXME";}

const char *solve019(map_t *data) {
  date_t start = {MONDAY, 1, JANUARY, 1900};

  // find 1st Jan 1901
  for (size_t i = 0; i < 12; i++) {
    start = next_month(start);
  }

  // i guessed the weekday here, but it shouldn't matter anyways.
  date_t end = {MONDAY, 31, DECEMBER, 2000};

  printf("%i\n", solve_019(start, end));
}

const char *solve020(map_t *data) {
  printf("%llu\n", solve_020(100));
}

const char *solve021(map_t *data) {
  printf("%i\n", solve_021(10000));
}

const char *solve022(map_t *data) {
  /*
  if (argc < 2) {
    fprintf(stderr, "no datafile specified\n");
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

  printf("%llu\n", solve_022(&v));
  vec_free(&v);


  */
  return "FIXME";}

const char *solve023(map_t *data) {
  printf("%i\n", solve_023(28123));
}

const char *solve024(map_t *data) {
  printf("%llu\n", solve_024(999999));
}

const char *solve025(map_t *data) {
  printf("%u\n", solve_025(1000));
}

const char *solve027(map_t *data) {
  printf("%i\n", solve_027(1000));
}

const char *solve028(map_t *data) {
  printf("%llu\n", solve_028(1001));
}

const char *solve029(map_t *data) {
  printf("%u\n", solve_029(100, 100));
}

const char *solve030(map_t *data) {
  printf("%i\n", solve_030());
}

const char *solve031(map_t *data) {
  printf("%i\n", solve_031(200));
}

const char *solve032(map_t *data) {
  printf("%i\n", solve_032(10));
}

const char *solve033(map_t *data) {
  printf("%i\n", solve_033(10));
}

const char *solve034(map_t *data) {
  printf("%llu\n", solve_034(2540160));
}

const char *solve035(map_t *data) {
  printf("%i\n", solve_035(1000000));
}

const char *solve036(map_t *data) {
  printf("%i\n", solve_036(1000000));
}

const char *solve037(map_t *data) {
  printf("%i\n", solve_037(11));
}

const char *solve038(map_t *data) {
  printf("%llu\n", solve_038(11));
}

const char *solve039(map_t *data) {
  printf("%u\n", solve_039(1000));
}

const char *solve040(map_t *data) {
  printf("%i\n", solve_040());
}

const char *solve041(map_t *data) {
  printf("%i\n", solve_041(9));
}

const char *solve042(map_t *data) {
  /*
  if (argc < 2) {
    fprintf(stderr, "no datafile specified\n");
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

  printf("%llu\n", solve_042(&v));
  vec_free(&v);


  */
  return "FIXME";}

const char *solve043(map_t *data) {
  printf("%llu\n", solve_043());
}

const char *solve044(map_t *data) {
  printf("%llu\n", solve_044());
}

const char *solve045(map_t *data) {
  printf("%llu\n", solve_045(285, 165, 143));
}

const char *solve046(map_t *data) {
  printf("%llu\n", solve_046());
}

const char *solve047(map_t *data) {
  printf("%llu\n", solve_047(4));
}

const char *solve048(map_t *data) {
  printf("%llu\n", solve_048(1000, 10));
}

const char *solve049(map_t *data) {
  printf("%llu\n", solve_049(1487));
}

const char *solve050(map_t *data) {
  printf("%llu\n", solve_050(1000000));
}

const char *solve052(map_t *data) {
  printf("%llu\n", solve_052());
}

struct solve_s solve[] = {
  [  0] = {0, 0},
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
