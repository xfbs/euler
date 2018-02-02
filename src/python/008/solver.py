# for a sequence of digits (represented as string), find the subsequence of the
# given length with the largest product and return that product.
def solve(sequence, length):
   digits = []
   for digit in sequence:
      digits.append(int(digit))

   # step one: find the earliest sequence of non-zero numbers with the
   # specified length. offset denotes the start of this sequence. product is
   # the product of the numbers in this sequence.
   offset = 0
   product = 1
   for i, d in enumerate(digits):
      # if the subsequence we found is length long, we're done.
      if (i - offset) == length:
         break
      if d == 0:
         # if the digit is zero, everything we got so far is invalid, so we set
         # the start of the sequence to the next iteration and reset product.
         offset = i + 1
         product = 1
      else:
         product *= d

   # step two: iterate through the rest of the sequence. when we encounter
   # zeroes, we flag this by raising the zeroes counter until we have moved
   # past the zero, and ignoring the product until then. we keep track of the
   # biggest products seen in max.
   zeroes = 0
   max = product
   for i in range(len(digits) - length - offset):
      out = digits[i + offset]
      cur = digits[i + offset + length]

      if out == 0:
         zeroes += 1
      else:
         product //= out

      if cur == 0:
         zeroes -= 1
      else:
         product *= cur

      if zeroes == 0 and product > max:
         max = product

   if (len(digits) - offset) < length:
      return 0
   else:
      return max
