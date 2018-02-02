import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(22, solver.solve([[11], [11, 10]]))
      self.assertEqual(23, solver.solve([[10], [12, 13]]))
      self.assertEqual(65, solver.solve([[10], [50, 9], [5, 4, 10]]))

   def test_reduce(self):
      self.assertEqual([[22]], solver.triangle_reduce([[11], [11, 10]]))
      self.assertEqual([[36]], solver.triangle_reduce([[23], [12, 13]]))
      self.assertEqual([[10], [55, 19]], solver.triangle_reduce([[10], [50, 9],
         [5, 4, 10]]))
