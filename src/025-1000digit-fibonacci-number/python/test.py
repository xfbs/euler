import unittest
import solve

class TestFibonacci(unittest.TestCase):
   def test_fibonacci(self):
      fibo = solve.Fibonacci()
      self.assertEqual(fibo.next(), 1)
      self.assertEqual(fibo.next(), 2)
      self.assertEqual(fibo.next(), 3)
      self.assertEqual(fibo.next(), 5)
      self.assertEqual(fibo.next(), 8)

class TestSolution(unittest.TestCase):
    # test the solution function
    def test_solution(self):
        self.assertEqual(solve.solve(3), 12)

if __name__ == '__main__':
    unittest.main()
