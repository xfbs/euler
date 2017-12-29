require "minitest/autorun"
require "euler/prime"

class PrimeTest < Minitest::Test
  def test_check
    primes = Euler::Prime.new
    assert primes.check? 2
    assert primes.check? 3
    assert primes.check? 5
    assert primes.check? 7
    assert primes.check? 11
    assert primes.check? 13
    assert primes.check? 17
    assert primes.check? 19
    assert primes.check? 23
    assert primes.check? 29
    assert primes.check? 29

    assert !primes.check? 4
    assert !primes.check? 6
    assert !primes.check? 8
    assert !primes.check? 9
    assert !primes.check? 10
    assert !primes.check? 12
    assert !primes.check? 15
    assert !primes.check? 21
    assert !primes.check? 25
    assert !primes.check? 27
    assert !primes.check? 33
  end
end
