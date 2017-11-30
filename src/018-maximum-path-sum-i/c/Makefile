DATAFILE = ../triangle.txt

main: main.o lib.o
	$(CC) $(CFLAGS) -o $@ $^

test: test.o lib.o
	$(CC) $(CFLAGS) -o $@ $^
	@./test

solve:
	@./main $(DATAFILE)

clean:
	$(RM) *.o test main

build: main

.PHONY: build test clean
