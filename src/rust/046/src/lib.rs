extern crate euler;
use euler::Prime;

pub fn solve() -> u64 {
    // FIXME: hack. since I can't have two mutable references to a prime (one
    // being primes.check() and the other one being primes.into_iter(), I just
    // resort to having two separate primes generators, which is of course not
    // exactly efficient, but works for now.
    let mut primes = Prime::new();
    let mut other = Prime::new();

    (3..)
        .filter(|&n| n % 2 == 1)
        .filter(|&n| !primes.check(n))
        .find(|&c| !conjecture(&mut other, c))
        .unwrap()
}

pub fn conjecture(primes: &mut Prime, odd_composite: u64) -> bool {
    primes
        .into_iter()
        .skip(1)
        .take_while(|&prime| prime < odd_composite)
        .map(|prime| (odd_composite - prime) / 2)
        .any(|prime| ((prime as f64).sqrt() as u64).pow(2) == prime)
}

#[test]
fn test_conjecture() {
    let mut primes = Prime::new();

    assert!(conjecture(&mut primes, 1005));
    assert!(!conjecture(&mut primes, 5993));
}

#[test]
fn test_solve() {
    let mut primes = Prime::new();

    assert!(!conjecture(&mut primes, solve()));
}
