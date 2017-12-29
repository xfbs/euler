import math

def solve(m):
   f = math.factorial(m)

   digit_sum = 0
   while f > 0:
      digit_sum += f % 10
      f //= 10

   return digit_sum
