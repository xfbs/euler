pub fn solve(dim: u64) -> u64 {
    let mut sum = 1u64;
    let mut cur = 1u64;

    for ring in (2..(dim + 1)).filter(|n| n % 2 == 0) {
        cur += ring;
        sum += cur;
        cur += ring;
        sum += cur;
        cur += ring;
        sum += cur;
        cur += ring;
        sum += cur;
    }

    sum
}

#[test]
fn test_solve() {
    assert_eq!(solve(3), 25);
    assert_eq!(solve(5), 101);
}
