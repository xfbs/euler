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

| problem | crystal |   c | ruby | rust | python | *avg* |
| ------- | ------- | --- | ---- | ---- | ------ | ----- |
| [`001`](https://projecteuler.net/problem=001) | 20ms | 10ms | 68ms | 12ms | 54ms | 32ms |
| [`002`](https://projecteuler.net/problem=002) | 20ms | 12ms | 86ms | 14ms | 48ms | 36ms |
| [`003`](https://projecteuler.net/problem=003) | 22ms | 16ms | 88ms | 18ms | 60ms | 40ms |
| [`004`](https://projecteuler.net/problem=004) | 74ms | 24ms | 114ms | 20ms | 62ms | 58ms |
| [`005`](https://projecteuler.net/problem=005) | 20ms | 14ms | 68ms | 12ms | 50ms | 32ms |
| [`006`](https://projecteuler.net/problem=006) | 16ms | 10ms | 66ms | 12ms | 60ms | 32ms |
| [`007`](https://projecteuler.net/problem=007) | 30ms | 20ms | 160ms | 22ms | 202ms | 86ms |
| [`008`](https://projecteuler.net/problem=008) | 18ms | 16ms | 64ms | 16ms | 50ms | 32ms |
| [`009`](https://projecteuler.net/problem=009) | 18ms | 12ms | 68ms | 12ms | 86ms | 39ms |
| [`010`](https://projecteuler.net/problem=010) | 146ms | 300ms | 350ms | 28ms | 486ms | 262ms |
| [`011`](https://projecteuler.net/problem=011) | 16ms | 16ms | 68ms | 12ms | 50ms | 32ms |
| [`012`](https://projecteuler.net/problem=012) | 76ms | 56ms | 642ms | 46ms | 998ms | 363ms |
| [`013`](https://projecteuler.net/problem=013) | 18ms | 16ms | 70ms | 14ms | 56ms | 34ms |
| [`014`](https://projecteuler.net/problem=014) | 544ms | 70ms | 1388ms | 44ms | 2054ms | 820ms |
| [`015`](https://projecteuler.net/problem=015) | 18ms | 18ms | 74ms | 14ms | 50ms | 34ms |
| [`016`](https://projecteuler.net/problem=016) | 18ms | 20ms | 68ms | 20ms | 54ms | 36ms |
| [`017`](https://projecteuler.net/problem=017) | 56ms | 12ms | 154ms | 18ms | 66ms | 61ms |
| [`018`](https://projecteuler.net/problem=018) | 20ms | 16ms | 66ms | 12ms | 54ms | 33ms |
| [`019`](https://projecteuler.net/problem=019) | 20ms | 12ms | 76ms | 16ms |      | 31ms |
| [`020`](https://projecteuler.net/problem=020) | 20ms | 20ms | 66ms | 14ms | 52ms | 34ms |
| [`021`](https://projecteuler.net/problem=021) | 80ms | 26ms | 450ms | 26ms |      | 145ms |
| [`022`](https://projecteuler.net/problem=022) | 34ms | 22ms | 88ms |      |      | 48ms |
| [`023`](https://projecteuler.net/problem=023) | 594ms | 156ms |      |      |      | 375ms |
| [`024`](https://projecteuler.net/problem=024) | 20ms |      | 68ms | 14ms |      | 34ms |
| [`025`](https://projecteuler.net/problem=025) | 16ms | 16ms | 84ms | 14ms | 52ms | 36ms |
| [`026`](https://projecteuler.net/problem=026) | 56ms |      | 158ms |      |      | 107ms |
| [`027`](https://projecteuler.net/problem=027) | 224ms | 76ms |      |      |      | 150ms |
| [`028`](https://projecteuler.net/problem=028) | 20ms | 10ms | 80ms |      |      | 36ms |
| [`029`](https://projecteuler.net/problem=029) | 158ms | 14ms | 102ms |      |      | 91ms |
| [`030`](https://projecteuler.net/problem=030) | 32ms | 30ms | 94ms |      |      | 52ms |
| [`031`](https://projecteuler.net/problem=031) | 40ms |      | 114ms |      |      | 77ms |
| [`032`](https://projecteuler.net/problem=032) | 300ms | 772ms |      |      |      | 536ms |
| [`033`](https://projecteuler.net/problem=033) | 18ms |      | 74ms |      |      | 46ms |
| [`034`](https://projecteuler.net/problem=034) | 58ms | 414ms | 170ms |      |      | 214ms |
| [`035`](https://projecteuler.net/problem=035) | 644ms | 132ms |      |      |      | 388ms |
| [`036`](https://projecteuler.net/problem=036) | 20ms | 156ms | 74ms |      |      | 83ms |
| [`037`](https://projecteuler.net/problem=037) | 176ms | 90ms |      |      |      | 133ms |
| [`038`](https://projecteuler.net/problem=038) | 78ms |      | 174ms |      |      | 126ms |
| [`039`](https://projecteuler.net/problem=039) | 18ms |      | 106ms | 18ms |      | 47ms |
| [`040`](https://projecteuler.net/problem=040) | 18ms | 12ms | 66ms | 14ms | 50ms | 32ms |
| [`041`](https://projecteuler.net/problem=041) | 472ms | 208ms |      |      |      | 340ms |
| [`042`](https://projecteuler.net/problem=042) | 28ms |      | 88ms |      |      | 58ms |
| [`043`](https://projecteuler.net/problem=043) | 22ms | 14ms | 68ms |      |      | 34ms |
| [`044`](https://projecteuler.net/problem=044) | 100ms | 44ms | 602ms |      |      | 248ms |
| [`045`](https://projecteuler.net/problem=045) | 20ms | 14ms | 84ms | 16ms | 108ms | 48ms |
| [`046`](https://projecteuler.net/problem=046) | 38ms | 14ms | 276ms |      |      | 109ms |
| [`048`](https://projecteuler.net/problem=048) | 66ms | 18ms | 86ms | 36ms | 56ms | 52ms |
| [`049`](https://projecteuler.net/problem=049) | 240ms | 220ms |      |      |      | 230ms |
| [`050`](https://projecteuler.net/problem=050) | 16ms | 12ms |      |      |      | 14ms |
| [`052`](https://projecteuler.net/problem=052) | 124ms | 58ms | 262ms |      |      | 148ms |
| *average* | 98ms | 74ms | 170ms | 19ms | 211ms | 114ms |
| *count* | 50 | 43 | 42 | 27 | 23 | 185 |

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

  - [ ] comment and clean up all solutions
  - [ ] implement tests for all problems
  - [ ] improve execution speed on some ruby/python solutions
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
    worked with a scheme before and it's reportedly very fast.
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

Verdict: there are far too many dope programming languages out there. I will try
my luck with these few, but whichever I choose, there will be ten others just as
great.

## License

See [license.md](license.md) for more information. 
