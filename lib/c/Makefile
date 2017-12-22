CFLAGS = -std=c99 -Wall -pedantic
LIBS = gcd_lcm bitvec simple_prime palindrome vec8 vec divisor_sum

build: $(LIBS:%=%.a)

%.a: %.o
	ar cr $@ $^
	ranlib $@

%_test: %.o %_test.o
	@$(CC) -o $@ $^ $(LDFLAGS)

test: $(LIBS:%=%_test)
	@./gcd_lcm_test
	@./bitvec_test
	@./simple_prime_test
	@./palindrome_test
	@./vec8_test
	@./vec_test
	@./divisor_sum_test

clean:
	$(RM) -rf *.o
	$(RM) -rf *.a
	$(RM) -rf *_test

.PHONY: build test
