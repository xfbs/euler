extern crate euler;
use euler::Prime;

pub fn solve(max: u64) -> u64 {
    let mut prime = Prime::new();

    let (max_len, sum_pre) = max_len_sum(&mut prime, max);
    consecutive_prime_sum(&mut prime, max_len, sum_pre).unwrap()
}

// find the maximum amount of primes you can add up to run short of max,
// and their sum.
fn max_len_sum(prime: &mut Prime, max: u64) -> (usize, u64) {
    let (max_len, sum_pre) = prime.into_iter()
        .enumerate()
        .take_while(|&(_, n)| n < max)
        .fold((0usize, 0u64), |(len, sum), (index, prime)| {
            if (sum + prime) < max {
                (index + 1, sum + prime)
            } else {
                (len, sum)
            }});

    (max_len, sum_pre)
}

// find the sum of a sequence of primes in (0..max_len), where the sum of the
// sequence is sum_pre, that is also prime.
fn consecutive_prime_sum(prime: &mut Prime, max_len: usize, sum_pre: u64) -> Option<u64> {
    let mut sum_pre = sum_pre;
    for len in (0..(max_len-1)).map(|n| max_len - n) {
        let mut sum = sum_pre;
        sum_pre -= prime.nth(len);

        for i in len..(max_len+1) {
            if prime.check(sum) {
                return Some(sum);
            }

            sum -= prime.nth(1 + i - len);
            sum += prime.nth(1 + i);
        }
    }

    None
}

#[test]
fn test_max_len_sum() {
    let mut prime = Prime::new();

    assert_eq!(max_len_sum(&mut prime, 10), (2, 5));
    assert_eq!(max_len_sum(&mut prime, 11), (3, 10));
    assert_eq!(max_len_sum(&mut prime, 30), (5, 28));
    assert_eq!(max_len_sum(&mut prime, 100), (8, 77));
}

#[test]
fn test_consecutive_prime_sum() {
    let mut prime = Prime::new();

    assert_eq!(consecutive_prime_sum(&mut prime, 8, 77), Some(41));
    assert_eq!(consecutive_prime_sum(&mut prime, 1, 2), None);
}

#[test]
fn test_solve() {
    assert_eq!(solve(10), 5);
    assert_eq!(solve(100), 41);
}
