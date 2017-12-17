extern crate gcd_lcm;

pub fn solve(max: u32) -> u32 {
    (1..(max+1)).fold(1, |a, b| gcd_lcm::lcm(a, b))
}

#[test]
fn test_solve() {
    assert!(solve(2) == 2);
    assert!(solve(3) == 6);
    assert!(solve(4) == 12);
    assert!(solve(5) == 60);
    assert!(solve(6) == 60);
}
