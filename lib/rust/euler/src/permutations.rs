use factorial::factorial;

pub struct Permutations {
    num: u8,
    req: u64,
    cur: [bool; 20]
}

impl Iterator for Permutations {
    type Item = usize;

    fn next(&mut self) -> Option<Self::Item> {
        if self.req == 0 {
            None
        } else {
            let choice = self.req / factorial(self.num as u64);
            Some(0)
        }
    }
}

pub fn permutations(count: usize, req: usize) -> Permutations {
    Permutations {
        num: count as u8,
        req: req as u64,
        cur: [false; 20]
    }
}
