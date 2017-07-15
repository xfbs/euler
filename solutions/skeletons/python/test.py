import unittest
import solution

class TestStringMethods(unittest.TestCase):
    # test the solution function
    def test_solution(self):
        self.assertEqual(solution.solve(0), 0)

    # FIXME
    def test_fail(self):
        self.assertTrue(False)

if __name__ == '__main__':
    unittest.main()
