main: main.o lib.o
	$(CC) -o $@ $^

test: test.o lib.o
	$(CC) -o $@ $^
	@./test

solve:
	@./main

clean:
	$(RM) *.o test main

.PHONY: build test clean
