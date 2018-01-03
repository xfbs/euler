# discover data file automatically and pass it to the solve script as argument
# if found. CHEZ is the name of the chez scheme binary (might be called `scheme`
# on some older systems). LIBDIR is the base directory where the shared
# libraries are kept. FLAGS are passed to the chez binary.
DATAFILE= $(wildcard ../*.txt)
CHEZ    = chez
RM      = rm -f
LIBDIR  = ../../../lib/chez
FLAGS   = --compile-imported-libraries
FLAGS  += --optimize-level 3
FLAGS  += --libdirs src:$(LIBDIR)/thunderchez:$(LIBDIR)/shared

# pre-compile the solve script and it's dependencies
build: src/solve.so

# run the solve script, passing it the path to the DATAFILE if present
solve: src/solve.so
	@chez $(FLAGS) --program $^ $(DATAFILE)

# runs unit tests
test: test/solver.so
	@chez $(FLAGS) --program $^

# removes precompiled cached files
clean:
	$(RM) src/*.so test/*.so

# starts a REPL with the same flags as the scripts are normally run (such that
# all scripts and libraries are importable)
repl:
	@chez $(FLAGS)

%.so: %.ss
	@echo '(maybe-compile-program "$^")' | $(CHEZ) -q $(FLAGS)

.PHONY: build solve test clean repl
