import unittest
import solver

class TestSolution(unittest.TestCase):
    def test_solve(self):
       self.assertEqual(solver.solve(0, 0, 0), 1)
       self.assertEqual(solver.solve(200, 100, 100), 40755)
