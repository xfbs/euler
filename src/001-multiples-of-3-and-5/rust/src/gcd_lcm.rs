pub trait GcdLcm : Clone {
    fn gcd(&self, b: Self) -> Self;
    fn lcm(&self, b: Self) -> Self;
}

impl GcdLcm for u32 {
    // greatest common divisor
    fn gcd(&self, b: u32) -> u32 {
        let mut a = self.clone();
        let mut b = b;
        while b != 0 {
            let t = b;
            b = a % b;
            a = t;
        }

        a
    }

    // least common multiple of a and b.
    fn lcm(&self, b: u32) -> u32 {
        if b > *self {
            b.lcm(*self)
        } else {
            self / self.gcd(b) * b
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
