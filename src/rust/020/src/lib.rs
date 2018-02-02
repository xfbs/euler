pub fn solve(exp: usize) -> u32 {
    let mut num: Vec<u16> = vec![1];

    for i in 1..(exp + 1) {
        let mut carry = 0;

        for d in num.iter_mut() {
            let cur = (i as u64) * (*d as u64) + carry;
            *d = (cur % 10000) as u16;
            carry = cur / 10000;
        }

        if carry != 0 {
            num.push(carry as u16);
        }
    }

    num.iter()
        .map(|n| {
            (0..4)
                .fold((1, 0u32), |(e, s), _| (10 * e, s + ((*n / e) % 10) as u32))
                .1
        })
        .sum()
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 1);
    assert_eq!(solve(2), 2);
    assert_eq!(solve(3), 6);
    assert_eq!(solve(4), 2 + 4);
    assert_eq!(solve(5), 1 + 2 + 0);
    assert_eq!(solve(6), 7 + 2 + 0);
    assert_eq!(solve(7), 5 + 0 + 4 + 0);
    assert_eq!(solve(8), 4 + 0 + 3 + 2 + 0);
    assert_eq!(solve(9), 3 + 6 + 2 + 8 + 8 + 0);
    assert_eq!(solve(10), 3 + 6 + 2 + 8 + 8 + 0 + 0);
    assert_eq!(solve(11), 3 + 9 + 9 + 1 + 6 + 8 + 0 + 0);
    assert_eq!(solve(12), 4 + 7 + 9 + 0 + 0 + 1 + 6 + 0 + 0);
}
