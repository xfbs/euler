mod even_fibonacci;
use even_fibonacci::EvenFibonacci;

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

