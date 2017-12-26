mod prime;
use prime::Prime;

pub fn solve(nth: usize) -> u64 {
    let mut p = Prime::new();
    p.nth(nth)
}

#[test]
fn test_solve() {
    assert!(solve(1) == 2);
    assert!(solve(2) == 3);
    assert!(solve(3) == 5);
    assert!(solve(4) == 7);
    assert!(solve(5) == 11);
    assert!(solve(6) == 13);
}
