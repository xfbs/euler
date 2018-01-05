# some problems requite auxillary datafiles, which are discovered automatically
# by being a .txt file in the problem root folder.
# LIBDIR is the directory for shared code between C solutions.
# CFLAGS and LDFLAGS are flags passed to the compiler for compilation or
# linking, they are set to include LIBDIR in the search path for headers, to use
# a modern version of C, and to show extra warnings.
# SOURCES are all the .c files that are to be compiled, containing the functions
# to solve the problem.
# LIBEULER is a shared library with functions from other solutions to reuse.
# TARGETS are all binaries to be built.
DATAFILE = $(wildcard ../*.txt)
LIBDIR   = ../../../lib/c
CFLAGS 	+= -Isrc -I$(LIBDIR)/include -std=c99 -Wall -pedantic
LDFLAGS  = -lm
SOURCES  = $(wildcard src/*.c)
LIBEULER = $(LIBDIR)/lib/libeuler.a
TARGETS  = $(wildcard bin/*.c)

# builds all target. each *.c file in bin/ is considered a target and built and
# linked against all source files and libeuler.a
build: $(TARGETS:%.c=%)

# run the solver
solve:
	@./bin/main

# build and run all tests. every src/*.c file must have a corresponding
# test/*_test.c file, which are all built and run.
test: $(SOURCES:src/%.c=test/%_test)
	@cd test && ./all.sh

# clean up temporary files and binaries.
clean:
	$(RM) src/*.o test/*_test bin/main

# build a given binary, bin/*, from bin/*.c, linked against all files in src/*
# and libeuler.a
bin/%: bin/%.o $(SOURCES:%.c=%.o) $(LIBEULER)
	$(CC) -o $@ $^ $(LDFLAGS)

# build a given test, test/*_test, from test/*_test.c and src/*.c, linked
# against libeuler.a
test/%_test: test/%_test.o src/%.o $(LIBEULER)
	$(CC) -o $@ $^ $(LDFLAGS)

# build libeuler.a. all files that are in src/ and all corresponding header
# files in src/euler/ are added to this automatically, to be able to share code
# across solutions.
$(LIBEULER):
	cd $(LIBDIR) && make

.PHONY: build solve clean test
