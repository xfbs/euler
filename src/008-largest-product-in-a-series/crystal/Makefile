DATAFILE=../number.txt
CRYSTAL = crystal
SHARDS 	= shards
RM		= rm -f
SOURCES = $(wildcard src/*.cr)
TESTS	= $(wildcard test/*_test.cr)

build: bin/solve

test: bin/test
	@./bin/test --verbose

solve:
	@./bin/solve $(DATAFILE)

clean:
	$(SHARDS) prune
	$(RM) bin/solve bin/test
	$(RM) -r lib

bin/solve: $(SOURCES)
	$(SHARDS) build --production

bin/test: $(SOURCES) $(TESTS) lib/minitest
	$(CRYSTAL) build -o $@ test/*_test.cr

lib/minitest:
	$(SHARDS) install

.PHONY: build test clean solve
