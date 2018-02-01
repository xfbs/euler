use std::vec::Vec;

/// Prime number generator.
pub struct Prime {
    list: Vec<u64>,
}

impl Prime {
    /// Construct a new prime number generator.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::Prime;
    ///
    /// let mut primes = Prime::new();
    /// assert_eq!(primes.nth(4), 7);
    /// ```
    pub fn new() -> Self {
        Prime { list: vec![2, 3] }
    }

    fn next(&mut self) -> u64 {
        let mut last = self.list.last().unwrap() + 2;

        while !self.check_fast(last).unwrap() {
            last += 2;
        }

        self.list.push(last);
        last
    }

    fn check_fast(&self, num: u64) -> Result<bool, ()> {
        let root = (num as f64).sqrt() as u64;

        for prime in self.list.iter() {
            if *prime > root {
                return Ok(true);
            }
            if (num % *prime) == 0 {
                return Ok(false);
            }
        }

        Err(())
    }

    /// Generates `nth` prime.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::Prime;
    ///
    /// let mut primes = Prime::new();
    /// assert_eq!(primes.nth(8), 19);
    /// assert_eq!(primes.nth(9), 23);
    /// assert_eq!(primes.nth(10), 29);
    /// ```
    pub fn nth(&mut self, n: usize) -> u64 {
        while self.list.len() < n {
            self.next();
        }

        self.list[n - 1]
    }

    /// Checks if a number is prime.
    ///
    /// Tries to divide by all primes smaller or equal to the square root of
    /// the number, returns true if it found a divisor or false if the number
    /// is prime.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::Prime;
    ///
    /// let mut primes = Prime::new();
    /// assert_eq!(primes.check(97), true);
    /// assert_eq!(primes.check(99), false);
    /// ```
    pub fn check(&mut self, num: u64) -> bool {
        let root = (num as f64).sqrt() as u64;

        while *self.list.last().unwrap() <= root {
            self.next();
        }

        if num < 2 {
            return false;
        }

        self.check_fast(num).unwrap()
    }
}

pub struct PrimeIter<'a> {
    prime: &'a mut Prime,
    pos: usize,
}

impl<'a> Iterator for PrimeIter<'a> {
    type Item = u64;

    fn next(&mut self) -> Option<Self::Item> {
        self.pos += 1;
        Some(self.prime.nth(self.pos - 1))
    }
}

impl<'a> IntoIterator for &'a mut Prime {
    type Item = u64;
    type IntoIter = PrimeIter<'a>;

    fn into_iter(self) -> Self::IntoIter {
        PrimeIter {
            prime: self,
            pos: 1,
        }
    }
}

#[test]
fn test_prime_next() {
    let mut p = Prime::new();

    assert!(p.next() == 5);
    assert!(p.next() == 7);
    assert!(p.next() == 11);
    assert!(p.next() == 13);
    assert!(p.next() == 17);
    assert!(p.next() == 19);
    assert!(p.next() == 23);
    assert!(p.next() == 29);
    assert!(p.next() == 31);
}

#[test]
fn test_prime_nth() {
    let mut p = Prime::new();

    assert!(p.nth(1) == 2);
    assert!(p.nth(2) == 3);
    assert!(p.nth(3) == 5);
    assert!(p.nth(4) == 7);
    assert!(p.nth(5) == 11);
    assert!(p.nth(6) == 13);
    assert!(p.nth(7) == 17);
    assert!(p.nth(8) == 19);
    assert!(p.nth(9) == 23);
    assert!(p.nth(10) == 29);
    assert!(p.nth(12) == 37);
}

#[test]
fn test_prime_check() {
    let mut p = Prime::new();

    assert!(!p.check(0));
    assert!(!p.check(1));
    assert!(p.check(2));
    assert!(p.check(3));
    assert!(p.check(13));
    assert!(!p.check(21));
}

#[test]
fn test_prime_iter() {
    let mut p = Prime::new();
    let ten = p.into_iter().take_while(|p| *p < 10).collect::<Vec<u64>>();
    assert_eq!(ten, vec![2, 3, 5, 7]);
}
