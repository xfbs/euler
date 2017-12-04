# fibonacci class - generates fibonacci sequence numbers
class Fibonacci():
   def __init__(self):
      self.fibo_a = 0
      self.fibo_b = 1

   def next(self):
      t = self.fibo_a
      self.fibo_a = self.fibo_b
      self.fibo_b = self.fibo_b + t
      return self.fibo_b

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

if __name__ == '__main__':
    # solution to problem
    print solve(1000)
