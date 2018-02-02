import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(3), 25)
      self.assertEqual(solver.solve(5), 101)
