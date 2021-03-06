pub fn solve(n: u32) -> u32 {
    (3 * n.pow(4) + 2 * n.pow(3) - 3 * n.pow(2) - 2 * n) / 12
}

#[test]
fn solve_works() {
    assert!(solve(10) == 2640);
}
