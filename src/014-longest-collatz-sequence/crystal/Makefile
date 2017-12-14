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
	@./bin/solve

.PHONY: build test clean solve
