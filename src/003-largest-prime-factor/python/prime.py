import math

def check(primes, prime):
   root = math.sqrt(prime)
   for d in primes:
      if d > root:
         return True
      if (prime % d) == 0:
         return False

   return True

# generator function for primes
def iter():
   # the only even prime number
   yield 2

   primes = [2]
   prime = 3

   while True:
      # yield current prime number
      yield prime
      primes.append(prime)

      # find next prime
      prime += 2
      while not check(primes, prime):
         prime += 2

