# Project Euler Solutions [![Build Status](https://travis-ci.org/xfbs/euler.svg?branch=master)](https://travis-ci.org/xfbs/euler) [![GitHub release](https://img.shields.io/github/tag/xfbs/euler.svg)]()

This is a repository of solutions to [Project Euler](https://projecteuler.net/)
problems. All of these solutions are written by me in an attempt to fool around
with mathematics and sharpen my programming skills in a few languages.

## Rules

  - A solution is only accepted when it:
      - yields the **correct answer**.
      - takes **less than 1s** (1000ms) to compute the answer. There are some
        solutions in here that take longer, because I couldn't (yet) get them
        there.
      - is **completely written by myself**, without having looked at someone
        else's solution (unless by accident). Don't wanna spoil the fun.
      - has a **full and working testing suite**. I like my code tested.
      - **is well-documented**, meaning that when reading it, it's obvious to
        see what is going on because the variables are named smartly and there
        comments to explain what is going on when necessary.
      - is **elegant**, meaning no more complex than it should be
  - Every language needs to be treated with respect by trying to **use its
    idioms** as much as possible and by **avoiding hackery**. That's kind of the
    point of this project — getting familiar with some dope new languages and
    their cool tricks
  - Code can be shared between solutions if it helps **keeping things 
    [Dry](http://wiki.c2.com/?DontRepeatYourself)**.
  - When possible, the **standard library of the language should suffice**. I
    don't like depending on external libraries, especially when it can be useful
    to implement some things by myself. However, in some cases it's okay (for 
    example, unit testing frameworks). When possible, I'll try to bundle
    external libraries into this repository.
  - The **simpler** the solution is, in terms of lines of code and complexity,
    the better.

## Languages

  - [crystal](https://crystal-lang.org/), because it's pretty damn fast (thanks
    to LLVM, static typing and a lot of optimization, from what I can tell) — 
    but yet also a pleasure to write because it has a ruby-esque syntax.
  - [c](https://en.wikipedia.org/wiki/C_(programming_language)), the grandfather
    of programming languages: because once you get into it, you can't escape it.
    I personally think it's a bit of a horrible and ancient language, but yet
    it's not so bad to write.
  - [ruby](https://www.ruby-lang.org), because it has a sweet, sweet syntax and
    it will always be my slow, but heartwarming favourite.
  - [rust](https://rust-lang.org), because all the cool kids at Mozilla are
    doing it, and I like picking up fights with the compiler.
  - [python](https://python.org), because it's *Everybody's Favourite Language*
    and I haven't spent much time with it recently.

## Progress

Here is a table of the current status of the project. The numbers represent how
many miliseconds the implementation takes to compute the correct answer (blank
means not implemented). 

<details>
  <summary>Click to view</summary>

| problem | crystal | ruby |   c | rust | python | *avg* |
| ------: | ------- | ---- | --- | ---- | ------ | ----- |
| [`001`](https://projecteuler.net/problem=001) | 18ms | 72ms | 12ms | 16ms | 52ms | 34ms |
| [`002`](https://projecteuler.net/problem=002) | 22ms | 88ms | 12ms | 18ms | 70ms | 42ms |
| [`003`](https://projecteuler.net/problem=003) | 22ms | 88ms | 14ms | 20ms | 64ms | 41ms |
| [`004`](https://projecteuler.net/problem=004) | 78ms | 114ms | 14ms | 22ms | 62ms | 58ms |
| [`005`](https://projecteuler.net/problem=005) | 20ms | 64ms | 12ms | 12ms | 48ms | 31ms |
| [`006`](https://projecteuler.net/problem=006) | 18ms | 78ms | 14ms | 14ms | 54ms | 35ms |
| [`007`](https://projecteuler.net/problem=007) | 30ms | 146ms | 22ms | 22ms | 210ms | 86ms |
| [`008`](https://projecteuler.net/problem=008) | 18ms | 68ms | 12ms | 14ms | 50ms | 32ms |
| [`009`](https://projecteuler.net/problem=009) | 16ms | 70ms | 10ms | 16ms | 88ms | 40ms |
| [`010`](https://projecteuler.net/problem=010) | 134ms | 350ms | 424ms | 28ms | 510ms | 289ms |
| [`011`](https://projecteuler.net/problem=011) | 20ms | 68ms | 12ms | 12ms | 52ms | 32ms |
| [`012`](https://projecteuler.net/problem=012) | 76ms | 680ms | 42ms | 42ms | 1144ms | 396ms |
| [`013`](https://projecteuler.net/problem=013) | 16ms | 62ms | 14ms | 14ms | 46ms | 30ms |
| [`014`](https://projecteuler.net/problem=014) | 536ms | 1378ms | 34ms | 32ms | 2070ms | 810ms |
| [`015`](https://projecteuler.net/problem=015) | 16ms | 68ms | 12ms | 18ms | 54ms | 33ms |
| [`016`](https://projecteuler.net/problem=016) | 14ms | 70ms | 12ms | 18ms | 48ms | 32ms |
| [`017`](https://projecteuler.net/problem=017) | 48ms | 104ms | 12ms | 16ms | 52ms | 46ms |
| [`018`](https://projecteuler.net/problem=018) | 16ms | 72ms | 12ms | 12ms | 54ms | 33ms |
| [`019`](https://projecteuler.net/problem=019) | 16ms | 66ms | 12ms | 16ms |      | 27ms |
| [`020`](https://projecteuler.net/problem=020) | 16ms | 66ms | 14ms | 14ms | 50ms | 32ms |
| [`021`](https://projecteuler.net/problem=021) | 40ms | 450ms | 18ms | 26ms | 174ms | 141ms |
| [`022`](https://projecteuler.net/problem=022) | 42ms | 88ms | 18ms | 16ms | 74ms | 47ms |
| [`023`](https://projecteuler.net/problem=023) | 486ms | 2326ms | 36ms | 62ms |      | 727ms |
| [`024`](https://projecteuler.net/problem=024) | 18ms | 70ms | 12ms | 16ms |      | 29ms |
| [`025`](https://projecteuler.net/problem=025) | 18ms | 70ms | 10ms | 18ms | 50ms | 33ms |
| [`026`](https://projecteuler.net/problem=026) | 44ms | 142ms |      |      |      | 93ms |
| [`027`](https://projecteuler.net/problem=027) | 200ms | 920ms | 40ms | 50ms |      | 302ms |
| [`028`](https://projecteuler.net/problem=028) | 14ms | 66ms | 14ms | 12ms | 50ms | 31ms |
| [`029`](https://projecteuler.net/problem=029) | 134ms | 82ms |  8ms | 18ms | 60ms | 60ms |
| [`030`](https://projecteuler.net/problem=030) | 30ms | 98ms | 14ms | 18ms | 80ms | 48ms |
| [`031`](https://projecteuler.net/problem=031) | 38ms | 102ms | 14ms | 16ms | 116ms | 57ms |
| [`032`](https://projecteuler.net/problem=032) | 290ms | 1090ms | 30ms | 50ms |      | 365ms |
| [`033`](https://projecteuler.net/problem=033) | 22ms | 74ms | 14ms |      |      | 36ms |
| [`034`](https://projecteuler.net/problem=034) | 60ms | 154ms | 42ms | 54ms |      | 77ms |
| [`035`](https://projecteuler.net/problem=035) | 602ms | 3408ms | 178ms | 178ms |      | 1091ms |
| [`036`](https://projecteuler.net/problem=036) | 20ms | 80ms | 30ms |      |      | 43ms |
| [`037`](https://projecteuler.net/problem=037) | 162ms |      | 126ms |      |      | 144ms |
| [`038`](https://projecteuler.net/problem=038) | 76ms | 164ms | 12ms | 16ms |      | 67ms |
| [`039`](https://projecteuler.net/problem=039) | 18ms | 98ms | 10ms | 14ms |      | 35ms |
| [`040`](https://projecteuler.net/problem=040) | 18ms | 66ms | 14ms | 20ms | 50ms | 33ms |
| [`041`](https://projecteuler.net/problem=041) | 476ms |      | 118ms |      |      | 297ms |
| [`042`](https://projecteuler.net/problem=042) | 20ms | 74ms |      |      |      | 47ms |
| [`043`](https://projecteuler.net/problem=043) | 20ms | 66ms | 12ms |      |      | 32ms |
| [`044`](https://projecteuler.net/problem=044) | 90ms | 574ms | 32ms |      |      | 232ms |
| [`045`](https://projecteuler.net/problem=045) | 20ms | 78ms | 12ms | 18ms | 106ms | 46ms |
| [`046`](https://projecteuler.net/problem=046) | 34ms | 236ms | 12ms |      |      | 94ms |
| [`047`](https://projecteuler.net/problem=047) | 72ms | 404ms | 44ms |      |      | 173ms |
| [`048`](https://projecteuler.net/problem=048) | 64ms | 70ms | 16ms | 36ms | 52ms | 47ms |
| [`049`](https://projecteuler.net/problem=049) | 224ms | 960ms | 146ms |      |      | 443ms |
| [`050`](https://projecteuler.net/problem=050) | 18ms | 74ms | 10ms | 152ms |      | 63ms |
| [`052`](https://projecteuler.net/problem=052) | 120ms | 270ms | 24ms |      |      | 138ms |
| *min* | 14ms | 62ms | 8ms | 12ms | 46ms | 8ms |
| *max* | 602ms | 3408ms | 424ms | 178ms | 2070ms | 3408ms |
| *average* | 90ms | 329ms | 36ms | 29ms | 192ms | 135ms |
| *mean* | 30ms | 88ms | 14ms | 18ms | 54ms | ms |
| *count* | 51 | 49 | 49 | 39 | 29 | 217 |

</details>

## Structure

The structure of the project is as follows:
  - [`Makefile`](Makefile), to build, clean, test and verify all solutions.
  - [`euler.rb`](euler.rb), a helper script to check solutions
  - [`src/`](src/), a folder with all the solutions, named as such:
      - [`001-multiples-of-3-and-5/`](src/001-multiples-of-3-and-5), an example 
        of a problem folder
          - [`problem.md`](src/001-multiples-of-3-and-5/problem.md), the
            explanation of the problem
          - [`ruby/`](src/001-multiples-of-3-and-5/ruby/), a ruby implementation
            of the solution
              - [`Makefile`](src/001-multiples-of-3-and-5/ruby/Makefile), the
                Makefile to build, test, run and clean the ruby solution
              - `...` ruby code and files
          - [`rust/`](src/001-multiples-of-3-and-5/rust), a rust implementation of the solution
              - [`Makefile`](src/001-multiples-of-3-and-5/rust/Makefile), the
                Makefile to build, test, run and clean the rust solution
              - `...` rust code and files
          - [`.solution.bcrypt`](src/001-multiples-of-3-and-5/.solution.bcrypt),
            a [bcrypt](https://en.wikipedia.org/wiki/Bcrypt)ed hash of the
            solution
      - `...` other problems
  - [`lib/`](lib/) — libraries and data shared between solutions
  - [`doc/`](doc/) — folder where, at some point, documentation for my solutions
    can be found or generated.

Every solution needs to contain a
[`Makefile`](src/001-multiples-of-3-and-5/ruby/Makefile) that responds to four
commands:
  - `make build` — to build the solution
  - `make solve` — to solve the problem, which should return the solution on
    `stdout` (and no other text)
  - `make test` — to build and run the unit test suite, returning nonzero on
    failure
  - `make clean` — to clean intermediate files, build targets and caches

Some solutions may have a `DISABLED` file inside their folder. This tells my
euler.rb script to ignore them, which usually means that the solution doesn't
work or is too slow, but I have committed it anyways because I feel that I get
get it to work or optimize it.

## Setup

To actually test out these solutions, you need to install a few things: 

  - ruby `2.3`
  - python `3.6`
  - crystal `0.24.1`
  - clang or gcc implementing `c99`
  - rust `1.19.0`

### On macOS

```bash
$ brew install ruby python3 crystal-lang rust
```

## Run Solutions

The [`Makefile`](Makefile) in the project root, in conjunction with the 
[`euler.rb`](euler.rb) script, offer some ways of running the solutions and
showing some statistics. To build, test, verify and time all solutions (this
could take a while), run:

```bash
make check
```

If you want to see how many problems are solved in a more concise manner, run:

```bash
make overview
```

Read the source code of the Makefile for more details.

### ToDo

  - [ ] problem 049, change algorithm to be more efficient
  - [X] export `010/rust` sieve code
  - [X] free `010/rust` from `bit-vec`
  - [ ] remove `euler/bitvec.h` dependencies in C solutions if not necessary
  - [X] properly test `lib/rust/euler/prime.rs`
  - [ ] comment and clean up all solutions
  - [ ] implement tests for all problems
  - [ ] improve execution speed on some ruby/python solutions
  - [ ] change from `python3` to `pypy3` for a little speed boost
      - probably not a good idea, stock python3 should do us okay
  - [X] rename `simple_prime.h` to just `prime.h`
  - [ ] add `sieve.h` from problem `010/c`
  - [ ] problems 30 and 34 are quite similar, export library code?
  - [ ] don't symlink for shared code, make libraries own their code
  - [ ] consider porting to `premake` to allow for IDE compatibility?
  - [ ] solve all problems up to problem 100
  - [ ] add solutions in another language (scheme, ocaml, cpp)

## Other Repositories

There are some other people putting their solutions to project euler problems
online, kudos to them because they have solved far more problems than I have:

  - [mathblog.dk](http://www.mathblog.dk/project-euler-solutions/), solutions
    are in C#
  - [project nayuki](https://www.nayuki.io/page/project-euler-solutions),
    solutions are in Java, Python, Mathematica and Haskell
  - [haskell wiki](https://wiki.haskell.org/Euler_problems), solutions are in
    Haskell

These are useful to compare against after having solved a problem, to check if
there is a more elegant or efficient method.

## Acknowledgments

Apart from the great standard libraries of the languages that are used in this
project, there are also a few support libraries used, which for now I have
bundled into the repository:

  - [ysbaddaden/minitest.cr](https://github.com/ysbaddaden/minitest.cr) in
    [`lib/crystal/minitest`](lib/crystal/minitest/), a unit test and assertions
    library for Crystal
  - [ovenpasta/thunderchez](https://github.com/ovenpasta/thunderchez) in
    [`lib/chez/thunderchez/`](lib/chez/thunderchez/), a collection of libraries
    for chez productivity

## Planned Languages:

  - [chez scheme](https://github.com/cisco/ChezScheme), because I never really
    worked with a scheme before and it's reportedly very fast. **Edit**: I might
    use a different flavour of Scheme, [chicken scheme](http://call-cc.org),
    because it seems a little more simplistic and doesn't have the overhead of
    an interpreter since it's compiled (although, it might be slower than
    `chez`).
  - [idris](https://www.idris-lang.org), because it might be an interesting way
    to get into haskell, and it has support for some cool features like
    automagic proofs and a totality checker.
  - [ocaml](https://github.com/ocaml/ocaml) because I keep hearing about it in
    unexpected places and it got me curious.
  - [nodejs](https://github.com/nodejs/node) because all the cool kids are doing
    it and my javascript is quite rusty.
  - [java9](https://www.oracle.com/java/java9.html) because that's what most
    people worldwide speak and while I'm really not a fan of java, they did add
    some features that make it interesting.
  - [haskell](https://www.haskell.org), because it's just been on my to do list
    for too long.
  - [risc5asm](https://rv8.io), because well you need to have done some assembly
    to be able to call yourself a 'real' programmer, and x86 assembler is too
    ordinaire for me and MIPS stopped being interesting 20 years ago.
  - [cpp](http://clang.org), because I haven't really gotten around to playing
    with C++14 and it could be okay.
  - [swift](https://github.com/apple/swift), because it's seems cool even though
    it's from a major company and not some academic tech hippies. it might even
    be useful..
  - [nim](https://nim-lang.org), because compiling to C, it has the potential to
    be rather quick but with a larger standard library, and with a python-esque
    syntax, also quite usable.
  - [luajit](https://luajit.org/luajit.html), because I'm already familiar with
    lua and it claims to be the 'fastest dynamic language'.

Verdict: there are far too many dope programming languages out there. I will try
my luck with these few, but whichever I choose, there will be ten others just as
great.

## License

See [license.md](license.md) for more information. 
