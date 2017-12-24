import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_even_fibonacci(self):
      for even in solver.even_fibonacci(1000):
         self.assertTrue((even % 2) == 0)

   def test_solve(self):
      self.assertEqual(solver.solve(100), 0+2+8+34)

