# some problems need an auxillary data file, which is discovered automatically
# here and passed to the solution as argument.
# all problems use python3, but should be mostly compatible with python2 as
# well. PYTHONPATH is a special variable to tell python where to load libraries
# from, which is set manually here.
DATAFILE    = $(wildcard ../*.txt)
PYTHON	    = python3
PYTHONPATH  = ../../../lib/python
export PYTHONPATH

# compile all files. this can speed up the initial parsing of the files
build:
	$(PYTHON) -m compileall .

# run the solve script, which is in solve.py
solve:
	@$(PYTHON) solve.py $(DATAFILE)

# run the tests, which are in the test directory and discovered automatically,
# but they must be named test_*.py
test:
	$(PYTHON) -m unittest discover --verbose

# cleans compiled files cache
clean:
	$(RM) -rf *.pyc */*.pyc __pycache__ */__pycache__

.PHONY: build solve test clean
