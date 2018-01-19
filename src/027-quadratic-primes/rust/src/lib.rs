extern crate euler;
use euler::prime::Prime;

pub fn solve(max: u32) -> i32 {
    let mut primes = Prime::new();

    // pre-populate a list of primes less than max
    let primes_under_max = primes
        .into_iter()
        .take_while(|p| *p < max as u64)
        .collect::<Vec<u64>>();

    // for a, try all |a| < max
    let (product, _) = ((1 - max as i32)..max as i32)
        .map(|a| {
            // for b, only try prime numbers, since f(0) = b, so b must be prime.
            primes_under_max
                .iter()
                .map(|b| {
                    (
                        a * *b as i32,
                        quadratic_prime_run(&mut primes, a, *b as i32),
                    )
                })
                .max_by_key(|&(_, run)| run)
                .unwrap()
        })
        .max_by_key(|&(_, run)| run)
        .unwrap();

    product
}

fn f(n: i32, a: i32, b: i32) -> i32 {
    n * n + n * a + b
}

pub fn quadratic_prime_run(primes: &mut Prime, a: i32, b: i32) -> u32 {
    (0u32..)
        .map(|n| (n, f(n as i32, a, b)))
        .find(|&(_, y)| y < 0 || !primes.check(y as u64))
        .unwrap()
        .0
}

#[test]
fn test_quadratic_prime_run() {
    let mut p = Prime::new();

    assert_eq!(f(0, 9, 13), 13);
    assert_eq!(f(1, 9, 13), 23);
    assert_eq!(f(2, 9, 13), 35);

    assert!(p.check(f(0, 9, 13) as u64));
    assert!(p.check(f(1, 9, 13) as u64));
    assert!(!p.check(f(2, 9, 13) as u64));

    assert_eq!(quadratic_prime_run(&mut p, 9, 13), 2);
    assert_eq!(quadratic_prime_run(&mut p, 1, 41), 40);
    assert_eq!(quadratic_prime_run(&mut p, -1, 41), 41);
    assert_eq!(quadratic_prime_run(&mut p, -79, 1601), 80);
    assert_eq!(quadratic_prime_run(&mut p, -120, 45), 0);
}

#[test]
fn test_f() {
    assert_eq!(f(0, 1, 41), 41);
    assert_eq!(f(1, 1, 41), 43);
    assert_eq!(f(2, 1, 41), 47);
    assert_eq!(f(3, 1, 41), 53);
}

#[test]
fn test_solve() {
    assert_eq!(solve(42), -41);
}
