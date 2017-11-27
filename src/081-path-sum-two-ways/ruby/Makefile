BUNDLER = bundler
RAKE    = rake
CONFIG  = Gemfile
SOURCES = $(wildcard lib/**.rb)
SOLVER	= bin/solve
DATAFILE= matrix.txt

build: $(CONFIG)
	$(BUNDLER) install

test: $(CONFIG) $(SOURCES)
	$(RAKE) test

solve: $(CONFIG) $(SOURCES) $(SOLVER)
	@$(BUNDLER) exec $(SOLVER) $(DATAFILE)

clean:

.PHONY: test build solve clean
