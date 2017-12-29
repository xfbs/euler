import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(1), 2)
      self.assertEqual(solver.solve(2), 4)
      self.assertEqual(solver.solve(3), 8)
      self.assertEqual(solver.solve(4), 1+6)
      self.assertEqual(solver.solve(5), 3+2)
      self.assertEqual(solver.solve(6), 6+4)
      self.assertEqual(solver.solve(7), 1+2+8)
      self.assertEqual(solver.solve(8), 2+5+6)
      self.assertEqual(solver.solve(9), 5+1+2)
