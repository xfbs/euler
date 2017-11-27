// find the sum of all numbers between 0 and max that are divisible
// by any of the two divisors
pub fn solve(max: u32, divisors: (u32, u32)) -> u32 {
    let (a, b) = divisors;

    sum(max, a) + sum(max, b) - sum(max, lcm(a, b))
}

// find the sum of all numbers that are divisible by the divisor
fn sum(max: u32, divisor: u32) -> u32 {
    // find the biggest number <= max that is divisible by divisor
    let max = max - (max % divisor);

    (max * ((max/divisor) + 1)) / 2
}

// euclid's two-thousand-year-old algorithm for finding the greatest common
// divisor. shamelessly copied from doc.rust-lang.org.
fn gcd(a: u32, b: u32) -> u32 {
    let mut a = a;
    let mut b = b;
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

// least common multiple of a and b.
fn lcm(a: u32, b: u32) -> u32 {
    if b > a {
        lcm(b, a)
    } else {
        a / gcd(a, b) * b
    }
}

#[test]
fn lcm_works() {
    // gcd of primes a and b is always a*b
    assert!(lcm(3, 5) == 15);
    assert!(lcm(5, 13) == 65);

    assert!(lcm(2, 10) == 10);
    assert!(lcm(3, 10) == 30);
    assert!(lcm(10, 25) == 50);
}

#[test]
fn gcd_works() {
    assert!(gcd(3, 5) == 1);
    assert!(gcd(5, 13) == 1);
    assert!(gcd(2, 10) == 2);
    assert!(gcd(5, 10) == 5);
    assert!(gcd(10, 25) == 5);
}

#[test]
fn sum_works() {
    assert!(sum(10, 3) == 18);
    assert!(sum(10, 5) == 15);
    assert!(sum(22, 7) == 42);
    assert!(sum(43, 51) == 0);
    assert!(sum(50, 10) == 150);
    assert!(sum(50, 25) == 75);
}

#[test]
fn solve_works() {
    assert!(solve(50, (10, 25)) == 175);
    assert!(solve(50, (25, 10)) == 175);
    assert!(solve(55, (10, 25)) == 175);
    assert!(solve(55, (25, 10)) == 175);
}
