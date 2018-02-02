pub fn solve(max: u32) -> u32 {
    (1..(max + 1))
        .map(|p| (p, solutions_count(p)))
        .max_by_key(|t| t.1)
        .unwrap()
        .0
}

pub fn solutions_count(p: u32) -> u32 {
    let p: i32 = p as i32;
    (1..(p / 3))
        .filter(|a| ((p * (2 * a - p)) % (2 * (a - p))) == 0)
        .count() as u32
}

#[test]
fn test_solutions_count() {
    assert_eq!(solutions_count(120), 3);
    assert_eq!(solutions_count(12), 1);
}

#[test]
fn test_solve() {
    assert_eq!(solve(12), 12);
}
