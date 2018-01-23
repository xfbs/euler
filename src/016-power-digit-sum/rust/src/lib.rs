pub fn solve(exp: usize) -> u64 {
    let mut num: Vec<u8> = vec![1];

    for _ in 0..exp {
        let mut carry = 0;

        for d in num.iter_mut() {
            let cur = 2 * (*d as u64) + carry;
            *d = (cur % 10) as u8;
            carry = cur / 10;
        }

        if carry != 0 {
            num.push(carry as u8);
        }
    }

    num.iter().map(|n| *n as u64).sum()
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 2);
    assert_eq!(solve(2), 4);
    assert_eq!(solve(3), 8);
    assert_eq!(solve(4), 1 + 6);
    assert_eq!(solve(5), 3 + 2);
    assert_eq!(solve(6), 6 + 4);
    assert_eq!(solve(7), 1 + 2 + 8);
    assert_eq!(solve(8), 2 + 5 + 6);
    assert_eq!(solve(9), 5 + 1 + 2);
    assert_eq!(solve(10), 1 + 0 + 2 + 4);
    assert_eq!(solve(11), 2 + 0 + 4 + 8);
}
