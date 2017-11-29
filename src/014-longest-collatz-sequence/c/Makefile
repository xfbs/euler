DATAFILE = ../numbers.txt

main: main.o lib.o
	$(CC) -o $@ $^

test: test.o lib.o
	$(CC) -o $@ $^
	@./test

solve:
	@./main $(DATAFILE)

clean:
	$(RM) *.o test main

build: main

.PHONY: build test clean
