include global.mk
PROBLEMS	= all
LANGUAGES	= all
BUNDLE		= bundle
MKDIR		= mkdir -p
RUBY		= ruby

build:
	@cd $(SOLUTIONDIR) && $(MAKE) $@

setup:
	#$(MKDIR) $(CACHEDIR)

clean:
	@cd $(SOLUTIONDIR) && $(MAKE) $@
	$(RM) $(CACHEDIR)

test:
	@cd $(SOLUTIONDIR) && $(MAKE) $@

setup-checker: setup
	@cd $(CHECKERDIR) && $(BUNDLE) install

check: setup build
	@cd $(CHECKERDIR) && $(BUNDLE) exec exe/check all

.PHONY: build setup setup-checker clean check
