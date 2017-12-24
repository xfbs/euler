import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve([2, 3, 4]), 12)
      self.assertEqual(solver.solve([5, 15]), 15)
      self.assertEqual(solver.solve([3, 9, 10]), 90)
      self.assertEqual(solver.solve(range(1, 4)), 6)

