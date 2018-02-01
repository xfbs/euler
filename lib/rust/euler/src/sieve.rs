use std::vec::IntoIter;
use std::iter::{Enumerate, FilterMap};

/// Prime sieve.
///
/// Implements `IntoIter` so that it can be used as an iterator over the primes.
///
/// ## Examples
///
/// ```
/// use euler::Sieve;
///
/// let sieve = Sieve::new(100);
/// assert_eq!(sieve.into_iter().count(), 25);
/// ```
pub struct Sieve {
    state: Vec<bool>,
}

impl Sieve {
    /// Create a new prime sieve, and sieve all numbers up to `max`.
    ///
    /// Sieves all numbers from 0 until `max` and returns a `Sieve` instance
    /// with the resulting matrix.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::Sieve;
    ///
    /// let sieve = Sieve::new(1000);
    /// assert_eq!(sieve.check(17), Some(true));
    /// assert_eq!(sieve.check(20), Some(false));
    /// assert_eq!(sieve.check(1001), None);
    /// ```
    pub fn new(max: usize) -> Self {
        let mut state = vec![true; max + 1];
        state[0] = false;
        state[1] = false;

        let mut p: u64 = 2;
        while (p * p) <= max as u64 {
            for f in p..((max as u64 / p) + 1) {
                state[(f * p) as usize] = false;
            }

            while {
                p = p + 1;
                state[p as usize] == false
            } {}
        }

        Sieve { state: state }
    }

    /// Checks if a given number is prime or not.
    ///
    /// ## Examples
    ///
    /// ```
    /// use euler::Sieve;
    ///
    /// let sieve = Sieve::new(1000);
    /// assert_eq!(sieve.check(17), Some(true));
    /// assert_eq!(sieve.check(20), Some(false));
    /// assert_eq!(sieve.check(1001), None);
    /// ```
    pub fn check(&self, num: u64) -> Option<bool> {
        self.state.get(num as usize).cloned()
    }

    fn filter_prime((pos, prime): (usize, bool)) -> Option<u64> {
        if prime {
            Some(pos as u64)
        } else {
            None
        }
    }
}

impl IntoIterator for Sieve {
    type Item = u64;
    type IntoIter = FilterMap<Enumerate<IntoIter<bool>>, fn((usize, bool)) -> Option<u64>>;

    fn into_iter(self) -> Self::IntoIter {
        self.state
            .into_iter()
            .enumerate()
            .filter_map(Sieve::filter_prime)
    }
}

#[test]
fn test_sieve_check_small() {
    let sieve = Sieve::new(10);

    assert!(sieve.check(2).unwrap());
    assert!(sieve.check(3).unwrap());
    assert!(sieve.check(5).unwrap());
    assert!(sieve.check(7).unwrap());

    assert!(!sieve.check(0).unwrap());
    assert!(!sieve.check(1).unwrap());
    assert!(!sieve.check(4).unwrap());
    assert!(!sieve.check(6).unwrap());
    assert!(!sieve.check(8).unwrap());
    assert!(!sieve.check(9).unwrap());
    assert!(!sieve.check(10).unwrap());
    assert!(sieve.check(11).is_none());
}

#[test]
fn test_sieve_check_big() {
    let sieve = Sieve::new(100);

    assert!(sieve.check(2).unwrap());
    assert!(sieve.check(3).unwrap());
    assert!(sieve.check(5).unwrap());
    assert!(sieve.check(7).unwrap());
    assert!(sieve.check(41).unwrap());
    assert!(sieve.check(47).unwrap());

    assert!(!sieve.check(0).unwrap());
    assert!(!sieve.check(10).unwrap());
    assert!(!sieve.check(98).unwrap());
    assert!(!sieve.check(60).unwrap());
    assert!(!sieve.check(44).unwrap());
    assert!(!sieve.check(25).unwrap());
    assert!(!sieve.check(90).unwrap());
    assert!(!sieve.check(55).unwrap());

    assert!(sieve.check(101).is_none());
}

#[test]
fn test_sieve_iter_check() {
    let sieve = Sieve::new(100);

    assert_eq!(sieve.into_iter().count(), 25);
}
