class CollatzLength:
   def __init__(self):
      self.cache = {}
      self.cache[1] = 1

   def len(self, num):
      add = 0

      while num > 1 and (num % 2) == 0:
         num //= 2
         add += 1

      if num in self.cache:
         return add + self.cache[num]
      else:
         length = 2 + add + self.len((3 * num + 1) // 2)

         self.cache[num] = length - add

         return length

   def longest(self, m):
      res = 1
      cur = 1
      for n in range(m, 1, -1):
         l = self.len(n)
         if l > cur:
            res = n
            cur = l
      return res

def solve(m):
   return CollatzLength().longest(m)
