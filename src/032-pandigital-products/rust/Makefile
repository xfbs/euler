# some solutions need auxillary data files, which are discovered automatically
# here and passed to the solution as an argument.
# cargo is the rust package manager, it takes care of building the code as well
# as importing dependencies. if needed, the CARGO variable can be replaced with
# `rustup nightly run cargo` or equivalent to test with different versions of
# rust.
# this makefile assumes that all sources are flat in `src/`.
DATAFILE= $(wildcard ../*.txt)
CARGO   = cargo
CONFIG  = Cargo.toml
SOURCES = $(wildcard src/*.rs) src/bin/solve.rs
RM      = rm -f

# the build target always does a release build, but there is also a debug target
build: release
release: target/release/solve
debug: target/debug/solve

# build the project, either a debug or a release build
target/debug/solve: $(CONFIG) $(SOURCES)
	$(CARGO) build
target/release/solve: $(CONFIG) $(SOURCES)
	$(CARGO) build --release

# run unit, integration and doc tests for the solution
test: $(CONFIG) $(SOURCES)
	$(CARGO) test

# run the solver. this will build the project if the binary is not available.
solve: target/release/solve
	@./target/release/solve $(DATAFILE)

# cargo clean takes care of removing all build, intermediate and binary files in
# the `target/` folder, but this also deletes the lock file
clean:
	$(CARGO) clean
	$(RM) Cargo.lock

.PHONY: test build solve clean release debug
