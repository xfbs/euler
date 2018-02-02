import euler.prime

def is_pythagorean_triplet(a, b, c):
   if b <= a:
      return False
   if c <= b:
      return False
   if a**2 + b**2 != c**2:
      return False
   return True

def solve(n):
   for c in range(1, n):
      for b in range(1, c):
         a = n - b - c
         if is_pythagorean_triplet(a, b, c):
            return a * b * c
