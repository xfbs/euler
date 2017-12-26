# Project Euler Solutions [![Build Status](https://travis-ci.org/xfbs/euler.svg?branch=master)](https://travis-ci.org/xfbs/euler) [![GitHub release](https://img.shields.io/github/release/qubyte/rubidium.svg?style=plastic)]()

This is a repository of my solutions to [Project Euler](https://projecteuler.net/)
problems. Mostly intended as a tool for me to use when learning a new language —
solving problems or porting solutions into a new language helps a lot to get a 
grasp on the new language's features.

Under the `src/` directory, there is a folder for (most of) the Project Euler
problems (I have to update these occasionally as new problems are released).
Each folder contains a problem description in `problem.md`. Most problem folders also
contain the (numeric) solution to the problem in the file `.solution.bcrypt` as
a [bcrypt](https://en.wikipedia.org/wiki/Bcrypt)ed hash (which is used by my 
[euler.rb](euler.rb) script to check if my solution is correct or not).

Ideally all, practically only some directories have one or more solution(s) in
subfolders named after the language they are written in, such as `c/` or
`ruby/`. Every solution subfolder contains a `Makefile` that responds to commands
such as `make build`, `make solve`, `make clean` and `make test`. The idea is
that my script will `make build` to build the solution and then call
`make solve` to get the solution, compare that with the stored answer, and
based on that decide if the solution is correct or not.

## Rules

  - A problem is only solved when the solution
      - yields the correct answer
      - takes less than 1s (1000ms) to compute the answer
      - is completely written by myself, without having looked at someone else's
        solution (unless by accident)
  - The more languages I can solve a problem in, the better
  - I should make use of each language's dogmas and idioms as well as possible
    and try to exploit all of it's features
  - When possible, I should reduce dependencies to what's available in the
    language by default, but if I really need to pull in a library I can
  - Every solution should have tests so I can work on my TDD workflow
  - When necessary, I should be able to share code across solutions (especially
    in languages where the standard API is limited, to avoid having to
    reimplement the same things multiple times), but this code also has to be
    tested

## Progress

Here is a table of the current status of the project. The numbers represent how
many miliseconds the implementation takes to compute the correct answer (blank
means not implemented). 

<details>
  <summary>Click to view</summary>

| problem | crystal |    c | ruby | python | rust | *avg* |
| ------: | ------: | ---: | ---: | -----: | ---: | ----: |
| `001` |   30 |   10 |   70 |   60 |   70 | 48 |
| `002` |   20 |   20 |   60 |   40 |   70 | 42 |
| `003` |   30 |   10 |   90 |   50 |   70 | 50 |
| `004` |  100 |   20 |  340 |  740 |   90 | 258 |
| `005` |   20 |   20 |   60 |   40 |   80 | 44 |
| `006` |   30 |   10 |   60 |   50 |   60 | 42 |
| `007` |   40 |   30 |  160 |  190 |   70 | 98 |
| `008` |   30 |    0 |  130 |   60 |      | 55 |
| `009` |   20 |   10 |   80 |   90 |   80 | 56 |
| `010` |  500 |  290 |      |  620 |   80 | 372 |
| `011` |   20 |      |   60 |      |      | 40 |
| `012` |  100 |   40 |  630 |  990 |      | 440 |
| `013` |   20 |   30 |   90 |   40 |      | 45 |
| `014` |  510 |   60 |      |      |      | 285 |
| `015` |   20 |   30 |   60 |      |      | 36 |
| `016` |   40 |      |   60 |      |      | 50 |
| `017` |   60 |    0 |  110 |      |      | 56 |
| `018` |   20 |   10 |   70 |      |      | 33 |
| `019` |   30 |   10 |   80 |      |      | 40 |
| `020` |   20 |      |   60 |      |      | 40 |
| `021` |   70 |   30 |  410 |      |      | 170 |
| `022` |   50 |   20 |   80 |      |      | 50 |
| `023` |  650 |  150 |      |      |      | 400 |
| `024` |   20 |      |   60 |      |      | 40 |
| `025` |      |      |      |   60 |      | 60 |
| `026` |   30 |      |  130 |      |      | 80 |
| `027` |      |  360 |      |      |      | 360 |
| `028` |   20 |   10 |   70 |      |      | 33 |
| `029` |  270 |   10 |  110 |      |      | 130 |
| `030` |   50 |   20 |   90 |      |      | 53 |
| `031` |   50 |      |  110 |      |      | 80 |
| `032` |  290 |  720 |      |      |      | 505 |
| `033` |   20 |      |   70 |      |      | 45 |
| `034` |   80 |  390 |  170 |      |      | 213 |
| `035` |  860 |  140 |      |      |      | 500 |
| `036` |   20 |  150 |   80 |      |      | 83 |
| `037` |      |  100 |      |      |      | 100 |
| `038` |   80 |      |  170 |      |      | 125 |
| `039` |   40 |      |  100 |      |      | 70 |
| `040` |   30 |   10 |   60 |      |      | 33 |
| `041` |      |  720 |      |      |      | 720 |
| `042` |   30 |      |   80 |      |      | 55 |
| `043` |      |   20 |      |      |      | 20 |
| `044` |      |   50 |      |      |      | 50 |
| `045` |   30 |      |   70 |      |      | 50 |
| `046` |      |  140 |      |      |      | 140 |
| `048` |      |   10 |      |      |      | 10 |
| `049` |      |  210 |      |      |      | 210 |
| `050` |      |   20 |      |      |      | 20 |
| `052` |  170 |   70 |  260 |      |      | 166 |
| *count* | 40 | 38 | 35 | 13 | 9 | 27 |
| *average* | 113 | 103 | 125 | 233 | 74 | 129 |

</details>

## Other Repositories

There are some other people putting their solutions to project euler problems
online:

  - [mathblog.dk](http://www.mathblog.dk/project-euler-solutions/), solutions
    are in C#
  - [project nayuki](https://www.nayuki.io/page/project-euler-solutions),
    solutions are in Java, Python, Mathematica and Haskell
  - [haskell wiki](https://wiki.haskell.org/Euler_problems), solutions are in
    Haskell

These are useful to compare against after having solved a problem, to check if
there is a more elegant or efficient method.

## Tech Demo

[![asciicast](https://asciinema.org/a/OJ6I04nBYKx6Z1sfbMpMwgrck.png)](https://asciinema.org/a/OJ6I04nBYKx6Z1sfbMpMwgrck)

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
