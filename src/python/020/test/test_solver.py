import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(1), 1)
      self.assertEqual(solver.solve(2), 2)
      self.assertEqual(solver.solve(3), 6)
      self.assertEqual(solver.solve(4), 2+4)
      self.assertEqual(solver.solve(5), 1+2+0)
      self.assertEqual(solver.solve(6), 7+2+0)
      self.assertEqual(solver.solve(7), 5+0+4+0)
      self.assertEqual(solver.solve(8), 4+0+3+2+0)
      self.assertEqual(solver.solve(9), 3+6+2+8+8+0)
