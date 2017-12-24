def iter(m):
   nums = [True for _ in range(m)]
   nums[0] = False
   nums[1] = False

   p = 2
   while p**2 < m:
      for n in range(p**2, m, p):
         nums[n] = False

      p += 1
      while not nums[p]:
         p += 1

   for num, prim in enumerate(nums):
      if prim:
         yield num

