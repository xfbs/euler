use std::ops::{AddAssign, Div, Mul, Rem};

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

pub trait ToDivisors
where
    Self: Sized,
{
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
