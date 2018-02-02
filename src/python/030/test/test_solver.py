import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(4), 1634+8208+9474)

   def test_digit_power_sum(self):
      self.assertTrue(solver.digit_power_sum([0, 0, 1, 2, 3, 4], 1234))
      self.assertTrue(solver.digit_power_sum([0, 0, 1, 2, 3, 4], 4231))
      self.assertTrue(solver.digit_power_sum([0, 0, 2, 2, 4, 5], 4252))

      self.assertFalse(solver.digit_power_sum([0, 0, 1, 2, 3, 4], 43212))
      self.assertFalse(solver.digit_power_sum([0, 0, 1, 2, 3, 4], 3251))
