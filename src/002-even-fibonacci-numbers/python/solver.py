import fibonacci

def even_fibonacci(m):
   cur = 0
   fib = fibonacci.nth(cur)
   while fib < m:
      yield fib
      cur += 3
      fib = fibonacci.nth(cur)

def solve(m):
   return sum(even_fibonacci(m))
