CFLAGS = -std=c99 -Wall -pedantic -Iinclude
SOURCES = $(wildcard src/*.c)
TARGET  = lib/libeuler.a

build: lib/libeuler.a

$(TARGET): $(SOURCES:%.c=%.o)
	ar cr $@ $^
	ranlib $@

#%_test: %.o %_test.o
#	@$(CC) -o $@ $^ $(LDFLAGS)

#test: $(LIBS:%=%_test)
#	@./gcd_lcm_test
#	@./bitvec_test
#	@./simple_prime_test
#	@./palindrome_test
#	@./vec8_test
#	@./vec16_test
#	@./vec_test
#	@./divisor_sum_test

clean:
	$(RM) -rf src/*.o
	$(RM) $(TARGET)

.PHONY: build test
