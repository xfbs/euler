# some problems have auxillary data files, these are found automatically here.
# RUBY denotes which ruby to use, for many solutions it should be possible to
# use jruby, rubinius (rbx) or similar.
# RUBYOPTS is needed to tell ruby where to find shared library files.
DATAFILE= $(wildcard ../*.txt)
RUBY    = ruby
RBOPTS  = -I../../../lib/ruby
SOURCES = $(wildcard src/*.rb src/*/*.rb)
TESTS   = $(wildcard test/*_test.rb)

# for MRI, this doesn't do anything. when using jruby, the code could be
# compiled here.
build:

# runs the unit tests in the `test/` folder.
test: $(SOURCES) $(TESTS)
	@$(RUBY) $(RBOPTS) test/all.rb --verbose

# runs the solver, solve.rb.
solve: $(SOURCES)
	@$(RUBY) $(RBOPTS) src/bin/solve.rb $(DATAFILE)

clean:

.PHONY: build test clean solve
