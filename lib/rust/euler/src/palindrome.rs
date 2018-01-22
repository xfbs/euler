use digits::ToDigits;
use std::ops::{DivAssign, MulAssign, RemAssign, Add, Div, Rem, Mul};

pub trait ToPalindrome where Self: Sized {
    fn to_palindrome(&self, base: Self) -> (Self, Self);
}

impl<T> ToPalindrome for T
where
    T: ToDigits<T> + Copy
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
        let long = self.digits().base(base).chain(self.digits().base(base).reverse()).fold(0u8.into(), |m, d| base * m + d);
        let short = self.digits().base(base).chain(self.digits().base(base).reverse().skip(1)).fold(0u8.into(), |m, d| base * m + d);
        (short, long)
    }
}

pub trait IsPalindrome where Self: Sized {
    fn is_palindrome(&self, base: Self) -> bool;
}

impl<T> IsPalindrome for T
where
    T: ToDigits<T> + Copy
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
        *self == self.digits().base(base).reverse().fold(0u8.into(), |m, c| base as T * m + c)
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
