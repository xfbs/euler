SOURCES=$(wildcard src/*.c)
HEADERS=$(wildcard src/*.h)
TESTS=$(wildcard test/*.c)
BINARIES=$(wildcard bin/*.c)

CFLAGS += -Isrc/

build: $(BINARIES:%.c=%) $(TESTS:%.c=%)

$(BINARIES:%.c=%): $(BINARIES:%.c=%.o) $(SOURCES:%.c=%.o)
	$(CC) $(LDFLAGS) -o $@ $^

$(TESTS:%.c=%): $(TESTS:%.c=%.o) $(SOURCES:%.c=%.o)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(SOURCES:%.c=%.o)
	$(RM) $(TESTS:%.c=%.o)
	$(RM) $(TESTS:%.c=%)
	$(RM) $(BINARIES:%.c=%.o)
	$(RM) $(BINARIES:%.c=%)

test: $(TESTS:%.c=%)
	@./test/test

solve: $(BINARIES:%.c=%)
	@./bin/solve

.PHONY: build test clean solve
