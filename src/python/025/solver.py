import math

def solve(length):
   phi = (1 + math.sqrt(5)) / 2
   sum1 = 0.5 * math.log(5)
   sum2 = (length - 1) * math.log(10)
   return math.ceil((sum1 + sum2) / math.log(phi))
