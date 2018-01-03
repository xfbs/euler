DATAFILE= $(wildcard ../*.txt)
CHEZ    = chez
RM      = rm -f
LIBDIR  = ../../../lib/chez
SOURCES = *.ss
FLAGS   = --compile-imported-libraries
FLAGS  += --optimize-level 3
FLAGS  += --libdirs src:$(LIBDIR)/thunderchez:$(LIBDIR)/shared

build: src/solve.so

solve: src/solve.so
	@chez $(FLAGS) --program $^ $(DATAFILE)

test: test/solver.so
	@chez $(FLAGS) --program $^ $(DATAFILE)

clean:
	$(RM) src/*.so test/*.so

repl:
	@chez $(FLAGS)

%.so: %.ss
	@echo '(maybe-compile-program "$^")' | $(CHEZ) -q $(FLAGS)

.PHONY: build solve test clean repl
