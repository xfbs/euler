use std::vec::Vec;

pub struct Prime {
    list: Vec<u64>,
}

impl Prime {
    pub fn new() -> Self {
        Prime {
            list: vec![2, 3]
        }
    }
    fn next(&mut self) -> u64 {
        let mut last = self.list.last().unwrap() + 2;

        while !self.is_prime(last) {
            last += 2;
        }

        self.list.push(last);
        last
    }
    pub fn is_prime(&self, num: u64) -> bool {
        let root = (num as f64).sqrt() as u64;

        for prime in self.list.iter() {
            if *prime > root {
                return true;
            }
            if (num % *prime) == 0 {
                return false;
            }
        }

        true
    }
    pub fn nth(&mut self, n: usize) -> u64 {
        while self.list.len() < n {
            self.next();
        }

        self.list[n-1]
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
    assert!(p.nth(11) == 31);
    assert!(p.nth(12) == 37);
}
