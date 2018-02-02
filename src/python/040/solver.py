def solve(n):
   product = 1
   for d in map(lambda x: champernowne_digit(10**x - 1), range(0, n)):
      product *= d
   return product

def champernowne_digit(pos):
   mag = 1
   exp = 9

   while pos >= (mag * exp):
      pos -= mag * exp
      exp *= 10
      mag += 1

   off = mag - (pos % mag) - 1
   num = (exp // 9 + pos // mag) // 10**off

   return num % 10
