import math

class Prime(object):
   def __init__(self):
      self.primes = [2]
      self.prime  = 2

   def check(self, prime):
      root = math.sqrt(prime)
      for d in self.primes:
         if d > root:
            return True
         if (prime % d) == 0:
            return False
      return True

   def next(self):
      if self.prime == 2:
         self.prime = 3
         return 2
      self.primes.append(self.prime)

      # find next prime
      self.prime += 2
      while not self.check(self.prime):
         self.prime += 2

      return self.primes[-1]

   def nth(self, n):
      while len(self.primes) < n:
         self.next()
      return self.primes[n-1]

# generator function for primes
def iter():
   p = Prime()
   while True:
      yield p.next()

