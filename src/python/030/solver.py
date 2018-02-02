def solve(power):
   powers = list(map(lambda n: n**power, range(0, 10)))

   total = 0

   for a in range(0, 10):
      for b in range(a, 10):
         for c in range(b, 10):
            for d in range(c, 10):
               for e in range(d, 10):
                  for f in range(e, 10):
                     # digits of the number (sorted)
                     digits = [a, b, c, d, e, f]

                     # power sums of the numebr
                     sums = sum(map(lambda n: powers[n], digits))

                     if digit_power_sum(digits, sums):
                        total += sums
   return total

def digit_power_sum(digits, s):
   if s == 1:
      return False
   else:
      sum_digits = list(map(lambda n: int(n), str(s).rjust(6, '0')))
      sum_digits.sort()

      return sum_digits == digits
