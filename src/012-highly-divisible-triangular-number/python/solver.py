from euler.prime import Prime

def factors(primes, num):
   count = 1

   for prime in primes:
      factors = 1

      while (num % prime) == 0:
         num //= prime
         factors += 1

      count *= factors

      if num == 1:
         break

   return count

def solve(n):
   triangle = 1
   index = 1
   primes = Prime()

   while factors(primes.iter(), triangle) <= n:
      index += 1
      triangle += index

   return triangle
