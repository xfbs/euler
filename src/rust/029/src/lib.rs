pub fn solve(max_a: u32, max_b: u32) -> u32 {
    // theoretical count of powers, if they were all distinct.
    let mut count = max_a.saturating_sub(1) * max_b.saturating_sub(1);

    let mut visited = vec![false; max_a as usize - 1];

    for a in 2..(max_a + 1) {
        let mut product = a * a;
        let mut power = 2;

        while product <= max_a && !visited[product as usize - 2] {
            visited[product as usize - 2] = true;

            for b in 2..(max_b + 1) {
                let exponent = b * power;

                for lower in 1..power {
                    if exponent % lower == 0 && (exponent / lower) <= max_b {
                        count -= 1;
                        break;
                    }
                }
            }

            product *= a;
            power += 1;
        }
    }

    count
}

#[test]
fn test_solve() {
    assert_eq!(solve(2, 20), 19);
    assert_eq!(solve(3, 20), 38);
    assert_eq!(solve(4, 20), 48);
    assert_eq!(solve(5, 20), 67);
    assert_eq!(solve(6, 20), 86);
    assert_eq!(solve(7, 20), 105);
    assert_eq!(solve(8, 20), 116);
    assert_eq!(solve(9, 20), 126);
    assert_eq!(solve(10, 20), 145);
    assert_eq!(solve(11, 20), 164);
    assert_eq!(solve(12, 20), 183);

    assert_eq!(solve(100, 15), 1307);
}
