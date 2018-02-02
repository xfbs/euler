# DATAFILE 	is a file that is passed to the solver that contains data provided
# 			for the problem.
# LIBDIR 	is a directory for shared code between C solutions.
# OPTIMISE 	sets the optimisation level used by the compiler and linker.
# CFLAGS 	are flags passed to the compiler for compilation
# LDFLAGS	are flags passed to the linker for linking.
# SOURCES 	are all the .c files that are to be compiled
# LIBEULER 	is a library of functions to be shared across solutions.
# TARGETS 	are all binaries to be built.
DATAFILE = $(wildcard ../*.txt)
LIBDIR   = ../../../lib/c
OPTIMISE = -O3
CFLAGS 	+= -Isrc -I$(LIBDIR)/include -std=c11 -Wall -pedantic $(OPTIMISE)
LDFLAGS  = -lm $(OPTIMISE)
SOURCES  = $(wildcard src/*.c)
LIBEULER = $(LIBDIR)/lib/libeuler.a
TARGETS  = $(wildcard bin/*.c)

# builds all target. each *.c file in bin/ is considered a target and built and
# linked against all source files and libeuler.a
build: $(TARGETS:%.c=%)

# run the solver
solve:
	@./bin/main $(DATAFILE)

# build and run all tests. every src/*.c file must have a corresponding
# test/*_test.c file, which are all built and run.
test: $(SOURCES:src/%.c=test/%_test)
	./test/solve_test

# clean up temporary files and binaries.
clean:
	$(RM) src/*.o test/*_test bin/main

# build a given binary, bin/*, from bin/*.c, linked against all files in src/*
# and libeuler.a
bin/%: bin/%.o $(SOURCES:%.c=%.o) $(LIBEULER)
	$(CC) -o $@ $^ $(LDFLAGS)

# build a given test, test/*_test, from test/*_test.c and src/*.c, linked
# against libeuler.a
test/%_test: test/%_test.o $(SOURCES:%.c=%.o) $(LIBEULER)
	$(CC) -o $@ $^ $(LDFLAGS)

# build libeuler.a. all files that are in src/ and all corresponding header
# files in src/euler/ are added to this automatically, to be able to share code
# across solutions.
$(LIBEULER):
	cd $(LIBDIR) && make

.PHONY: build solve clean test
