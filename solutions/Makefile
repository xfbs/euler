include ../global.mk

SOLUTIONS=$(wildcard ???-*.*)
TARGETS=build test clean

$(TARGETS): $(SOLUTIONS)

$(SOLUTIONS):
	@echo Running 'make $(MAKECMDGOALS)' for $@
	@$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TARGETS) $(SOLUTIONS)
