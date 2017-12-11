# Project Euler Solutions [![Build Status](https://travis-ci.org/xfbs/euler.svg?branch=master)](https://travis-ci.org/xfbs/euler)

This is a repository of a couple of solutions to project euler problems. Mostly
intended as a tool for me to use when learning a new language — solving problems
or porting solutions into a new language helps a lot to get a grasp on the new
language's features.

Under the `src/` directory, I have a folder for (most of) the project euler
problems, with a problem description in `problem.md`. Most problem folders also
contain the (numeric) solution to the problem in the file `.solution.bcrypt`,
however as the name implies it has been run through the *bcrypt* hash function
to obscure it. Furthermore many directories have one or more solution in
subfolders named after the language they are written in, such as `c/` or
`ruby/`. Every solution subfolder contains a `Makefile` the responds to commands
such as `make build`, `make solve`, `make clean` and `make test`.

To automatically test all the solutions present there is a small script in the
root of the repository, which offers several ways to see which ones are correct
and which ones are not:

To see which problems are solved, 
`ruby euler.rb check --color --summary --problem 1-100 --thread 4` does the
trick. For more details, `ruby euler.rb check --color --problem 1-100` can be
used which reports more detail for each solution.

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

## Tech Demo

[![asciicast](https://asciinema.org/a/OJ6I04nBYKx6Z1sfbMpMwgrck.png)](https://asciinema.org/a/OJ6I04nBYKx6Z1sfbMpMwgrck)

