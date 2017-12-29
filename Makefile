# checks all problems (build, test, verify), prints of any errors occured and
# how much time, on average, it took to solve for each implementation
check:
	ruby euler.rb check --color

# gives an overview over which problems have working solutions
overview:
	ruby euler.rb check --color --overview --problem 1-100 --thread 4

# runs `make build` for all implementations
build:
	ruby euler.rb build

# runs `make test` for all implementations, printing any error messages if they
# occur
test:
	ruby euler.rb test --color --verbose

# shows an overview over how many problems have been solved, and a list of
# languages and how many of the solutions have been ported to each of them.
goals:
	ruby euler.rb goals --color

# runs `make clean` for each solution
clean:
	ruby euler.rb clean

# generates a json-formatted hash for each problem with the amount of time each
# solution takes, for programmatic use.
json:
	@ruby euler.rb check --json -r 5
