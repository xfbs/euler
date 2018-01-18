def solve(names):
   names.sort()
   return sum(map(lambda pos_name: (1 + pos_name[0]) * worth(pos_name[1]),
      enumerate(names)))

def worth(name):
   return sum(map(lambda c: ord(c) - ord('A') + 1, list(name)))

