extern crate euler;
use euler::ToDivisors;

pub fn solve(max: u32) -> u64 {
    (1..max).map(|n| amicable(n as u64)).sum()
}

pub fn amicable(num: u64) -> u64 {
    let partner = num.divisors().sum();

    if num != partner && num == partner.divisors().sum() {
        partner
    } else {
        0
    }
}

#[test]
fn test_amicable() {
    assert_eq!(amicable(220), 284);
    assert_eq!(amicable(219), 0);
    assert_eq!(amicable(221), 0);
    assert_eq!(amicable(284), 220);
    assert_eq!(amicable(283), 0);
    assert_eq!(amicable(285), 0);
}

#[test]
fn test_solution() {
    assert_eq!(solve(285), 220 + 284);
}
