import unittest
import sieve

class TestSolution(unittest.TestCase):
   def test_iter(self):
      i = sieve.iter(10)
      self.assertEqual(next(i), 2)
      self.assertEqual(next(i), 3)
      self.assertEqual(next(i), 5)
      self.assertEqual(next(i), 7)

      i = sieve.iter(11)
      self.assertEqual(next(i), 2)
      self.assertEqual(next(i), 3)
      self.assertEqual(next(i), 5)
      self.assertEqual(next(i), 7)
      self.assertEqual(next(i), 11)

      i = sieve.iter(20)
      self.assertEqual(next(i), 2)
      self.assertEqual(next(i), 3)
      self.assertEqual(next(i), 5)
      self.assertEqual(next(i), 7)
      self.assertEqual(next(i), 11)
      self.assertEqual(next(i), 13)
      self.assertEqual(next(i), 17)
      self.assertEqual(next(i), 19)

   def test_iter_max(self):
      for max in [13, 34, 55, 123]:
         for p in sieve.iter(max):
            self.assertTrue(p <= max)
