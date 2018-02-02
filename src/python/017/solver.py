def teens_number_word(n):
   lengths = {
      1:  3, # one
      2:  3, # two
      3:  5, # three
      4:  4, # four
      5:  4, # five
      6:  3, # six
      7:  5, # seven
      8:  5, # eight
      9:  4, # nine
      10: 3, # ten
      11: 6, # eleven
      12: 6, # twelve
      13: 8, # thirteen
      14: 8, # fourteen
      15: 7, # fifteen
      16: 7, # sixteen
      17: 9, # seventeen
      18: 8, # eighteen
      19: 8, # nineteen
      20: 6, # twenty
      30: 6, # thirty
      40: 5, # forty
      50: 5, # fifty
      60: 5, # sixty
      70: 7, # seventy
      80: 6, # eighty
      90: 6} # ninety

   other = 0
   while lengths.get(n) == None:
      other += 1
      n -= 1

   n = lengths.get(n)
   if other != 0:
      n += teens_number_word(other)
   return n

def hundreds_number_word(n):
   hunnies = n // 100
   teens   = n % 100
   result  = 0

   if hunnies > 0:
      result += teens_number_word(hunnies) + 7
   if teens > 0:
      result += teens_number_word(teens)
   if hunnies > 0 and teens > 0:
      result += 3
   return result

def thousands_number_word(n):
   hunnies = n // 1000
   teens   = n % 1000
   result  = 0

   if hunnies > 0:
      result += hundreds_number_word(hunnies) + 8
   if teens > 0:
      result += hundreds_number_word(teens)
   return result

def solve(m):
   return sum(map(thousands_number_word, range(1, m+1)))
