OPTIMIZE = -O3
CFLAGS   = -std=c11 -Wall -pedantic -Iinclude $(OPTIMIZE)
LDFLAGS  = -lm $(OPTIMIZE)
SOURCES  = $(wildcard src/*.c)
TESTS    = $(wildcard test/*_test.c) test/all.c test/doc_tests.c
TARGET   = lib/libeuler.a
DOXYGEN  = doxygen
DOXYFILE = config.doxygen
CFORMAT  = clang-format -i
CLING	 = cling

build: $(TARGET)

# clean temporary files from compilation and the target
clean:
	$(RM) src/*.o test/*.o test/all
	$(RM) $(TARGET)

# build and run all tests.
test: test/all
	@./test/all

# runs the clang-format code formatter for all files in this lib.
fmt: $(wildcard include/**.h src/*.c test/*.c)
	$(CFORMAT) $^

# generates documentation in ../../doc/lib/c
doc:
	$(DOXYGEN) $(DOXYFILE)

# start an interactive repl session with cling
repl:
	$(CLING) -Llib -leuler

# generate doc tests from the headers
test/doc_tests.c: $(wildcard include/euler/*.h) test/doc_tests.rb
	cd test && ruby doc_tests.rb > doc_tests.c

# generate main file for all tests
test/all.c: $(wildcard test/*_test.c) test/all.rb
	cd test && ruby all.rb > all.c

# take the sources and produce a library file
$(TARGET): $(SOURCES:%.c=%.o)
	ar cr $@ $^
	ranlib $@

# build a given test, test/*_test, from test/*_test.c and src/*.c
test/all: $(SOURCES:%.c=%.o) $(TESTS:%.c=%.o)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: build test clean fmt doc
