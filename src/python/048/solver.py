def solve(n, e):
   m = 10**e
   return sum(map(lambda x: pow(x, x, m), range(1, n+1))) % m
