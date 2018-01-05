import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_divisor_sum(self):
      self.assertEqual(solver.divisor_sum(2), 1)
      self.assertEqual(solver.divisor_sum(3), 1)
      self.assertEqual(solver.divisor_sum(4), 1+2)
      self.assertEqual(solver.divisor_sum(5), 1)
      self.assertEqual(solver.divisor_sum(6), 1+2+3)
      self.assertEqual(solver.divisor_sum(7), 1)
      self.assertEqual(solver.divisor_sum(8), 1+2+4)
      self.assertEqual(solver.divisor_sum(9), 1+3)
      self.assertEqual(solver.divisor_sum(10), 1+2+5)
      self.assertEqual(solver.divisor_sum(11), 1)
      self.assertEqual(solver.divisor_sum(12), 1+2+3+4+6)

   def test_amicable_pair(self):
      self.assertEqual(solver.amicable_pair(220), (True, 284))
      self.assertEqual(solver.amicable_pair(284), (True, 220))
      self.assertEqual(solver.amicable_pair(285), (False, None))
      self.assertEqual(solver.amicable_pair(221), (False, None))

   def test_solve(self):
      self.assertEqual(solver.solve(10), 0)
      self.assertEqual(solver.solve(20), 0)
      self.assertEqual(solver.solve(285), 220+284)
