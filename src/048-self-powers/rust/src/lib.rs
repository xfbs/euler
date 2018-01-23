pub fn solve(max: u32, digits: u32) -> u64 {
    let m = 10u64.pow(digits);

    (1..(max + 1)).fold(0u64, |memo, c| (memo + pow(c as u64, c as u64, m)) % m)
}

fn pow(n: u64, e: u64, m: u64) -> u64 {
    match e {
        0 => 1u64,
        1 => n % m,
        e => {
            if e % 2 == 0 {
                pow(mult(n, n, m), e / 2, m) % m
            } else {
                mult(pow(mult(n, n, m), e / 2, m) % m, n, m)
            }
        }
    }
}

fn mult(a: u64, b: u64, m: u64) -> u64 {
    let pow32 = 2u64.pow(32);
    let ah = a / pow32;
    let bh = b / pow32;
    let al = a % pow32;
    let bl = b % pow32;

    let mut res = al * bl;
    res %= m;
    res += shift(ah * bl % m, 32u8, m);
    res %= m;
    res += shift(bh * al % m, 32u8, m);
    res %= m;
    res += shift(ah * bh % m, 64u8, m);

    res % m
}

fn shift(n: u64, a: u8, m: u64) -> u64 {
    if a == 0 {
        n % m
    } else {
        shift((n << 1) % m, a - 1, m)
    }
}

#[test]
fn test_mult() {
    assert_eq!(mult(3456, 30, 120000), 3456 * 30);
    assert_eq!(mult(3456, 30, 10000), 3680);
}

#[test]
fn test_pow() {
    assert_eq!(pow(7, 0, 2), 1);
    assert_eq!(pow(7, 1, 2), 1);
    assert_eq!(pow(7, 1, 9), 7);
    assert_eq!(pow(7, 9, 2), 1);
    assert_eq!(pow(6, 2, 8), 4);
    assert_eq!(pow(7, 1, 432), 7);
    assert_eq!(pow(7, 2, 432), 49);
    assert_eq!(pow(7, 3, 432), 343);
    assert_eq!(pow(7, 4, 432), 241);
    assert_eq!(pow(7, 5, 432), 391);
}

#[test]
fn test_shift() {
    assert_eq!(shift(12, 0, 10), 2);
    assert_eq!(shift(12, 1, 10), 4);
    assert_eq!(shift(12, 2, 10), 8);
    assert_eq!(shift(12, 3, 10), 6);
    assert_eq!(shift(342384230, 13, 34039234), 12769794);
}

#[test]
fn test_solve() {
    assert_eq!(
        solve(5, 10),
        1 + 2 * 2 + 3 * 3 * 3 + 4 * 4 * 4 * 4 + 5 * 5 * 5 * 5 * 5
    );
    assert_eq!(
        solve(5, 3),
        (1 + 2 * 2 + 3 * 3 * 3 + 4 * 4 * 4 * 4 + 5 * 5 * 5 * 5 * 5) % 1000
    );
    assert_eq!(
        solve(5, 2),
        (1 + 2 * 2 + 3 * 3 * 3 + 4 * 4 * 4 * 4 + 5 * 5 * 5 * 5 * 5) % 100
    );
    assert_eq!(
        solve(5, 1),
        (1 + 2 * 2 + 3 * 3 * 3 + 4 * 4 * 4 * 4 + 5 * 5 * 5 * 5 * 5) % 10
    );
}
