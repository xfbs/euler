# libeuler

The library is part of [xfbs/euler](https://xfbs.github.io/euler), which aims to
solve [Project Euler](https://projecteuler.net/) problems in a variety of
languages.

The functions and classes of this library are to share code between different
solutions. There are also tests for this library. 

### Building

If you clone the
[repository](https://github.com/xfbs/euler), and navigate to this library (which
is in `/lib/c/`), you will find a `Makefile` that supports the following
targets:

  - `make build` to build the library and place the resulting file in
    `/lib/c/lib`

  - `make test` to build and run all the tests of this library.

  - `make fmt` to run the `clang-format` code formatter  over all of the code
     in this library.

  - `make doc` generate these docs, the output will be placed in
    `/doc/lib/c` in the repository.

There are some variables that can be used to customize the build:

  - `CC` chooses a different C compiler. Use like so:

```
# build with clang++-5.0.1
make CC="clang++-5.0.1"
```

  - `OPTIMIZE` gets passed to both the compiler (`CFLAGS`) and the linker
    (`LDFLAGS`). You can use this to set custom optimization options or other
    flags:

```
# compile with full optimization
make OPTIMIZE="-O3"
```

```
# make a debug build and enable clang address sanitizer
make OPTIMIZE="-O0 -g -fsanitize=address"
```

### Compatibility

All code in this library has been developed and tested with `clang 5.0.1`,
and should follow the `c11` standard. Some features of `c11` may not work with
older compilers — if you get warnings about `_Generic` not being found, you
probably have an outdated or incompatible compiler.
