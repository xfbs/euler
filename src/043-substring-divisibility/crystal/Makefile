DATAFILE= $(wildcard ../*.txt)
CRYSTAL = crystal
SHARDS 	= shards
RM	    = rm -f
SOURCES = $(wildcard src/*.cr src/*/*.cr)
TESTS	= $(wildcard test/*_test.cr)
CONFIG  = shard.yml

build: bin/solve

solve: bin/solve
	@./bin/solve $(DATAFILE)

test: bin/test
	@./bin/test --verbose

clean:
	$(SHARDS) prune
	$(RM) -r .shards lib bin shard.lock

bin/solve: $(CONFIG) $(SOURCES)
	$(SHARDS) build solve --production

bin/test: $(CONFIg) $(SOURCES) $(TESTS)
	$(SHARDS) build test

.PHONY: build test clean solve
