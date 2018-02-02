import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(2, 2), 1)
      self.assertEqual(solver.solve(3, 3), 4)
      self.assertEqual(solver.solve(5, 5), 15)
