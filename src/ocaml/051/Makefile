OCAMLBUILD = ocamlbuild -use-ocamlfind
SOURCES    = $(wildcard src/**)

build: bin/main

test: bin/test
	./bin/test

solve: bin/main
	./bin/main

clean:
	$(RM) -r bin/* _build

bin/%: %.native $(SOURCES)
	mv $< $@

%.native:
	$(OCAMLBUILD) $@

.PHONY: build test solve clean
