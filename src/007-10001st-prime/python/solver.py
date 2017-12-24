import euler.prime

def solve(n):
   primes = euler.prime.iter()

   for _ in range(n-1):
      next(primes)

   return next(primes)
