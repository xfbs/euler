import unittest
import solver

class TestSolution(unittest.TestCase):
   def test_solve(self):
      grid = [[1,2,3,4],[2,3,5,7],[3,4,5,6],[4,5,6,7]]
      self.assertEqual(solver.solve(grid, 1), 7);
      self.assertEqual(solver.solve(grid, 2), 6 * 7);
      self.assertEqual(solver.solve(grid, 3), 7 * 6 * 7);
      self.assertEqual(solver.solve(grid, 4), 4 * 7 * 6 * 7);

   def test_max_product(self):
      grid = [[1,2,3,4],[2,3,5,7],[3,4,5,6],[4,5,6,7]]

      self.assertEqual(solver.max_product(grid, (1, 0), 1), 7)
      self.assertEqual(solver.max_product(grid, (1, 0), 2), 7 * 6)
      self.assertEqual(solver.max_product(grid, (1, 0), 3), 7 * 6 * 7)
      self.assertEqual(solver.max_product(grid, (1, 0), 4), 4 * 7 * 6 * 7)
      self.assertEqual(solver.max_product(grid, (1, 0), 5), 0)

      self.assertEqual(solver.max_product(grid, (0, 1), 1), 7)
      self.assertEqual(solver.max_product(grid, (0, 1), 2), 6 * 7)
      self.assertEqual(solver.max_product(grid, (0, 1), 3), 5 * 6 * 7)
      self.assertEqual(solver.max_product(grid, (0, 1), 4), 4 * 5 * 6 * 7)
      self.assertEqual(solver.max_product(grid, (0, 1), 5), 0)

      self.assertEqual(solver.max_product(grid, (1, 1), 1), 7)
      self.assertEqual(solver.max_product(grid, (1, 1), 2), 5 * 7)
      self.assertEqual(solver.max_product(grid, (1, 1), 3), 3 * 5 * 7)
      self.assertEqual(solver.max_product(grid, (1, 1), 4), 1 * 3 * 5 * 7)
      self.assertEqual(solver.max_product(grid, (1, 1), 5), 0)

      self.assertEqual(solver.max_product(grid, (1, -1), 1), 7)
      self.assertEqual(solver.max_product(grid, (1, -1), 2), 6 * 6)
      self.assertEqual(solver.max_product(grid, (1, -1), 3), 5 * 5 * 7)
      self.assertEqual(solver.max_product(grid, (1, -1), 4), 4 * 5 * 4 * 4)
      self.assertEqual(solver.max_product(grid, (1, -1), 5), 0)
