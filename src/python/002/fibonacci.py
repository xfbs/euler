import math

# phi - the golden ration
PHI = (1 + math.sqrt(5)) / 2

# the root of five, we need this a lot
ROOT5 = math.sqrt(5)

# returns the nth fibonacci number
def nth(n):
   return round((PHI**n) / ROOT5)

