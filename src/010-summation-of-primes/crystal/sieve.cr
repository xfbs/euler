# Compute prime numbers up to 100 with the Sieve of Eratosthenes
max = 1000000

sieve = Array.new(max + 1, true)
sieve[0] = false
sieve[1] = false

(2..Math.sqrt(max)).each do |i|
  if sieve[i]
    ((i * i)..max).step(i) do |j|
      sieve[j] = false
    end
  end
end

sum = 0.to_u64
sieve.each_with_index do |prime, number|
  if prime
    sum += number
  end
end

puts sum
gets
sieve.each_with_index do |prime, number|
  if prime
    puts number
  end
end
