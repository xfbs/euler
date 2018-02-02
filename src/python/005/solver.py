import euler

def solve(nums):
   cur = nums[0]

   for num in nums:
      cur *= num // euler.gcd(cur, num)

   return cur

