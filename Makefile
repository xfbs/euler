check:
	ruby euler.rb check --color

overview:
	ruby euler.rb check --color --overview --problem 1-100 --thread 4

build:
	ruby euler.rb build

test:
	ruby euler.rb test

clean:
	ruby euler.rb clean
