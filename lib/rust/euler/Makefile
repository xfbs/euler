# some solutions need auxillary data files, which are discovered automatically
# here and passed to the solution as an argument.
# cargo is the rust package manager, it takes care of building the code as well
# as importing dependencies. if needed, the CARGO variable can be replaced with
# `rustup nightly run cargo` or equivalent to test with different versions of
# rust.
# this makefile assumes that all sources are flat in `src/`.
CARGO   = cargo
CONFIG  = Cargo.toml
SOURCES = $(wildcard src/*.rs)
RM      = rm -f

# run unit, integration and doc tests for the solution
test: $(CONFIG) $(SOURCES)
	$(CARGO) test

# cargo clean takes care of removing all build, intermediate and binary files in
# the `target/` folder, but this also deletes the lock file
clean:
	$(CARGO) clean
	$(RM) Cargo.lock

# runs cargo's formatter over the code
fmt: $(wildcard src/**.rs)
	$(CARGO) fmt

.PHONY: test clean fmt
