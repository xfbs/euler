pub fn solve(n: u32) -> u32 {
    (0..n)
        .map(|e| champernowne_digit(10u32.pow(e) - 1))
        .fold(1u32, |m, c| m * c)
}

pub fn champernowne_digit(nth: u32) -> u32 {
    let mut pos = nth;
    let mut mag = 1;
    let mut exp = 9;

    while pos >= (mag * exp) {
        pos -= mag * exp;
        exp *= 10;
        mag += 1;
    }

    let off = mag - (pos % mag) - 1;
    let num = (exp / 9 + pos / mag) / 10u32.pow(off);

    num % 10
}

#[test]
fn test_champernowne() {
    assert_eq!(champernowne_digit(0), 1);
    assert_eq!(champernowne_digit(1), 2);
    assert_eq!(champernowne_digit(2), 3);
    assert_eq!(champernowne_digit(3), 4);
    assert_eq!(champernowne_digit(4), 5);
    assert_eq!(champernowne_digit(5), 6);
    assert_eq!(champernowne_digit(6), 7);
    assert_eq!(champernowne_digit(7), 8);
    assert_eq!(champernowne_digit(8), 9);
    assert_eq!(champernowne_digit(9), 1);
    assert_eq!(champernowne_digit(10), 0);
    assert_eq!(champernowne_digit(11), 1);
    assert_eq!(champernowne_digit(12), 1);
    assert_eq!(champernowne_digit(13), 1);
    assert_eq!(champernowne_digit(14), 2);
    assert_eq!(champernowne_digit(15), 1);
    assert_eq!(champernowne_digit(16), 3);
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 1);
    assert_eq!(solve(2), 1);
    assert_eq!(solve(3), 5);
    assert_eq!(solve(4), 15);
}
