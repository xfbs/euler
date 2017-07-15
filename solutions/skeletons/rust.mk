CARGO=cargo

build:
	$(CARGO) build

test: build
	$(CARGO) test

solve: build
	$(CARGO) run solve

clean:
	$(CARGO) clean

.PHONY: test build solve clean
