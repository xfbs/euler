CRYSTAL = crystal
SHARDS 	= shards
RM	    = rm -f
SOURCES = $(wildcard src/*.cr src/*/*.cr)
TESTS	= $(wildcard test/*_test.cr)
CONFIG  = shard.yml

# build and run the tests from 'spec'
test:
	$(CRYSTAL) spec

# clean the project folder. shards places temporary files in the `.shards` and
# `lib` directories, and the executables are in `bin/`. also deletes shard.lock
# to allow for automatic version discovery
clean:
	$(SHARDS) prune
	$(RM) -r .shards lib bin shard.lock

# runs the crystal code formatter over the code
fmt: $(SOURCES)
	$(CRYSTAL) tool format

doc:
	$(CRYSTAL) docs --output=../../../doc/lib/crystal

.PHONY: test clean fmt
