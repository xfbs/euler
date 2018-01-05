import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_change(self):
      self.assertEqual(solver.change([1], 1), 1)
      self.assertEqual(solver.change([2, 1], 3), 2)
      self.assertEqual(solver.change([5, 2, 1], 5), 4)
      self.assertEqual(solver.change([5, 2, 1], 6), 5)
      self.assertEqual(solver.change([5, 2], 3), 0)
      self.assertEqual(solver.change([5, 2], 4), 1)
      self.assertEqual(solver.change([5, 2], 5), 1)
      self.assertEqual(solver.change([5, 2], 6), 1)
