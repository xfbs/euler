extern crate euler;
use euler::GcdLcm;

pub fn solve() -> u64 {
    let mut num = 1;
    let mut den = 1;

    for a in 0..10 {
        for b in 0..10 {
            for c in 0..10 {
                for d in 0..10 {
                    if check_fraction(a, b, c, d) {
                        num *= 10 * a as u64 + b as u64;
                        den *= 10 * c as u64 + d as u64;

                        let gcd = num.gcd(den);
                        num /= gcd;
                        den /= gcd;
                    }
                }
            }
        }
    }

    den
}

fn check_fraction(a: u8, b: u8, c: u8, d: u8) -> bool {
    let num = 10.0 * a as f64 + b as f64;
    let den = 10.0 * c as f64 + d as f64;
    let frac = num / den;

    if 0.0 < frac && frac <= 1.0 {
        let one = (b == c) && frac == (a as f64 / d as f64);
        let two = (a == d) && frac == (b as f64 / c as f64);

        one || two
    } else {
        false
    }
}

#[test]
fn test_check_fraction() {
    assert!(check_fraction(4, 9, 9, 8));
    assert!(!check_fraction(3, 0, 5, 0));
}
