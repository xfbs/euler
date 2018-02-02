pub fn solve(max: u32) -> u64 {
    for i in 1.. {
        let difference = pentagonal(i);

        for n in (1..).take_while(|&n| is_candidate(difference, n)) {
            if is_valid(difference, n) {
                let x = get_x(difference, n);

                if is_pentagonal(pentagonal(x) + pentagonal(x + n)) {
                    return difference;
                }
            }
        }
    }

    0
}

/// Checks if `n` is a candidate for a valid offset difference of `difference`.
///
/// Returns `true` if `n` is small enough such that `p(x + n) - p(x) = difference`
/// could be valid.
pub fn is_candidate(difference: u64, n: u64) -> bool {
    pentagonal_b(n) <= difference
}

/// Checks if `n` is a valid offset difference for `difference`.
///
/// Returns `true` if `p(x + n) - p(x) = difference` is solvable.
pub fn is_valid(difference: u64, n: u64) -> bool {
    (difference - pentagonal_b(n)) % (3 * n) == 0
}

/// Solves for `x` given a pentagonal difference and n.
///
/// Assuming that `n` is a valid pentagonal offset and the difference is
/// `difference`, solves `p(x + n) - p(x) = difference` for x.
pub fn get_x(difference: u64, n: u64) -> u64 {
    (difference - pentagonal_b(n)) / (3 * n) + 1
}

/// Computes the `x`th pentagonal number.
///
/// # Examples
///
/// ```
/// # use solver::*;
/// assert_eq!(pentagonal(1), 1);
/// assert_eq!(pentagonal(2), 5);
/// ```
pub fn pentagonal(x: u64) -> u64 {
    x * (3 * x).saturating_sub(1) / 2
}

/// Computes the pentagonal function inverse.
///
/// For a given pentagonal number `y`, it computes what the input `x` to the
/// `pentagonal()` function must be to generate it.
///
/// # Examples
///
/// ```
/// # use solver::*;
/// assert_eq!(pentagonal_inverse(35), 5);
/// assert_eq!(pentagonal_inverse(pentagonal(9)), 9);
/// ```
pub fn pentagonal_inverse(y: u64) -> u64 {
    let y = y as f64;
    let x = (1.0 / 6.0) + ((1.0 / 36.0) + (2.0 / 3.0) * y).sqrt();
    x.round() as u64
}

/// Checks if a given number is a pentagonal number.
///
/// # Examples
///
/// ```
/// # use solver::*;
/// assert!(is_pentagonal(12));
/// assert!(is_pentagonal(pentagonal(32)));
/// assert!(!is_pentagonal(4));
/// ```
pub fn is_pentagonal(y: u64) -> bool {
    pentagonal(pentagonal_inverse(y)) == y
}

/// Pentagonal difference function.
///
/// This function can be used to check if a given `n` is a valid pentagonal
/// offset between two pentagonal numbers, and compute all possible `x`.
///
/// It holds the invariant `p(x + n) - p(x) = b(n) + 3n(x-1)`.
pub fn pentagonal_b(x: u64) -> u64 {
    (3 * x * x + 5 * x) / 2
}

#[test]
fn test_pentagonal() {
    assert_eq!(pentagonal(0), 0);
    assert_eq!(pentagonal(1), 1);
    assert_eq!(pentagonal(2), 5);
    assert_eq!(pentagonal(3), 12);
    assert_eq!(pentagonal(4), 22);
    assert_eq!(pentagonal(5), 35);
    assert_eq!(pentagonal(6), 51);
    assert_eq!(pentagonal(7), 70);
    assert_eq!(pentagonal(8), 92);
    assert_eq!(pentagonal(9), 117);
    assert_eq!(pentagonal(10), 145);
}

#[test]
fn test_pentagonal_inverse() {
    assert_eq!(pentagonal_inverse(0), 0);
    assert_eq!(pentagonal_inverse(1), 1);
    assert_eq!(pentagonal_inverse(5), 2);
    assert_eq!(pentagonal_inverse(12), 3);
    assert_eq!(pentagonal_inverse(22), 4);
    assert_eq!(pentagonal_inverse(35), 5);
    assert_eq!(pentagonal_inverse(51), 6);
    assert_eq!(pentagonal_inverse(70), 7);
    assert_eq!(pentagonal_inverse(92), 8);
    assert_eq!(pentagonal_inverse(117), 9);
    assert_eq!(pentagonal_inverse(145), 10);
}

#[test]
fn test_is_pentagonal() {
    assert!(is_pentagonal(0));
    assert!(is_pentagonal(1));
    assert!(is_pentagonal(5));
    assert!(is_pentagonal(12));
    assert!(is_pentagonal(22));
    assert!(is_pentagonal(35));
    assert!(is_pentagonal(51));
    assert!(is_pentagonal(70));
    assert!(is_pentagonal(92));

    assert!(!is_pentagonal(2));
    assert!(!is_pentagonal(4));
    assert!(!is_pentagonal(13));
    assert!(!is_pentagonal(25));
    assert!(!is_pentagonal(32));
    assert!(!is_pentagonal(50));
    assert!(!is_pentagonal(71));
    assert!(!is_pentagonal(90));
    assert!(!is_pentagonal(120));
    assert!(!is_pentagonal(150));
}
