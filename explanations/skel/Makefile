include ../../global.mk
PANDOC		= pandoc
EXPLANATION	= EXPLANATION.md
PROBLEM		= PROBLEM.md
IMAGES		= $(wildcard img/*)
OUTPUTS		= README.pdf README.md

build: $(OUTPUTS)

README.md: $(EXPLANATION) $(PROBLEM)
	cat $(PROBLEM) > $@
	echo >> $@
	cat $(EXPLANATION) >> $@

%.pdf: %.md $(IMAGES)
	$(PANDOC) $^ -o $@
