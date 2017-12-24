import unittest
import fibonacci

class TestFibonacci(unittest.TestCase):
   def test_nth(self):
      self.assertEqual(fibonacci.nth(0), 0)
      self.assertEqual(fibonacci.nth(1), 1)
      self.assertEqual(fibonacci.nth(2), 1)
      self.assertEqual(fibonacci.nth(3), 2)
      self.assertEqual(fibonacci.nth(4), 3)
      self.assertEqual(fibonacci.nth(5), 5)
      self.assertEqual(fibonacci.nth(6), 8)
      self.assertEqual(fibonacci.nth(7), 13)
      self.assertEqual(fibonacci.nth(8), 21)
      self.assertEqual(fibonacci.nth(9), 34)
      self.assertEqual(fibonacci.nth(10), 55)

