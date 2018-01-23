use std::f64;

pub fn solve(max: u32) -> u32 {
    let phi = (1.0 + (5.0 as f64).sqrt()) / 2.0;

    let sum1 = (1.0 / 2.0) * (5.0 as f64).log(phi);
    let sum2 = ((max - 1) as f64) * (10.0 as f64).log(phi);
    (sum1 + sum2).ceil() as u32
}

#[test]
fn test_solve() {
    assert_eq!(solve(2), 7);
    assert_eq!(solve(3), 12);
    assert_eq!(solve(4), 17);
    assert_eq!(solve(5), 21);
    assert_eq!(solve(6), 26);
    assert_eq!(solve(7), 31);
    assert_eq!(solve(8), 36);
}
