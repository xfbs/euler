pub fn solve(max: u32) -> u32 {
    let factorials = factorials();

    (3..(max + 1)).filter(|n| is_curious(&factorials, *n)).sum()
}

fn factorials() -> Vec<u32> {
    (0..10)
        .map(|n| (1..(n + 1)).fold(1u32, |memo, cur| memo * cur))
        .collect::<Vec<u32>>()
}

pub fn is_curious(fac: &[u32], num: u32) -> bool {
    let mut sum = 0;
    let mut cur = num;

    while sum < num && 0 < cur {
        let digit = cur % 10;
        sum += fac[digit as usize];
        cur /= 10;
    }

    (cur == 0) && (sum == num)
}

#[test]
fn test_is_curious() {
    let factorials = factorials();
    assert!(is_curious(&factorials, 145));
    assert!(!is_curious(&factorials, 9));
    assert!(!is_curious(&factorials, 19));
    assert!(!is_curious(&factorials, 10));
    assert!(!is_curious(&factorials, 12));
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 0);
    assert_eq!(solve(2), 0);
    assert_eq!(solve(3), 0);
    assert_eq!(solve(145), 145);
}

#[test]
fn test_factorials() {
    let factorials = factorials();

    assert_eq!(factorials[0], 1);
    assert_eq!(factorials[1], 1);
    assert_eq!(factorials[2], 2);
    assert_eq!(factorials[3], 6);
    assert_eq!(factorials[9], 362880);
}
