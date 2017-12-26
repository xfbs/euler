import unittest
import fibonacci

class TestFibonacci(unittest.TestCase):
   def test_fibonacci(self):
      fibo = fibonacci.Fibonacci()
      self.assertEqual(fibo.next(), 1)
      self.assertEqual(fibo.next(), 2)
      self.assertEqual(fibo.next(), 3)
      self.assertEqual(fibo.next(), 5)
      self.assertEqual(fibo.next(), 8)
