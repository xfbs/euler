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
    in this library. This is useful when adding code to be sure that it's
    well-formatted, especially when using an editor that isn't set up quite
    right.

  - `make doc` generate these docs, the output will be placed in
    `/doc/lib/c` in the repository.

There are some variables that can be used to customize the build:

  - `CC` chooses a different C compiler. For example, running
    `make CC="clang-5.0"` will use `clang-5.0` as compiler instead of `cc`, the
    system standard.

  - `OPTIMIZE` gets passed to both the compiler (`CFLAGS`) and the linker
    (`LDFLAGS`). This can be used to set custom optimization options, for
    example. `make OPTIMIZE="-O3"` compiles the code with full optimizations
    enabled. It can also be used with special compiler features: running
    `make OPTIMIZE="-O0 -g -fsanitize=address"` will enable `clang`'s
    AddressSanitizer.

### Testing

Note that the testing process is a big of a fragile mess. The way it works is
that there is a very tiny C unit testing helper in `include/euler/test.h`. This
is used to write the tests in the `test/` folder. 

Additionally, there is a script, `test/doc_test.rb`, which is used by the
Makefile to automatically extract tests from the documentation and place them
into `test/doc_test.c`. Any time it encounters a commented block like

    //! ```c
    //! int a = 5;
    //! assert(a == 5);
    //! ```

It tries its best to figure out which function this code snippet is for (using
some very simple regexes) and then it constructs a testing method for that,
naming the method something like `doctest_filename_methodname`.

Then there is a third script, `test/all.rb`, which generates the necessary
`main` method for all the tests in `test/all.c`, by parsing all `*_test.c`
files in `test/`, and parsing it for lines like `void your_test()`. This script
is run automatically by the `Makefile`, too. 

#### Test Coverage

Using `clang`, basic coverage information can be (semi-easily) generated from
the C sources and the tests with the following sequence of commands:

First, any previously compiled object files and binaries need to be cleared out
with

    make clean

Then, the code needs to be recompiled with instrumentation and run. For this,
the `OPTIMIZE` flag of the `Makefile` provides a convenient way to pass options
both to the compiler and the linker.

    make test OPTIMIZE="-O0 -fprofile-instr-generate -fcoverage-mapping"

Now there will be a `default.profraw` file in the current directory. This file
needs to be processed further with `llvm-proftool` to make it readable. If there
were multiple binaries to run different tests, then this tool would enable
merging both run data into one coverage report.

    llvm-proftool merge default.profraw -output output.cov

And finally the coverage report can be viewed with `llvm-cov report`. 

    llvm-cov report -instr-profile output.cov ./test/all

There is additionally `llvm-cov show`, which can be used to view a line-by-line
overview over what is touched turing testing and what isn't.

### Compatibility

All code in this library has been developed and tested with `clang 5.0.1`,
and should follow the `c11` standard. Some features of `c11` may not work with
older compilers — if you get warnings about `_Generic` not being found, you
probably have an outdated or incompatible compiler.

### Acknowledgements

The hashing function used for the Hashmap implementation is the ever-popular
[Murmur64](https://github.com/aappleby/smhasher).
