DATAFILE = $(wildcard ../*.txt)
LIBDIR   = ../../../lib/cpp
OPTIMIZE = -O3
CPPFLAGS = -Isrc -I$(LIBDIR)/include -std=c++17 -Wall -pedantic $(OPTIMISE)
LDFLAGS  = -L$(LIBDIR)/lib -lm -leuler -lc++ $(OPTIMIZE)
LIBEULER = $(LIBDIR)/lib/libeuler.a
SOURCES  = $(wildcard src/*.cpp)
HEADERS  = $(wildcard src/*.hpp)
TARGETS  = $(wildcard bin/*.cpp)

build: $(TARGETS:%.cpp=%)

solve: bin/main
	@./bin/main $(DATAFILE)

test: test/all
	@./test/all

clean:
	$(RM) src/*.o test/*_test bin/main

fmt: $(SOURCES) $(TARGETS) $(HEADERS)
	clang-format -i $^

bin/%: bin/%.o $(SOURCES:%.cpp=%.o)
	$(CXX) -o $@ $^ $(LDFLAGS)

test/all: test/all.o $(SOURCES:%.cpp=%.o) $(SOURCES:src/%.cpp=test/%_test.o)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(LIBEULER):
	cd $(LIBDIR) && make

.PHONY: build solve clean test
