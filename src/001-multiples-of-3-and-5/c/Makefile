solve: solve.o solution.o
	$(CC) -o solve $^

test: test.o solution.o
	$(CC) -o test $^
	./test

run: solve
	@./solve

clean: 
	$(RM) *.o test solve

.PHONY: build test clean
