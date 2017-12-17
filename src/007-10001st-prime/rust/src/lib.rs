mod prime_sieve;
use prime_sieve::sieve;

pub fn solve(nth: u64) -> u64 {
    sieve(nth + 1)
}

