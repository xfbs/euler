import unittest
import solver

class TestSolution(unittest.TestCase):
    # test the solution function
    def test_solution(self):
        self.assertEqual(solver.solve(3), 12)
