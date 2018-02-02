import unittest
import solver

class TestSolution(unittest.TestCase):
   # test the solution function
   def test_solution(self):
      self.assertEqual(solver.solve(2), 7)
      self.assertEqual(solver.solve(3), 12)
      self.assertEqual(solver.solve(4), 17)
      self.assertEqual(solver.solve(5), 21)
      self.assertEqual(solver.solve(6), 26)
      self.assertEqual(solver.solve(7), 31)
      self.assertEqual(solver.solve(8), 36)
