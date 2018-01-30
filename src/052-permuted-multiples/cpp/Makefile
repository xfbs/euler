DATAFILE = $(wildcard ../*.txt)
LIBDIR   = ../../../lib/cpp
OPTIMIZE = -O3
CPPFLAGS = -Isrc -I$(LIBDIR)/include -std=c++17 -Wall -pedantic $(OPTIMIZE)
LDFLAGS  = -L$(LIBDIR)/lib -lm -leuler $(OPTIMIZE)
LIBEULER = $(LIBDIR)/lib/libeuler.a
SOURCES  = $(wildcard src/*.cpp)
HEADERS  = $(wildcard src/*.hpp)
TARGETS  = $(wildcard bin/*.cpp)
TESTS    = $(wildcard test/*.cpp)
OBJECTS  = $(SOURCES:%.cpp=%.o)

build: $(TARGETS:%.cpp=%)

solve: bin/main
	@./bin/main $(DATAFILE)

test: test/all
	@./test/all

clean:
	$(RM) $(TARGETS:%.cpp=%) bin/*.o src/*.o test/*.o test/all

fmt: $(SOURCES) $(TARGETS) $(HEADERS) $(TESTS)
	clang-format -i $^

bin/%: bin/%.o $(OBJECTS) $(LIBEULER)
	$(CXX) -o $@ $< $(OBJECTS) $(LDFLAGS)

test/all: $(OBJECTS) $(LIBEULER) $(TESTS:%.cpp=%.o)
	$(CXX) -o $@ $(OBJECTS) $(TESTS:%.cpp=%.o) $(LDFLAGS)

$(LIBEULER):
	cd $(LIBDIR) && make

.PHONY: build solve clean test
