import math

def solve(nums):
   cur = nums[0]

   for num in nums:
      cur *= num // math.gcd(cur, num)

   return cur

