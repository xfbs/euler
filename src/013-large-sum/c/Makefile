DATAFILE = ../numbers.txt

main: main.o
	$(CC) -o $@ $^

test:

solve:
	@./main $(DATAFILE)

clean:
	$(RM) *.o main

build: main

.PHONY: build test clean
