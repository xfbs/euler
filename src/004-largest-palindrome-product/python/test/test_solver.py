import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(2), 9009)

