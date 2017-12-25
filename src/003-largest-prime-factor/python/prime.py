import math

class Prime(object):
   def __init__(self):
      self.primes = [2, 3]
      self.prime  = 3

   def check(self, prime):
      root = math.sqrt(prime)
      for d in self.primes:
         if d > root:
            return True
         if (prime % d) == 0:
            return False
      return True

   def next(self):
      # find next prime
      self.prime += 2
      while not self.check(self.prime):
         self.prime += 2

      self.primes.append(self.prime)
      return self.primes[-1]

   def nth(self, n):
      while len(self.primes) <= n:
         self.next()
      return self.primes[n]

   def iter(self):
      for p in self.primes:
         yield p
      while True:
         yield self.next()

# generator function for primes
def iter():
   return Prime().iter()

