def solve(m):
   total = pow(2, m)

   digits = 0
   while total > 0:
      digits += total % 10
      total //= 10

   return digits
