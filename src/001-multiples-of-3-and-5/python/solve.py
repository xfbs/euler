def gcd(a, b):
   while b != 0:
      t = b
      b = a % t
      a = t
   return a

def lcm(a, b):
   return a / gcd(a, b) * b

def sum_divisible(m, n):
   m = m - (m % n)
   return m * ((m / n) + 1) / 2

def solve(m, a, b):
   return sum_divisible(m, a) + sum_divisible(m, b) - sum_divisible(m, lcm(a, b))

if __name__ == '__main__':
    # solution to problem
    print solve(1000, 3, 5)
