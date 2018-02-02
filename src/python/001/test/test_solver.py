import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_sum_divisible(self):
      self.assertEqual(solver.sum_divisible(10, 2), 2+4+6+8+10)
      self.assertEqual(solver.sum_divisible(10, 3), 3+6+9)
      self.assertEqual(solver.sum_divisible(11, 5), 5+10)

   def test_lcm(self):
      self.assertEqual(solver.lcm(10, 15), 30)
      self.assertEqual(solver.lcm(20, 10), 20)
      self.assertEqual(solver.lcm(5, 7), 35)

   def test_solve(self):
      self.assertEqual(solver.solve(10, 2, 3), 2+4+6+8+10+3+9)
      self.assertEqual(solver.solve(10, 5, 3), 3+5+6+9+10)
