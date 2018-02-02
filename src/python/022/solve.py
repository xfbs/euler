import solver
import sys

with open(sys.argv[1]) as datafile:
   names = list(map(lambda n: n[1:-1], datafile.read().split(',')))

print(solver.solve(names))
