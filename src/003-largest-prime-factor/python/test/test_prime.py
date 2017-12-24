import unittest
import prime

class TestPrime(unittest.TestCase):
   def test_iter(self):
      i = prime.iter()
      self.assertEqual(next(i), 2)
      self.assertEqual(next(i), 3)
      self.assertEqual(next(i), 5)
      self.assertEqual(next(i), 7)
      self.assertEqual(next(i), 11)
      self.assertEqual(next(i), 13)
      self.assertEqual(next(i), 17)
      self.assertEqual(next(i), 19)
      self.assertEqual(next(i), 23)
      self.assertEqual(next(i), 29)
      self.assertEqual(next(i), 31)
      self.assertEqual(next(i), 37)

