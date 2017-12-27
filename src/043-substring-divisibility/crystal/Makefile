DATAFILE= ../words.txt
CRYSTAL = crystal
SHARDS 	= shards
RM	    = rm -f
SOURCES = $(wildcard src/*.cr)
TESTS	= $(wildcard test/*_test.cr)

build: bin/solve

solve:
	@./bin/solve $(DATAFILE)

test: bin/test
	@./bin/test --verbose

clean:
	$(SHARDS) prune
	$(RM) bin/solve bin/test
	$(RM) -r .shards

bin/solve: $(SOURCES)
	$(SHARDS) build solve --production

bin/test: $(SOURCES) $(TESTS)
	$(SHARDS) build test

.PHONY: build test clean solve
