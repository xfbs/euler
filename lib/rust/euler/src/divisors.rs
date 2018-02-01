use std::ops::{AddAssign, Div, Mul, Rem};

/// An iterator over the divisors of a number.
#[derive(Debug, Copy, Clone)]
pub struct Divisors<T> {
    num: T,
    cur: T,
    chk: bool,
}

impl<T> Iterator for Divisors<T>
where
    T: Copy
        + AddAssign
        + Div<Output = T>
        + Rem<Output = T>
        + Mul<Output = T>
        + PartialOrd
        + From<u8>,
{
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        if self.cur * self.cur > self.num {
            None
        } else {
            if !self.chk {
                if self.num % self.cur == 0u8.into() {
                    self.chk = true;
                    Some(self.cur)
                } else {
                    self.cur += 1u8.into();
                    self.next()
                }
            } else {
                self.chk = false;
                let recp = self.num / self.cur;

                if self.cur != recp && self.cur != 1u8.into() {
                    self.cur += 1u8.into();
                    Some(recp)
                } else {
                    self.cur += 1u8.into();
                    self.next()
                }
            }
        }
    }
}

/// Trait to turn a number into an `Iterator` over its divisors.
pub trait ToDivisors
where
    Self: Sized,
{
    /// Return an iterator over the divisors of `self`.
    ///
    /// Calling this method will produce an Iterator over the divisors of
    /// `self`. The order that the divisors will be returned is undefined.
    ///
    /// The iterator will only produce proper divisors of `self` — that is,
    /// divisors that divide `self` evenly and are smaller than `self`.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::ToDivisors;
    ///
    /// assert_eq!(0.divisors().count(), 0);
    /// assert_eq!(4.divisors().count(), 2);
    /// assert_eq!(12.divisors().sum::<i32>(), [1, 2, 3, 4, 6].iter().sum());
    /// ```
    fn divisors(&self) -> Divisors<Self>;
}

impl<T> ToDivisors for T
where
    T: Copy + From<u8>,
{
    fn divisors(&self) -> Divisors<Self> {
        Divisors {
            num: *self,
            cur: 1u8.into(),
            chk: false,
        }
    }
}

#[test]
fn test_divisors() {
    assert_eq!(220.divisors().sum::<i32>(), 284);
    assert_eq!(284.divisors().sum::<i32>(), 220);
}
