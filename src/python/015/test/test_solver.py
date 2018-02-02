import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(4), 70)

   def test_collatz(self):
      c = solver.LatticePaths(12, 12)
      self.assertEqual(c.count(0, 1), 1)
      self.assertEqual(c.count(0, 5), 1)
      self.assertEqual(c.count(9, 0), 1)
      self.assertEqual(c.count(7, 0), 1)
      self.assertEqual(c.count(2, 0), 1)

      self.assertEqual(c.count(1, 1), 2)
      self.assertEqual(c.count(1, 5), 6)
      self.assertEqual(c.count(9, 1), 10)
      self.assertEqual(c.count(7, 1), 8)
      self.assertEqual(c.count(2, 1), 3)

      self.assertEqual(c.count(2, 2), 6)
      self.assertEqual(c.count(2, 3), 10)
      self.assertEqual(c.count(3, 2), 10)
      self.assertEqual(c.count(5, 3), 56)
      self.assertEqual(c.count(4, 4), 70)

      self.assertEqual(c.count(4, 6), 210)
      self.assertEqual(c.count(5, 5), 252)
      self.assertEqual(c.count(8, 4), 495)
      self.assertEqual(c.count(5, 7), 792)
