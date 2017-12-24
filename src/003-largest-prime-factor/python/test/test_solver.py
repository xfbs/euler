import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(10), 5)
      self.assertEqual(solver.solve(15), 5)
      self.assertEqual(solver.solve(20), 5)
      self.assertEqual(solver.solve(9), 3)
      self.assertEqual(solver.solve(91), 13)
      self.assertEqual(solver.solve(323), 19)

