extern crate euler;
use euler::Prime;
use euler::ToDigits;

pub fn solve(count: usize) -> u64 {
    // I had to use two prime generators here, because I can't mutibly borrow
    // one twice.. maybe this could be fixed somehow?
    let mut primes = Prime::new();
    let mut other = Prime::new();

    primes
        .into_iter()
        .skip(4)
        .filter(|&n| is_truncatable(&mut other, n))
        .take(count)
        .sum()
}

/// Checks if a prime number is truncatable from both sides.
///
/// # Examples
///
/// ```
/// # extern crate euler;
/// # extern crate solver;
/// # use euler::Prime;
/// # use solver::is_truncatable;
/// # fn main() {
/// let mut primes = Prime::new();
/// assert!(is_truncatable(&mut primes, 23));
/// assert!(!is_truncatable(&mut primes, 17));
/// # }
/// ```
pub fn is_truncatable(primes: &mut Prime, prime: u64) -> bool {
    let right = prime
        .digits()
        .scan(0, |memo, digit| {
            *memo *= 10;
            *memo += digit;
            Some(*memo)
        })
        .all(|n| primes.check(n));

    let left = prime
        .digits()
        .reverse()
        .scan((0, 1), |memo, digit| {
            memo.0 += memo.1 * digit;
            memo.1 *= 10;
            Some(memo.0)
        })
        .all(|n| primes.check(n));

    right && left
}

#[test]
fn test_is_truncatable() {
    let mut primes = Prime::new();

    assert!(is_truncatable(&mut primes, 3797));
    assert!(is_truncatable(&mut primes, 23));
    assert!(!is_truncatable(&mut primes, 2141));
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 23);
}
