use std::vec::IntoIter;
use std::iter::{Enumerate, FilterMap};

pub struct Sieve {
    state: Vec<bool>
}

impl Sieve {
    pub fn new(max: usize) -> Self {
        let mut state = vec![true; max + 1];
        state[0] = false;
        state[1] = false;

        let mut p: u64 = 2;
        while (p*p) <= max as u64 {
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

    pub fn check(&self, num: u64) -> bool {
        self.state[num as usize]
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

    assert!(sieve.check(2));
    assert!(sieve.check(3));
    assert!(sieve.check(5));
    assert!(sieve.check(7));

    assert!(!sieve.check(0));
    assert!(!sieve.check(1));
    assert!(!sieve.check(4));
    assert!(!sieve.check(6));
    assert!(!sieve.check(8));
    assert!(!sieve.check(9));
    assert!(!sieve.check(10));
}

#[test]
fn test_sieve_check_big() {
    let sieve = Sieve::new(100);

    assert!(sieve.check(2));
    assert!(sieve.check(3));
    assert!(sieve.check(5));
    assert!(sieve.check(7));
    assert!(sieve.check(41));
    assert!(sieve.check(47));

    assert!(!sieve.check(0));
    assert!(!sieve.check(10));
    assert!(!sieve.check(98));
    assert!(!sieve.check(60));
    assert!(!sieve.check(44));
    assert!(!sieve.check(25));
    assert!(!sieve.check(90));
    assert!(!sieve.check(55));
}

#[test]
fn test_sieve_iter_check() {
    let sieve = Sieve::new(100);

    assert_eq!(sieve.into_iter().count(), 25);
}

