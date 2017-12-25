import solver
import sys

datafile = open(sys.argv[1])
numbers = []
for line in datafile:
   numbers.append(line)

print(solver.solve(numbers))
