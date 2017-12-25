import unittest
import solver

class TestSolution(unittest.TestCase):
    def test_solve(self):
       self.assertEqual(solver.solve(1), 3)
       self.assertEqual(solver.solve(2), 6)
       self.assertEqual(solver.solve(3), 6)
       self.assertEqual(solver.solve(4), 28)
