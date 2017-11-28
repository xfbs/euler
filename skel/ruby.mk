include ../../global.mk

BUNDLER = bundler
RAKE    = rake
CONFIG  = Gemfile
SOURCES = $(wildcard lib/**.rb)
SOLVER	= bin/solve

build: $(CONFIG)
	$(BUNDLER) install

test: $(CONFIG) $(SOURCES)
	$(RAKE) test

solve: $(CONFIG) $(SOURCES) $(SOLVER)
	@$(BUNDLER) exec $(SOLVER)

clean:

.PHONY: test build solve clean
