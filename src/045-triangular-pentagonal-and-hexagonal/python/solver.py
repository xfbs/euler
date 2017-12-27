def triangular(n):
   return n * (n + 1) // 2

def pentagonal(n):
   return n * (3 * n - 1) // 2

def hexagonal(n):
   return n * (2 * n - 1)

def solve(t, p, h):
   tt = triangular(t)
   pp = pentagonal(p)
   hh = hexagonal(h)

   while True:
      is_triangular = False
      is_pentagonal = False
      h += 1
      hh = hexagonal(h)

      while tt <= hh:
         t += 1
         tt = triangular(t)
         if tt == hh:
            is_triangular = True

      while pp <= hh:
         p += 1
         pp = pentagonal(p)
         if pp == hh:
            is_pentagonal = True

      if is_triangular and is_pentagonal:
         return hh
