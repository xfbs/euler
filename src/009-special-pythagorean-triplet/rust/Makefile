CARGO = cargo
CONFIG  = Cargo.toml
SOURCES = src/lib.rs src/test.rs src/bin/solve.rs

build: target/release/solve

target/debug/solve: $(CONFIG) $(SOURCES)
	$(CARGO) build

target/release/solve: $(CONFIG) $(SOURCES)
	$(CARGO) build --release

test: $(CONFIG) $(SOURCES)
	$(CARGO) test

solve: target/release/solve
	@$(CARGO) run --release -q solve

clean:
	$(CARGO) clean

.PHONY: test build solve clean
