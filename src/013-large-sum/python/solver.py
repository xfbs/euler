def solve(numbers):
   sum = 0

   for number in numbers:
      sum += int(number[0:11])

   return int(str(sum)[0:10])
