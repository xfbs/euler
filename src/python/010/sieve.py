def iter(m):
   # generate sieve, half the size of m because we know all odd numbers apart
   # from 2 are not prime.
   nums = [True for _ in range((m + 1) // 2)]

   # 1 is not prime
   nums[0] = False

   p = 3
   p2 = p**2

   # for every prime such that p^2 < m
   while p2 < m:
      # check off all multiples
      for n in range(p**2, m, 2*p):
         nums[(n - 1) // 2] = False

      p += 2
      while not nums[(p - 1) // 2]:
         p += 2

      p2 = p**2

   yield 2
   for num, prim in enumerate(nums):
      if prim:
         yield 2 * num + 1

