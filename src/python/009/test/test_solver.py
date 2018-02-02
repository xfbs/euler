import unittest
import solver

class TestSolver(unittest.TestCase):
   def test_is_pythagorean_triplet(self):
      self.assertEqual(solver.is_pythagorean_triplet(3, 4, 5), True)
      self.assertEqual(solver.is_pythagorean_triplet(3, 4, 6), False)
      self.assertEqual(solver.is_pythagorean_triplet(4, 3, 5), False)

   def test_solve(self):
      self.assertEqual(solver.solve(12), 60)
