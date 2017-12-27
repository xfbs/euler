class LatticePaths:
   def __init__(self, x, y):
      self.cache = [[0 for _ in range(y)] for _ in range(x)]
   def count(self, x, y):
      if x > y:
         x, y = y, x
      if x == 0:
         return 1
      if x == 1:
         return y + 1
      if x < len(self.cache) and y < len(self.cache[x]):
         if self.cache[x][y] != 0:
            return self.cache[x][y]
      res = self.count(x-1, y) + self.count(x, y-1)
      if x < len(self.cache) and y < len(self.cache[x]):
         self.cache[x][y] = res
      return res

def solve(xy):
   return LatticePaths(xy, xy).count(xy, xy)
