import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      self.assertEqual(solver.solve(20), 19)

   def test_collatz(self):
      c = solver.CollatzLength()
      self.assertEqual(c.len(1), 1)
      self.assertEqual(c.len(2), 2)
      self.assertEqual(c.len(5), 6)
      self.assertEqual(c.len(11), 15)
      self.assertEqual(c.len(13), 10)
      self.assertEqual(c.len(19), 21)
      self.assertEqual(c.len(32), 6)
