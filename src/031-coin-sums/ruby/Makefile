DATAFILE=
RUBY    = ruby
RBOPTS  = -I../../../lib/ruby
SOURCES = $(wildcard src/*.rb)
TESTS   = $(wildcard test/*_test.rb)

build:

test: $(SOURCES) $(TESTS)
	@$(RUBY) $(RBOPTS) test/all.rb

solve: $(SOURCES)
	@$(RUBY) $(RBOPTS) src/solve.rb $(DATAFILE)

clean:

.PHONY: build test clean solve
