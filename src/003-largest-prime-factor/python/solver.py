import prime

def solve(m):
   for p in prime.iter():
      while (m % p) == 0:
         if m == p:
            return m
         m //= p

