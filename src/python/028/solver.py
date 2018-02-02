def solve(m):
   sum = 1
   cur = 1

   for ring in range(2, m, 2):
      cur += ring
      sum += cur
      cur += ring
      sum += cur
      cur += ring
      sum += cur
      cur += ring
      sum += cur

   return sum
