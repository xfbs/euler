import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(2), 9009)

   def test_palindrome(self):
      self.assertEqual(solver.palindrome(86), (8668, 868))
      self.assertEqual(solver.palindrome(456), (456654, 45654))
      self.assertEqual(solver.palindrome(9123), (91233219, 9123219))

   def test_factorizable(self):
      self.assertEqual(solver.factorizable(234 * 345, 234, 345), True)
      self.assertEqual(solver.factorizable(234 * 345, 23, 34), False)
      self.assertEqual(solver.factorizable(999999, 100, 999), False)

