import unittest
import solver

class TestSolution(unittest.TestCase):
    def test_solve(self):
        self.assertEqual(solver.solve(1), 2)
        self.assertEqual(solver.solve(2), 3)
        self.assertEqual(solver.solve(3), 5)
        self.assertEqual(solver.solve(4), 7)
        self.assertEqual(solver.solve(5), 11)
        self.assertEqual(solver.solve(6), 13)
