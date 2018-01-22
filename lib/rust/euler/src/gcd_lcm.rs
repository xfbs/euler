use std::ops::{Rem, Div, Mul};

pub trait GcdLcm<RHS = Self> where
{
    type Output;
    fn gcd(&self, b: RHS) -> Self::Output;
    fn lcm(&self, b: RHS) -> Self::Output;
}

impl<LHS, RHS> GcdLcm<RHS> for LHS where
    LHS: Copy + Div<Output=LHS> + Mul<Output=LHS> + PartialOrd + Rem<Output=LHS> + From<u8>,
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
