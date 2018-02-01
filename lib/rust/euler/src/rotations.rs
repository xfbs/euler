use std::ops::{Add, Div, DivAssign, Mul, MulAssign, Rem};

/// Iterator over rotations of a number.
#[derive(Debug, Copy, Clone)]
pub struct Rotations<T> {
    num: T,
    mag: T,
    bas: T,
    cur: T,
    rev: bool,
}

impl<T: MulAssign + PartialOrd + Copy + From<u8>> Rotations<T> {
    /// Reverse the direction of the rotations.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::ToRotations;
    ///
    /// assert_eq!(123.rotations().collect::<Vec<u32>>(), vec![123, 312, 231]);
    /// assert_eq!(123.rotations().reverse().collect::<Vec<u32>>(), vec![123, 231, 312]);
    /// ```
    pub fn reverse(&self) -> Self {
        let cur = if !self.rev { self.mag } else { 1u8.into() };

        Rotations {
            num: self.num,
            mag: self.mag,
            bas: self.bas,
            cur: cur,
            rev: !self.rev,
        }
    }

    /// Change the base in which to rotate the number.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::ToRotations;
    ///
    /// let rotated = 0b11011.rotations().base(2u8).collect::<Vec<u32>>();
    /// let reference = vec![0b11011, 0b11101, 0b11110, 0b1111, 0b10111];
    /// assert_eq!(rotated, reference);
    /// ```
    pub fn base<B: Copy + Into<T>>(&self, base: B) -> Self {
        let mut mag = base.into();
        while self.num >= mag {
            mag *= base.into();
        }

        let cur = if self.rev { self.mag } else { 1u8.into() };

        Rotations {
            num: self.num,
            mag: mag,
            bas: base.into(),
            cur: cur,
            rev: self.rev,
        }
    }
}

impl<T> Iterator for Rotations<T>
where
    T: Copy
        + DivAssign
        + MulAssign
        + Add<Output = T>
        + Div<Output = T>
        + Rem<Output = T>
        + Mul<Output = T>
        + PartialEq
        + From<u8>,
{
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        if self.rev && self.cur == 1u8.into() || !self.rev && self.cur == self.mag {
            None
        } else {
            let res = self.num / self.cur + (self.mag / self.cur) * (self.num % self.cur);

            if self.rev {
                self.cur /= self.bas;
            } else {
                self.cur *= self.bas;
            }

            Some(res)
        }
    }
}

/// Trait to generate an iterator over the rotations of a number.
pub trait ToRotations<T> {
    /// Returns an iterator over the rotations of a number.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::ToRotations;
    ///
    /// let mut rotations = 123.rotations();
    /// assert_eq!(rotations.next(), Some(123));
    /// assert_eq!(rotations.next(), Some(312));
    /// assert_eq!(rotations.next(), Some(231));
    /// assert_eq!(rotations.next(), None);
    /// ```
    fn rotations(&self) -> Rotations<T>;
}

impl<T> ToRotations<T> for T
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
    fn rotations(&self) -> Rotations<T> {
        let base = 10u8.into();
        let mut mag = base;
        while *self >= mag {
            mag *= base;
        }

        let cur = 1u8.into();

        Rotations {
            num: *self,
            mag: mag,
            bas: base,
            cur: cur,
            rev: false,
        }
    }
}

#[test]
fn test_rotations_u64() {
    assert_eq!(123.rotations().collect::<Vec<u64>>(), vec![123, 312, 231]);
    assert_eq!(
        123.rotations().reverse().collect::<Vec<u64>>(),
        vec![123, 231, 312]
    );
    assert_eq!(
        0b1011.rotations().base(2u8).collect::<Vec<u64>>(),
        vec![0b1011, 0b1101, 0b1110, 0b111]
    );
}
