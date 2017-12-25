def palindrome(num):
   rev = 0
   cur = num

   while cur != 0:
      rev *= 10
      rev += cur % 10
      cur //= 10

   return rev == num

def solve(m):
   # minimum number factor to consider
   s = 10**(m-1)
   e = s * 10
   largest = 0

   # for all factors s <= a < e
   for a in range(s, e):
      # for all factors a <= b < e (larger than or equal to a to avoid
      # duplications)
      for b in range(a, e):
         product = a * b
         if palindrome(product):
            if product > largest:
               largest = product

   return largest
