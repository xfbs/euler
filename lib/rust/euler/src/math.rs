use std::ops::{Div, Mul, Rem};

/// Pre-computed factorials.
///
/// Since it's rather expensive to recompute them every time, and a u64 can only
/// hold factorials up to 20! anyways, they are pre-computed and stored in this
/// global.
///
/// Ideally at some point these should be computed by a `const fn`, but since
/// that hasn't arrived in rust stable yet as of `1.22.1`, this will do.
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

/// Returns the `n`th factorial.
///
/// Looks the factorial up in `FACTORIALS`, so it's cheap to generate
/// factorials. Note however that this method will only return factorials up to
/// 20! — anything bigger than that will not fit into an `u64`.
///
/// ## Examples
///
/// ```
/// assert_eq!(euler::factorial(0), Some(1));
/// assert_eq!(euler::factorial(1), Some(1));
/// assert_eq!(euler::factorial(6), Some(720));
/// assert_eq!(euler::factorial(21), None);
/// ```
pub fn factorial(n: u64) -> Option<u64> {
	FACTORIALS.get(n as usize).cloned()
}

/// The greatest common divisor of two types.
pub trait Gcd<RHS = Self> {
    /// The resulting type of computing the greatest common divisor of two
    /// numbers.
    type Output;

    /// Computes the greatest common multiple of two numbers.
    ///
    /// Implementation uses Euclid's battle-tested algorithm.
    ///
    /// ## Examples
    ///
    /// ### Compute Gcds of integers
    ///
    /// ```
    /// use euler::Gcd;
    ///
    /// assert_eq!(3.gcd(5), 1);
    /// assert_eq!(13.gcd(23), 1);
    /// assert_eq!(10.gcd(15), 5);
    /// assert_eq!(44.gcd(100), 4);
    /// ```
    ///
    /// ### Compute Gcds of integers of different types
    ///
    /// You can also get the Gcd of two different types, as long as the `RHS`
    /// type implements `Into<LHS>`.
    ///
    /// ```
    /// use euler::Gcd;
    ///
    /// assert_eq!(5i64.gcd(9u32), 1);
    /// assert_eq!(504u64.gcd(994u32), 14);
    /// ```
    fn gcd(&self, b: RHS) -> Self::Output;
}

/// The least common multiple of two types.
pub trait Lcm<RHS = Self> {
    /// The resulting type of computing the least common multiple of two
    /// numbers.
    type Output;

    /// Computes the least common multiple of two numbers.
    ///
    /// Implementation uses `Gcd`, so it only works for types which implement the
    /// `Gcd` trait.
    ///
    /// ## Examples
    ///
    /// ### Compute Lcm of integers
    ///
    /// ```
    /// use euler::Lcm;
    ///
    /// assert_eq!(5.lcm(3), 15);
    /// assert_eq!(5.lcm(15), 15);
    /// assert_eq!(5.lcm(32), 160);
    /// assert_eq!(244.lcm(124), 7564);
    /// ```
    ///
    /// ### Compute Lcm of integers of different types
    ///
    /// Just like the `Gcd` trait, you can get the Lcm of two integers with
    /// different types so long as the `RHS` type implements `Into<LHS>`.
    ///
    /// ```
    /// use euler::Lcm;
    ///
    /// assert_eq!(22u32.lcm(56u16), 616);
    /// assert_eq!(76i64.lcm(14i8), 532);
    /// ```
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
    assert_eq!(factorial(0), Some(1));
    assert_eq!(factorial(1), Some(1));
    assert_eq!(factorial(2), Some(2));
    assert_eq!(factorial(3), Some(6));
    assert_eq!(factorial(4), Some(24));
    assert_eq!(factorial(5), Some(120));
    assert_eq!(factorial(6), Some(720));
    assert_eq!(factorial(7), Some(5040));
    assert_eq!(factorial(8), Some(40320));
    assert_eq!(factorial(21), None);
}

