import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_champernowne(self):
      self.assertEqual(solver.champernowne_digit(0), 1)
      self.assertEqual(solver.champernowne_digit(1), 2)
      self.assertEqual(solver.champernowne_digit(2), 3)
      self.assertEqual(solver.champernowne_digit(3), 4)
      self.assertEqual(solver.champernowne_digit(4), 5)
      self.assertEqual(solver.champernowne_digit(5), 6)
      self.assertEqual(solver.champernowne_digit(6), 7)
      self.assertEqual(solver.champernowne_digit(7), 8)
      self.assertEqual(solver.champernowne_digit(8), 9)
      self.assertEqual(solver.champernowne_digit(9), 1)
      self.assertEqual(solver.champernowne_digit(10), 0)
      self.assertEqual(solver.champernowne_digit(11), 1)
      self.assertEqual(solver.champernowne_digit(12), 1)
      self.assertEqual(solver.champernowne_digit(13), 1)
      self.assertEqual(solver.champernowne_digit(14), 2)

   def test_solve(self):
      self.assertEqual(solver.solve(1), 1)
      self.assertEqual(solver.solve(2), 1)
      self.assertEqual(solver.solve(3), 5)
      self.assertEqual(solver.solve(4), 15)
