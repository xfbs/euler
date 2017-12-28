DATAFILE= $(wildcard ../*.txt)
CARGO   = cargo
CONFIG  = Cargo.toml
SOURCES = $(wildcard src/*.rs) src/bin/solve.rs
RM      = rm -f

build: target/release/solve

target/debug/solve: $(CONFIG) $(SOURCES)
	$(CARGO) build

target/release/solve: $(CONFIG) $(SOURCES)
	$(CARGO) build --release

test: $(CONFIG) $(SOURCES)
	$(CARGO) test

solve: target/release/solve
	@./target/release/solve $(DATAFILE)

clean:
	$(CARGO) clean
	$(RM) Cargo.lock

.PHONY: test build solve clean
