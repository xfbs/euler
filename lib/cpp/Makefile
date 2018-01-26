OPTIMIZE = -O2
CXXFLAGS = -std=c++1z -Wall -pedantic -Iinclude $(OPTIMIZE)
LDFLAGS  = -lm $(OPTIMIZE)
FILES    = prime digits
TARGET   = lib/libeuler.a

build: $(TARGET)

clean:
	$(RM) src/*.o test/all test/*_test.o $(TARGET)

test: test/all
	@./test/all

# FIXME: dependency on .hpp files
test/all: $(FILES:%=src/%.o) $(FILES:%=test/%_test.o) test/all.o
	$(CXX) -o $@ $^ $(LDFLAGS)

fmt: $(FILES:%=src/%.cpp) $(FILES:%=test/%_test.cpp) $(FILES:%=include/euler/%.hpp)
	clang-format -i $^

$(TARGET): $(FILES:%=src/%.o) $(FILES:%=include/euler/%.hpp)
	ar cr $@ $(FILES:%=src/*.o)
	ranlib $@

.PHONY: build test clean fmt
