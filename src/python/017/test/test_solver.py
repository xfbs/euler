import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_teens_number_word(self):
      self.assertEqual(solver.teens_number_word(1), 3)
      self.assertEqual(solver.teens_number_word(5), 4)
      self.assertEqual(solver.teens_number_word(10), 3)
      self.assertEqual(solver.teens_number_word(15), 7)
      self.assertEqual(solver.teens_number_word(25), 10)
      self.assertEqual(solver.teens_number_word(32), 9)
      self.assertEqual(solver.teens_number_word(45), 9)
      self.assertEqual(solver.teens_number_word(78), 12)
      self.assertEqual(solver.teens_number_word(70), 7)
      self.assertEqual(solver.teens_number_word(11), 6)
      self.assertEqual(solver.teens_number_word(81), 9)

   def test_hundreds_number_word(self):
      # fifty-five
      self.assertEqual(9, solver.hundreds_number_word(55))

      # one-hundred
      self.assertEqual(10, solver.hundreds_number_word(100))

      # one hundred and fifty-five
      self.assertEqual(22, solver.hundreds_number_word(155))

      # seven hundred and five
      self.assertEqual(19, solver.hundreds_number_word(705))

      # nine hundred and ninety-four
      self.assertEqual(24, solver.hundreds_number_word(994))

   def test_thousands_number_word(self):
      # one thousand
      self.assertEqual(11, solver.thousands_number_word(1000))

      # one thousand, seven hundred and sixty-four
      self.assertEqual(35, solver.thousands_number_word(1764))

   def test_solve(self):
      self.assertEqual(3, solver.solve(1))

      # one two three four five six seven eight nine ten
      self.assertEqual(39, solver.solve(10))
