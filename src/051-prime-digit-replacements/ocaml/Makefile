OCAMLBUILD = ocamlbuild -use-ocamlfind

main: bin/main

test: bin/test
	./bin/test

clean:
	$(RM) -r bin/* _build

bin/%: %.native
	mv $< $@

%.native:
	$(OCAMLBUILD) $@

.PHONY: test default clean
