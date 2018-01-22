use std::ops::{Rem, Div, Mul};

pub trait GcdLcm where Self: Clone {
    fn gcd<R: Clone + Into<Self>>(&self, b: R) -> Self;
    fn lcm<R: Clone + Into<Self>>(&self, b: R) -> Self;
}

impl<T> GcdLcm for T
where T: PartialEq + Rem<Output=T> + Div<Output=T> + Mul<Output=T> + Clone + From<u8> + PartialOrd
{
    // greatest common divisor
    fn gcd<R: Into<T>>(&self, b: R) -> T {
        let mut a = self.clone();
        let mut b = b.into();
        while b != 0u8.into() {
            let t = b.clone();
            b = a % b;
            a = t;
        }

        a
    }

    // least common multiple of a and b.
    fn lcm<R: Into<T>>(&self, b: R) -> T {
        let b = b.into();
        if b > *self {
            b.lcm(self.clone())
        } else {
            self.clone() / self.gcd(b.clone()) * b
        }
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
