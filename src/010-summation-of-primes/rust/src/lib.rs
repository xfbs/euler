mod sieve;
use sieve::sieve;

pub fn solve(n: u64) -> u64 {
    let primes = sieve(n);

    primes.iter()
        .filter(|&p| *p < n)
        .fold(0, |s,n| s+n)
}

#[test]
fn test_solve() {
    assert!(solve(10) == 2+3+5+7);
    assert!(solve(20) == 2+3+5+7+11+13+17+19);
    assert!(solve(30) == 2+3+5+7+11+13+17+19+23+29);
}
