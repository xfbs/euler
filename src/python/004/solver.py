import math

def palindrome(num):
   rev = 0
   cur = num
   exp = 1

   while cur != 0:
      rev *= 10
      rev += cur % 10
      cur //= 10
      exp *= 10

   return ((num * exp) + rev, (num // 10 * exp) + rev)

def factorizable(num, min_factor, max_factor):
   for d in range(min_factor, math.floor(math.sqrt(num)) + 1):
      if num % d == 0 and (num // d) >= min_factor and (num // d) < max_factor:
         return True
   return False

def solve(m):
   # minimum number factor to consider
   min_factor = 10**(m-1)
   max_factor = min_factor * 10

   for (palin, _) in map(palindrome, range(max_factor-1, min_factor-1, -1)):
      if factorizable(palin, min_factor, max_factor):
         return palin

   for (_, palin) in map(palindrome, range(max_factor-1, min_factor-1, -1)):
      if factorizable(palin, min_factor, max_factor):
         return palin
