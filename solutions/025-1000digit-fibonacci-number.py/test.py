import unittest
import solution

class TestFibonacci(unittest.TestCase):
   def test_fibonacci(self):
      fibo = solution.Fibonacci()
      self.assertEqual(fibo.next(), 2)
      self.assertEqual(fibo.next(), 3)
      self.assertEqual(fibo.next(), 5)

class TestSolution(unittest.TestCase):
    # test the solution function
    def test_solution(self):
        self.assertEqual(solution.solve(3), 12)

if __name__ == '__main__':
    unittest.main()
