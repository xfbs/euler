use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Rem, RemAssign};

pub fn divisor_sum(num: u64) -> u64 {
    let root = (num as f64).sqrt() as u64;
    let mut sum = 0;

    for div in 1..(root + 1) {
        if (num % div) == 0 {
            sum += div;

            if (div != (num / div)) && div != 1 {
                sum += num / div;
            }
        }
    }

    sum
}

#[test]
fn test_divisor_sum() {
    assert_eq!(divisor_sum(2), 1);
    assert_eq!(divisor_sum(3), 1);
    assert_eq!(divisor_sum(4), 1 + 2);
    assert_eq!(divisor_sum(5), 1);
    assert_eq!(divisor_sum(6), 1 + 2 + 3);
    assert_eq!(divisor_sum(7), 1);
    assert_eq!(divisor_sum(8), 1 + 2 + 4);
    assert_eq!(divisor_sum(9), 1 + 3);
    assert_eq!(divisor_sum(10), 1 + 2 + 5);
    assert_eq!(divisor_sum(11), 1);
    assert_eq!(divisor_sum(12), 1 + 2 + 3 + 4 + 6);
    assert_eq!(
        divisor_sum(60),
        1 + 2 + 3 + 4 + 5 + 6 + 10 + 12 + 15 + 20 + 30
    );
}

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

pub trait ToDivisors where Self: Sized {
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
            chk: false
        }
    }
}

#[test]
fn test_divisors() {
    assert_eq!(220.divisors().sum::<i32>(), 284);
    assert_eq!(284.divisors().sum::<i32>(), 220);
}
