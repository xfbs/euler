class Fibonacci():
   def __init__(self):
      self.fibo_a = 0
      self.fibo_b = 1

   def next(self):
      t = self.fibo_a
      self.fibo_a = self.fibo_b
      self.fibo_b = self.fibo_b + t
      return self.fibo_b
