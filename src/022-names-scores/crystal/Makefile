DATAFILE=../names.txt
CRYSTAL = crystal
SHARDS 	= shards
RM		= rm -f

build:
	$(SHARDS) build

test:
	@$(SHARDS) install
	@$(CRYSTAL) run test/*_test.cr -- --verbose

clean:
	$(RM) bin/solve
	$(RM) -r lib

solve:
	@./bin/solve $(DATAFILE)

.PHONY: build test clean solve
