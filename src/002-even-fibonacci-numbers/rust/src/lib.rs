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

#[test]
fn test_solve() {
    assert!(solve(3) == 2);
    assert!(solve(4) == 2);
    assert!(solve(5) == 2);
    assert!(solve(6) == 2);
    assert!(solve(7) == 2);
    assert!(solve(8) == 2);
    assert!(solve(9) == 2+8);
    assert!(solve(10) == 2+8);
    assert!(solve(11) == 2+8);
    assert!(solve(12) == 2+8);
    assert!(solve(35) == 2+8+34);
    assert!(solve(40) == 2+8+34);
    assert!(solve(50) == 2+8+34);
    assert!(solve(144) == 2+8+34);
    assert!(solve(145) == 2+8+34+144);
}
