import solver
import sys

datafile = open(sys.argv[1])
sequence = ""
for line in datafile:
   sequence += line.rstrip()

print(solver.solve(sequence, 13))
