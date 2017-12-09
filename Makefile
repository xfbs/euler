check:
	ruby euler.rb check -c

overview:
	ruby euler.rb check -c -s -p 1-100 -t 4

build:
	ruby euler.rb build

test:
	ruby euler.rb test

clean:
	ruby euler.rb clean
