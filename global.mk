ROOTDIR		= $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
DATADIR		= $(ROOTDIR)data
CHECKERDIR	= $(ROOTDIR)checker
CACHEDIR	= $(ROOTDIR).cache
PROBLEMDIR 	= $(ROOTDIR)problems
SOLUTIONDIR	= $(ROOTDIR)solutions
