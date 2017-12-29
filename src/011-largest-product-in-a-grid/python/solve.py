import solver
import sys

datafile = open(sys.argv[1])
grid = datafile.readlines()
grid = map(lambda x: list(map(int, x.strip().split(' '))), grid)

print(solver.solve(list(grid), 4))
