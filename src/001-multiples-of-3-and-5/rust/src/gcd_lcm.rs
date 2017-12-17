// euclid's two-thousand-year-old algorithm for finding the greatest common
// divisor. shamelessly copied from doc.rust-lang.org.
pub fn gcd(a: u32, b: u32) -> u32 {
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
pub fn lcm(a: u32, b: u32) -> u32 {
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
