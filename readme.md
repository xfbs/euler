# Project Euler Solutions

This is a repository of a couple of solutions to project euler problems. Mostly
intended as a tool for me to use when learning a new language — solving problems
or porting solutions into a new language helps a lot to get a grasp on the new
language's features.

The layout is rather simple, every problem has it's own directory under `src/`,
which contains a description of the problem in `problem.md`, and in some cases
also some data (as a `.txt` file) or an image for the description.

Every solution should have a `Makefile` with appropriate targets (`build`, 
`solve`, `test` and `clean`). This way, the supplied script `euler.rb` can 
automagically test solutions for correctness and speed.

To add a solution to a problem, you have to hash it with `bcrypt` and inside the
problem directory, save it in a file named `.solution.bcrypt`. This way the
`euler.rb` script can find it.
