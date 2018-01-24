default: main

main: main.native

test: test.native

%.native: 
	ocamlbuild $@
	mv $@ $*

.PHONY: test default
