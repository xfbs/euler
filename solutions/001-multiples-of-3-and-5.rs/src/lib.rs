// find the sum of all numbers between 0 and max that are divisible
// by any of the two divisors
pub fn solve(max: u32, divisors: (u32, u32)) -> u32 {
    let (a, b) = divisors;

    sum(max, a) + sum(max, b) - sum(max, a*b)
}

// find the sum of all numbers that are divisible by the divisor
fn sum(max: u32, divisor: u32) -> u32 {
    // find the biggest number <= max that is divisible by divisor
    let max = max - (max % divisor);

    (max * ((max/divisor) + 1)) / 2
}

#[test]
fn sum_works() {
    //..
}
