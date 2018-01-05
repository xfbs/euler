def solve(value):
   coins = [200, 100, 50, 20, 10, 5, 2, 1]
   return change(coins, value)

def change(coins, value, pos=0):
   if value == 0 or (pos+1) == len(coins):
      return 1 if value % coins[-1] == 0 else 0
   possibilities = range(0, value//coins[pos] + 1)
   return sum(map(lambda n: change(coins, value-n*coins[pos], pos + 1), possibilities))
