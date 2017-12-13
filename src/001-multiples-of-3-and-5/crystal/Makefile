CRYSTAL = crystal
SHARDS 	= shards
RM		= rm -f

build:
	$(SHARDS) build

test:
	@$(CRYSTAL) run test/solver_test.cr -- --verbose

clean:
	$(RM) bin/solve
	$(RM) -r lib

solve:
	@./bin/solve

.PHONY: build test clean solve
