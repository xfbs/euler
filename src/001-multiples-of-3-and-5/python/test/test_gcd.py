import unittest
import euler

class TestGCD(unittest.TestCase):
   def test_gcd(self):
      self.assertEqual(euler.gcd(3, 5), 1)
      self.assertEqual(euler.gcd(5, 13), 1)
      self.assertEqual(euler.gcd(2, 10), 2)
      self.assertEqual(euler.gcd(5, 10), 5)
      self.assertEqual(euler.gcd(10, 25), 5)
