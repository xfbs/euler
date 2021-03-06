use std::ops::{Add, Div, DivAssign, Mul, MulAssign, Rem, RemAssign};

/// Iterator over the digits of a number.
#[derive(Debug, Copy, Clone)]
pub struct Digits<T> {
    num: T,
    mag: T,
    bas: T,
    rev: bool,
}

impl<T: DivAssign + MulAssign + PartialOrd + Copy + From<u8>> Digits<T> {
    /// Reverse the order that the digits are being output.
    ///
    /// Calling this method on the `Digits` struct causes the digits to be
    /// output in reverse order.
    ///
    /// ## Example
    ///
    /// ```
    /// use euler::ToDigits;
    ///
    /// assert_eq!(123.digits().collect::<Vec<i32>>(), vec![1, 2, 3]);
    /// assert_eq!(123.digits().reverse().collect::<Vec<i32>>(), vec![3, 2, 1]);
    /// ```
    pub fn reverse(&self) -> Self {
        Digits {
            num: self.num,
            mag: self.mag,
            bas: self.bas,
            rev: !self.rev,
        }
    }

    /// Change base in which digits are being output.
    ///
    /// By default, digits are being output in base 10. With this method a
    /// different base can be selected.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::ToDigits;
    ///
    /// assert_eq!(123.digits().collect::<Vec<u32>>(), vec![1, 2, 3]);
    /// assert_eq!(27.digits().base(2u8).collect::<Vec<u32>>(), vec![1, 1, 0, 1, 1]);
    /// ```
    pub fn base<B: Copy + Into<T>>(&self, base: B) -> Self {
        let mut mag = 1u8.into();
        while self.num >= mag {
            mag *= base.into();
        }

        mag /= base.into();

        Digits {
            num: self.num,
            mag: mag,
            bas: base.into(),
            rev: self.rev,
        }
    }
}

impl<T> Iterator for Digits<T>
where
    T: Copy
        + DivAssign
        + MulAssign
        + RemAssign
        + Add<Output = T>
        + Div<Output = T>
        + Rem<Output = T>
        + Mul<Output = T>
        + PartialEq
        + From<u8>,
{
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        if self.mag == 0u8.into() {
            None
        } else {
            let res = if self.rev {
                self.num % self.bas
            } else {
                self.num / self.mag
            };

            if self.rev {
                self.num /= self.bas;
            } else {
                self.num %= self.mag;;
            }

            self.mag /= self.bas;

            Some(res)
        }
    }
}

/// Trait to convert a number into an iterator over its digits.
pub trait ToDigits<T> {
    /// Convert self into an iterator over the digits.
    ///
    /// Returns an iterator over the digits of self. If the type of `self` is
    /// `u32`, then the type of the iterated digits will also be `u32`.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::ToDigits;
    ///
    /// assert_eq!(1234.digits().collect::<Vec<u32>>(), vec![1, 2, 3, 4]);
    /// assert_eq!(8328.digits().collect::<Vec<u32>>(), vec![8, 3, 2, 8]);
    /// ```
    fn digits(&self) -> Digits<T>;
}

impl<T> ToDigits<T> for T
where
    T: Copy
        + DivAssign
        + MulAssign
        + Add<Output = T>
        + Div<Output = T>
        + Rem<Output = T>
        + Mul<Output = T>
        + PartialEq
        + PartialOrd
        + From<u8>,
{
    fn digits(&self) -> Digits<T> {
        let base = 10u8.into();
        let mut mag = 1u8.into();
        while *self >= mag {
            mag *= base;
        }

        mag /= base;

        Digits {
            num: *self,
            mag: mag,
            bas: base,
            rev: false,
        }
    }
}

#[test]
fn test_digits_count() {
    assert_eq!(0.digits().count(), 0);
    assert_eq!(1.digits().count(), 1);
    assert_eq!(10.digits().count(), 2);
    assert_eq!(34.digits().count(), 2);
    assert_eq!(230.digits().count(), 3);
    assert_eq!(999.digits().count(), 3);
    assert_eq!(1000.digits().count(), 4);
}

#[test]
fn test_reverse_digits_count() {
    assert_eq!(0.digits().reverse().count(), 0);
    assert_eq!(1.digits().reverse().count(), 1);
    assert_eq!(10.digits().reverse().count(), 2);
    assert_eq!(34.digits().reverse().count(), 2);
    assert_eq!(230.digits().reverse().count(), 3);
    assert_eq!(999.digits().reverse().count(), 3);
    assert_eq!(1000.digits().reverse().count(), 4);
}

#[test]
fn test_digits_correct() {
    assert_eq!(
        1234567.digits().collect::<Vec<u32>>(),
        vec![1, 2, 3, 4, 5, 6, 7]
    );
    assert_eq!(
        1234567.digits().reverse().collect::<Vec<u32>>(),
        vec![7, 6, 5, 4, 3, 2, 1]
    );

    assert_eq!(
        0b101101.digits().base(2u8).collect::<Vec<u32>>(),
        vec![1, 0, 1, 1, 0, 1]
    );
    assert_eq!(
        0b101101.digits().base(2u8).reverse().collect::<Vec<u32>>(),
        vec![1, 0, 1, 1, 0, 1]
    );
}

#[test]
fn test_digits_less_than_base() {
    for num in 0..1000 {
        for digit in num.digits() {
            assert!(digit < 10);
        }

        for digit in num.digits().reverse() {
            assert!(digit < 10);
        }

        for &base in [2, 8, 10, 16, 32].iter() {
            for digit in num.digits().base(base as u8).reverse() {
                assert!(digit < base);
            }
        }
    }
}
