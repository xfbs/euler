# Project Euler Solutions [![Build Status](https://travis-ci.org/xfbs/euler.svg?branch=master)](https://travis-ci.org/xfbs/euler)

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

| problem | crystal |    c | ruby | python | rust |
| ------: | ------: | ---: | ---: | -----: | ---: |
| `001` |   20 |   10 |   60 |   40 |   70 |
| `002` |   30 |   10 |   90 |   50 |   80 |
| `003` |   20 |   20 |  100 |   60 |   70 |
| `004` |   60 |   20 |  340 |  720 |  100 |
| `005` |   20 |   10 |   70 |   60 |   80 |
| `006` |   20 |    0 |   70 |   50 |   70 |
| `007` |   30 |   30 |  180 |  190 |   80 |
| `008` |   20 |    0 |   70 |   50 |      |
| `009` |   10 |   10 |   80 |   80 |   80 |
| `010` |  470 |  300 |      |  550 |  100 |
| `011` |    0 |      |   60 |      |      |
| `012` |   70 |   30 |  630 | 1000 |      |
| `013` |   20 |    0 |   60 |   50 |      |
| `014` |  530 |   70 |      |      |      |
| `015` |   20 |   20 |   60 |      |      |
| `016` |   10 |      |   70 |      |      |
| `017` |   30 |   20 |  100 |      |      |
| `018` |   30 |   10 |   60 |      |      |
| `019` |   10 |    0 |   70 |      |      |
| `020` |   10 |      |   80 |      |      |
| `021` |   70 |   20 |  430 |      |      |
| `022` |   30 |   20 |   90 |      |      |
| `023` |  590 |  140 |      |      |      |
| `024` |   10 |      |   60 |      |      |
| `025` |      |      |      |   60 |      |
| `026` |   30 |      |  150 |      |      |
| `027` |      |  360 |      |      |      |
| `028` |   10 |   20 |   70 |      |      |
| `029` |  300 |    0 |   80 |      |      |
| `030` |   20 |   30 |   80 |      |      |
| `031` |   30 |      |   90 |      |      |
| `032` |  310 |  700 |      |      |      |
| `033` |    0 |      |   70 |      |      |
| `034` |   60 |  430 |  230 |      |      |
| `035` |  840 |  150 |      |      |      |
| `036` |   10 |  150 |   60 |      |      |
| `037` |      |   90 |      |      |      |
| `038` |   80 |      |  160 |      |      |
| `039` |   10 |      |  100 |      |      |
| `040` |   20 |   10 |   60 |      |      |
| `041` |      |  750 |      |      |      |
| `042` |   20 |      |   60 |      |      |
| `043` |      |   10 |      |      |      |
| `044` |      |   40 |      |      |      |
| `045` |   20 |      |   80 |      |      |
| `046` |      |  140 |      |      |      |
| `048` |      |   20 |      |      |      |
| `049` |      |  190 |      |      |      |
| `050` |      |   20 |      |      |      |
| `052` |  100 |   60 |  270 |      |      |


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

