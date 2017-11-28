# commands
PYTHON	= python
PIP		= pip

# files
REQUIREMENTS	= requirements.txt
SOLUTIONPY		= solution.py
TESTPY			= test.py

# install requirements
build:
	$(PIP) install -q -r $(REQUIREMENTS)

# run solution.py
solve:
	@$(PYTHON) $(SOLUTIONPY)

# run test.pi
test:
	@$(PYTHON) $(TESTPY)

# nothing to clean up
clean:

.PHONY: build solve test clean
