import math

def divisor_sum(n):
   s = 0
   for d in range(1, math.floor(math.sqrt(n)) + 1):
      if n % d == 0:
         s += d
         if d != (n // d) and d != 1:
            s += n // d
   return s

def amicable_pair(num):
   partner = divisor_sum(num)

   if partner != num and divisor_sum(partner) == num:
      return (True, partner)
   else:
      return (False, None)

def solve(m):
   a = 0
   for candidate in range(1, m):
      res, partner = amicable_pair(candidate)

      if res:
         a += candidate
   return a


