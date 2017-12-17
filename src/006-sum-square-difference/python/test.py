import unittest
import solve

class TestSolution(unittest.TestCase):
    def test_solve(self):
        self.assertEqual(solve.solve(10), 2640)

if __name__ == '__main__':
    unittest.main()
