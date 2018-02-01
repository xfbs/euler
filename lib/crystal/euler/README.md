# Euler Library

The library is part of [xfbs/euler](https://xfbs.github.io/euler), which aims to
solve [Project Euler](https://projecteuler.net/) problems in a variety of
languages.

The functions and classes of this library are to share code between different
solutions. There are also tests provided, if you clone the
[repository](https://github.com/xfbs/euler), and navigate to this library (which
is in `/lib/crystal/euler`), there is a `Makefile` that supports the following
targets:

  - `make test`

>   Builds and runs all the tests of this library.

  - `make fmt`

>   Runs the crystal code formatter over all of the code in this library.

  - `make doc`

>   Generates these docs, the output will be placed in `doc/lib/crystal` in the
>   repository.

All code in this library has been developed and tested with Crystal `0.24.1`.
Since crystal is still under development, things may break with future releases
of Crystal.
