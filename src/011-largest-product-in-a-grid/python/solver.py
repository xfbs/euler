def max_product(grid, direction, length):
   dx, dy = direction
   maxp = 0

   for x in range(0, len(grid)):
      for y in range(0, len(grid[x])):
         product = 1
         for c in range(0, length):
            cur_x = x + c * dx
            cur_y = y + c * dy

            if cur_x >= 0 and cur_x < len(grid):
               if cur_y >= 0 and cur_y < len(grid[cur_x]):
                  product *= grid[cur_x][cur_y]
               else:
                  product = 0
            else:
               product = 0
         if product > maxp:
            maxp = product

   return maxp


def solve(grid, l):
   return max(map(lambda d: max_product(grid, d, l), [(1,0), (0,1), (1,1),
      (1,-1)]))
