import unittest
import solver

class TestSolution(unittest.TestCase):
    def test_solve(self):
       self.assertEqual(solver.solve(["123", "234"]), 357)
       self.assertEqual(solver.solve(["213563345435254532"]), 2135633454)
