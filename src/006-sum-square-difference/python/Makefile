DATAFILE    =
PYTHON	    = python3
PYTHONPATH  = ../../../lib/python
export PYTHONPATH

build:

solve:
	@$(PYTHON) solve.py

test:
	@$(PYTHON) -m unittest discover --verbose

clean:
	$(RM) -rf *.pyc */*.pyc __pycache__ */__pycache__

.PHONY: build solve test clean
