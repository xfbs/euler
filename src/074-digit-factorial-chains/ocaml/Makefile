OCAMLBUILD  = ocamlbuild -use-ocamlfind
OCAMLFORMAT = ocamlformat --inplace
SOURCES     = $(wildcard src/**) $(wildcard test/**)

build: bin/main

test: bin/test
	@./bin/test

solve: bin/main
	@./bin/main

clean:
	$(RM) -r bin/* _build

fmt:
	$(OCAMLFORMAT) $(SOURCES)

bin/%: %.native $(SOURCES)
	mv $< $@

%.native:
	$(OCAMLBUILD) $@

.PHONY: build test solve clean fmt
