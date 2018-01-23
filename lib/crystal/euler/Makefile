CRYSTAL = crystal
SHARDS 	= shards
RM	    = rm -f
SOURCES = $(wildcard src/*.cr src/*/*.cr)
TESTS	= $(wildcard test/*_test.cr)
CONFIG  = shard.yml

# build and run the unit tests from `test/`
test: bin/test
	@./bin/test --verbose

# clean the project folder. shards places temporary files in the `.shards` and
# `lib` directories, and the executables are in `bin/`. also deletes shard.lock
# to allow for automatic version discovery
clean:
	$(SHARDS) prune
	$(RM) -r .shards lib bin shard.lock

# runs the crystal code formatter over the code
fmt: $(SOURCES)
	$(CRYSTAL) tool format

# build test unit test executable
bin/test: $(CONFIG) $(SOURCES) $(TESTS)
	$(SHARDS) build test

.PHONY: test clean fmt
