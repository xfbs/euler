check:
	ruby euler.rb check --color

overview:
	ruby euler.rb check --color --overview --problem 1-100 --thread 4

build:
	ruby euler.rb build

test:
	ruby euler.rb test --color --verbose

goals:
	ruby euler.rb goals --color

clean:
	ruby euler.rb clean
