import unittest
import solver

class TestSolution(unittest.TestCase):
    def test_solve(self):
       self.assertEqual(solver.solve(1, 1), 1)
       self.assertEqual(solver.solve(2, 1), 5)
       self.assertEqual(solver.solve(3, 1), 2)
       self.assertEqual(solver.solve(3, 2), 32)
       self.assertEqual(solver.solve(4, 1), 8)
       self.assertEqual(solver.solve(4, 2), 88)
       self.assertEqual(solver.solve(4, 3), 288)
