from fibonacci import Fibonacci

# solution
def solve(length):
   fibo = Fibonacci()
   do = True
   counter = 1
   while do:
      cur = fibo.next()
      counter += 1
      if len(str(cur)) >= length:
         do = False
   return counter
