OPTIMIZE = -O2
CXXFLAGS = -std=c++17 -Wall -pedantic -Iinclude $(OPTIMIZE)
LDFLAGS  = -Llib -lm $(OPTIMIZE)
SOURCES  = $(wildcard src/*.cpp)
HEADERS  = $(wildcard include/euler/*.hpp)
TESTS    = $(wildcard test/*_test.cpp)
TARGET   = lib/libeuler.a

build: $(TARGET)

clean:
	$(RM) src/*.o test/all test/*_test.o $(TARGET)

test: test/all
	@./test/all

fmt: $(SOURCES) $(HEADERS) $(TESTS)
	clang-format -i $^

repl: $(TARGET)
	cling $(CXXFLAGS) $(LDFLAGS) -leuler

test/all: $(TESTS:%.cpp=%.o) $(TARGET) test/all.o
	$(CXX) -o $@ $(TESTS:%.cpp=%.o) test/all.o $(LDFLAGS) -leuler

$(TARGET): $(SOURCES:%.cpp=%.o) $(HEADERS)
	ar cr $@ $(SOURCES:%.cpp=%.o)
	ranlib $@

.PHONY: build test clean fmt repl
