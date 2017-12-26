from fibonacci import Fibonacci

# solution
def solve(length):
   fibo = Fibonacci()
   counter = 2
   while len(str(fibo.next())) < length:
      counter += 1
   return counter
