# some problems have auxillary data files, these are found automatically here.
# CRYSTAL is the crystal compiler, and SHARDS the crystal package manager. these
# can be set to different binaries to test out different versions of crystal.
DATAFILE= $(wildcard ../*.txt)
CRYSTAL = crystal
SHARDS 	= shards
RM	    = rm -f
SOURCES = $(wildcard src/*.cr src/*/*.cr)
TESTS	= $(wildcard test/*_test.cr)
CONFIG  = shard.yml

# build the project's executable. this always build it in production (release)
# mode. to build it in debug mode, use `shards build solve` manually.
build: bin/solve

# run the solve executable (building it before if it doesn't exist).
solve: bin/solve
	@./bin/solve $(DATAFILE)

# build and run the unit tests from `test/`
test: bin/test
	@./bin/test --verbose

# clean the project folder. shards places temporary files in the `.shards` and
# `lib` directories, and the executables are in `bin/`. also deletes shard.lock
# to allow for automatic version discovery
clean:
	$(SHARDS) prune
	$(RM) -r .shards lib bin shard.lock

# build the project executable
bin/solve: $(CONFIG) $(SOURCES)
	$(SHARDS) build solve --production

# build test unit test executable
bin/test: $(CONFIG) $(SOURCES) $(TESTS)
	$(SHARDS) build test

.PHONY: build test clean solve
