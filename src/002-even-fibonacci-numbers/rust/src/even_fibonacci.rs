pub struct EvenFibonacci {
    // only need to keep track of
    // current fibonacci number
    curr: u32,
}

// to generate a new fibonacci iterator
impl EvenFibonacci {
    pub fn new() -> EvenFibonacci {
        // use 2 as starting number
        // because it's first even one
        EvenFibonacci { curr: 2 }
    }
}

// phi (golden ratio)
const PHI: f64 = 1.61803398875;
const PHI3: f64 = PHI * PHI * PHI;

// implement next so we can use it like an iterator
impl Iterator for EvenFibonacci {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        let saved = self.curr;
        // each multiplication with phi proceeds
        // to next fibonacci number, so multiplication
        // with phi^3 proceeds to next even number
        self.curr = ((saved as f64) * PHI3).round() as u32;
        Some(saved)
    }
}

#[test]
fn even_fibo_works() {
    let mut f = EvenFibonacci::new();

    assert!(f.next().unwrap() == 2);
    assert!(f.next().unwrap() == 8);
    assert!(f.next().unwrap() == 34);
    assert!(f.next().unwrap() == 144);
    assert!(f.next().unwrap() == 610);
}

#[test]
fn all_fibos_are_even() {
    let f = EvenFibonacci::new();

    for fibo in f.take_while(|&a| a < 10000000) {
        assert!((fibo % 2) == 0);
    }
}
