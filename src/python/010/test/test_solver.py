import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(10), 2+3+5+7)
      self.assertEqual(solver.solve(20), 2+3+5+7+11+13+17+19)
      self.assertEqual(solver.solve(32), 2+3+5+7+11+13+17+19+23+29+31)
