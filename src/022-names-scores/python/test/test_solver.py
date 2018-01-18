import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_worth(self):
      self.assertEqual(solver.worth("A"), 1)
      self.assertEqual(solver.worth("Z"), 26)
      self.assertEqual(solver.worth("COLIN"), 53)

   def test_solve(self):
      self.assertEqual(solver.solve(["A", "Z", "COLIN"]), 1*1 + 2*53 + 3*26)
