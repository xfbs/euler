use std::ops::{Div, Mul, Rem};

// FIXME: once const fn is stable, implement this as such.
const FACTORIALS: [u64; 21] = [
	1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600,
    6227020800,
    87178291200,
    1307674368000,
    20922789888000,
    355687428096000,
    6402373705728000,
    121645100408832000,
    2432902008176640000
];

pub fn factorial(n: u64) -> u64 {
	FACTORIALS[n as usize]
}


pub trait Gcd<RHS = Self> {
    type Output;

    fn gcd(&self, b: RHS) -> Self::Output;
}

pub trait Lcm<RHS = Self> {
    type Output;

    fn lcm(&self, b: RHS) -> Self::Output;
}

impl<LHS, RHS> Gcd<RHS> for LHS
where
    LHS: Copy + PartialOrd + Rem<Output = LHS> + From<u8>,
    RHS: Copy + Into<LHS>,
{
    type Output = LHS;

    fn gcd(&self, rhs: RHS) -> Self::Output {
        let mut a = *self;
        let mut b = rhs.into();
        while b != 0u8.into() {
            let t = b;
            b = a % b;
            a = t;
        }

        a
    }
}

impl<LHS, RHS> Lcm<RHS> for LHS
where
    LHS: Copy + Gcd<Output = LHS> + Div<Output = LHS> + Mul<Output = LHS>,
    RHS: Copy + Into<LHS>
{
    type Output = LHS;

    fn lcm(&self, rhs: RHS) -> Self::Output {
        let rhs = rhs.into();
        *self / self.gcd(rhs) * rhs
    }
}

#[test]
fn lcm_works() {
    // gcd of primes a and b is always a*b
    assert!(3.lcm(5) == 15);
    assert!(5.lcm(13) == 65);

    assert!(2.lcm(10) == 10);
    assert!(3.lcm(10) == 30);
    assert!(10.lcm(25) == 50);
}

#[test]
fn gcd_works() {
    assert!(3.gcd(5) == 1);
    assert!(5.gcd(13) == 1);
    assert!(2.gcd(10) == 2);
    assert!(5.gcd(10) == 5);
    assert!(10.gcd(25) == 5);
}

#[test]
fn test_factorial() {
    assert_eq!(factorial(0), 1);
    assert_eq!(factorial(1), 1);
    assert_eq!(factorial(2), 2);
    assert_eq!(factorial(3), 6);
    assert_eq!(factorial(4), 24);
    assert_eq!(factorial(5), 120);
    assert_eq!(factorial(6), 720);
    assert_eq!(factorial(7), 5040);
    assert_eq!(factorial(8), 40320);
}

