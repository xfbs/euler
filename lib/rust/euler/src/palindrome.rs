use digits::ToDigits;
use std::ops::{Add, Div, DivAssign, Mul, MulAssign, Rem, RemAssign};

/// Trait to turn a number into a palindrome.
pub trait ToPalindrome
where
    Self: Sized,
{
    /// Turns self into a palindrome.
    ///
    /// Returns two palindromes. If the number is `abc`, the first palindrome
    /// is `abcba` (shorter version) and the second if `abccba` (longer
    /// version). The parameter `base` specifies in which base the number
    /// should be a palindrome.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::ToPalindrome;
    ///
    /// assert_eq!(123.to_palindrome(10), (12321, 123321));
    /// assert_eq!(932.to_palindrome(10), (93239, 932239));
    /// ```
    fn to_palindrome(&self, base: Self) -> (Self, Self);
}

impl<T> ToPalindrome for T
where
    T: ToDigits<T>
        + Copy
        + DivAssign
        + MulAssign
        + RemAssign
        + Add<Output = T>
        + Div<Output = T>
        + Rem<Output = T>
        + Mul<Output = T>
        + PartialEq
        + PartialOrd
        + From<u8>,
{
    fn to_palindrome(&self, base: Self) -> (Self, Self) {
        let long = self.digits()
            .base(base)
            .chain(self.digits().base(base).reverse())
            .fold(0u8.into(), |m, d| base * m + d);
        let short = self.digits()
            .base(base)
            .chain(self.digits().base(base).reverse().skip(1))
            .fold(0u8.into(), |m, d| base * m + d);
        (short, long)
    }
}

/// Trait to check if a number is a palindrome.
pub trait IsPalindrome
where
    Self: Sized,
{
    /// Checks if `self` is a palindrome in the given base.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::IsPalindrome;
    ///
    /// assert_eq!(12321.is_palindrome(10), true);
    /// assert_eq!(123321.is_palindrome(10), true);
    /// assert_eq!(93239.is_palindrome(10), true);
    /// assert_eq!(932239.is_palindrome(10), true);
    /// assert_eq!(394449.is_palindrome(10), false);
    /// ```
    fn is_palindrome(&self, base: Self) -> bool;
}

impl<T> IsPalindrome for T
where
    T: ToDigits<T>
        + Copy
        + DivAssign
        + MulAssign
        + RemAssign
        + Add<Output = T>
        + Div<Output = T>
        + Rem<Output = T>
        + Mul<Output = T>
        + PartialEq
        + PartialOrd
        + From<u8>,
{
    fn is_palindrome(&self, base: Self) -> bool {
        *self
            == self.digits()
                .base(base)
                .reverse()
                .fold(0u8.into(), |m, c| base as T * m + c)
    }
}

#[test]
fn test_is_palindrome() {
    assert!(1221.is_palindrome(10));
    assert!(99099u32.is_palindrome(10));
    assert!(123454321i64.is_palindrome(10));

    assert!(!1231.is_palindrome(10));
    assert!(!12331.is_palindrome(10));
    assert!(!0b1101.is_palindrome(2));
    assert!(!0b1011.is_palindrome(2));
    assert!(!0b10011.is_palindrome(2));
    assert!(!11.is_palindrome(2));
}

#[test]
fn test_to_palindrome() {
    assert_eq!(123.to_palindrome(10), (12321, 123321));
    assert_eq!(1231.to_palindrome(10), (1231321, 12311321));
}
