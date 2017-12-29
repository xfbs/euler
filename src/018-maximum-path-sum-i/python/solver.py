def triangle_reduce(triangle):
   last = triangle.pop()

   for i, n in enumerate(triangle[-1]):
      if last[i] > last[i+1]:
         triangle[-1][i] = triangle[-1][i] + last[i]
      else:
         triangle[-1][i] = triangle[-1][i] + last[i+1]

   return triangle


def solve(triangle):
   while len(triangle) > 1:
      triangle = triangle_reduce(triangle)

   return triangle[0][0]
