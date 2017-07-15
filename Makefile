DATADIR		= "$(CURDIR)/data"
CHECKERDIR	= "$(CURDIR)/checker"
CACHEDIR	= "$(CURDIR)/.cache"
PROBLEMDIR 	= "$(CURDIR)/problems"
SOLUTIONDIR	= "$(CURDIR)/solutions"
PROBLEMS	= all
LANGUAGES	= all
BUNDLE		= bundle
MKDIR		= mkdir -p
RUBY		= ruby

# export all variables
export

build: setup
	cd $(SOLUTIONDIR) && $(MAKE) $@

setup:
	$(MKDIR) $(CACHEDIR)

clean:
	cd $(SOLUTIONDIR) && $(MAKE) $@
	$(RM) $(CACHEDIR)

setup-checker: setup
	$(BUNDLE) install --path="$(CACHEDIR)/ruby" --gemfile="$(CHECKERDIR)/Gemfile"

check: setup build
	$(RUBY) $(CHECKERDIR)/checker.rb check --langs="$(LANGUAGES)" --problems="$(PROBLEMS)"

.PHONY: build setup clean check
