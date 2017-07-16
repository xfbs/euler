struct EvenFibonacci {
    // only need to keep track of
    // current fibonacci number
    curr: u32,
}

// to generate a new fibonacci iterator
impl EvenFibonacci {
    fn new() -> EvenFibonacci {
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

pub fn solve(upper_bound: u32) -> u32 {
    // generate a new fibonacci iterator
    EvenFibonacci::new().take_while(|&a|
            // iterate as long as the numbers are
            // smaller than upper_bound
            a < upper_bound
        ).fold(0, |sum, item|
            // add them all up
            sum + item)
}

