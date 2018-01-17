def solve(a, b):
   exponents = set()
   for a in range(2, a + 1):
      for b in range(2, b + 1):
         exp = a**b

         if exp not in exponents:
            exponents.add(exp)

   return len(exponents)
