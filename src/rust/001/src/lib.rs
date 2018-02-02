extern crate euler;
use euler::Lcm;

// find the sum of all numbers between 0 and max that are divisible
// by any of the two divisors
pub fn solve(max: u32, divisors: (u32, u32)) -> u32 {
    let (a, b) = divisors;

    sum(max, a) + sum(max, b) - sum(max, a.lcm(b))
}

// find the sum of all numbers that are divisible by the divisor
fn sum(max: u32, divisor: u32) -> u32 {
    // find the biggest number <= max that is divisible by divisor
    let max = max - (max % divisor);

    (max * ((max / divisor) + 1)) / 2
}

#[test]
fn sum_works() {
    assert!(sum(10, 3) == 18);
    assert!(sum(10, 5) == 15);
    assert!(sum(22, 7) == 42);
    assert!(sum(43, 51) == 0);
    assert!(sum(50, 10) == 150);
    assert!(sum(50, 25) == 75);
}

#[test]
fn solve_works() {
    assert!(solve(50, (10, 25)) == 175);
    assert!(solve(50, (25, 10)) == 175);
    assert!(solve(55, (10, 25)) == 175);
    assert!(solve(55, (25, 10)) == 175);
    assert!(solve(9, (3, 5)) == 23);
}
