import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      # valid: product of empty sequence is 1
      self.assertEqual(solver.solve("", 0), 1)
      self.assertEqual(solver.solve("1", 0), 1)
      self.assertEqual(solver.solve("12", 0), 1)
      self.assertEqual(solver.solve("123", 0), 1)
      self.assertEqual(solver.solve("1232407128923", 0), 1)
      self.assertEqual(solver.solve("000", 0), 1)

      # invalid: string empty
      self.assertEqual(solver.solve("", 1), 0)
      self.assertEqual(solver.solve("", 2), 0)
      self.assertEqual(solver.solve("", 3), 0)
      self.assertEqual(solver.solve("", 4), 0)

      # invalid: string too short
      self.assertEqual(solver.solve("123", 4), 0)
      self.assertEqual(solver.solve("123242", 10), 0)
      self.assertEqual(solver.solve("1", 4), 0)
      self.assertEqual(solver.solve("122341863", 12), 0)

      # valid
      self.assertEqual(solver.solve("123", 3), 6)
      self.assertEqual(solver.solve("123012340123", 4), 1*2*3*4)
      self.assertEqual(solver.solve("097549087249983", 3), 9*9*8)
      self.assertEqual(solver.solve("123456789", 7), 9*8*7*6*5*4*3)

      # embedded zeroes
      self.assertEqual(solver.solve("99099099", 3), 0)
      self.assertEqual(solver.solve("99099099", 3), 0)
      self.assertEqual(solver.solve("990990990", 3), 0)
      self.assertEqual(solver.solve("934191012", 7), 0)
