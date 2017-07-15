class fibonacci():
   fibo = []
   def __init__(self, fibo=[1,1]):
      self.fibo = fibo
   
   def next(self):
      self.fibo.append(self.fibo[-2] + self.fibo[-1])
      return self.fibo[-1]

fibona = fibonacci()
do = True
counter = 2
while do:
   fibo = fibona.next()
   counter += 1
   if len(str(fibo)) >= 1000:
      do = False

