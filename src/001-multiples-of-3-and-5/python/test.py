import unittest
import solve

class TestSolution(unittest.TestCase):
   def test_sum_divisible(self):
      self.assertEqual(solve.sum_divisible(10, 2), 2+4+6+8+10)
      self.assertEqual(solve.sum_divisible(10, 3), 3+6+9)
      self.assertEqual(solve.sum_divisible(11, 5), 5+10)

   def test_gcd(self):
      self.assertEqual(solve.gcd(5, 2), 1)
      self.assertEqual(solve.gcd(5, 7), 1)
      self.assertEqual(solve.gcd(5, 15), 5)
      self.assertEqual(solve.gcd(10, 15), 5)

   def test_lcm(self):
      self.assertEqual(solve.lcm(10, 15), 30)
      self.assertEqual(solve.lcm(20, 10), 20)
      self.assertEqual(solve.lcm(5, 7), 35)

   def test_solve(self):
      self.assertEqual(solve.solve(10, 2, 3), 2+4+6+8+10+3+9)
      self.assertEqual(solve.solve(10, 5, 3), 3+5+6+9+10)

if __name__ == '__main__':
    unittest.main()
