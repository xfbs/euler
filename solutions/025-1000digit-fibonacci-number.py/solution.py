# fibonacci class - generates fibonacci sequence numbers
class Fibonacci():
   def __init__(self):
      self.fibo = [1, 1]

   def next(self):
      self.fibo.append(self.fibo[-2] + self.fibo[-1])
      return self.fibo[-1]

# solution
def solve(length):
   fibo = Fibonacci()
   do = True
   counter = 2
   while do:
      cur = fibo.next()
      counter += 1
      if len(str(cur)) >= length:
         do = False
   return counter

if __name__ == '__main__':
    # solution to problem
    print solve(1000)
