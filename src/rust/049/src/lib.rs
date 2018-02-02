extern crate euler;
use euler::ToDigits;
use euler::Prime;

pub fn solve(avoid: u64) -> u64 {
    let mut primes = Prime::new();

    let four_digit_primes: Vec<u64> = primes
        .into_iter()
        .filter(|&p| 1000 <= p)
        .filter(|&p| p != avoid)
        .take_while(|&p| p < 10000)
        .collect();

    for (index, first) in four_digit_primes.iter().enumerate() {
        for second in &four_digit_primes[index + 1..] {
            let third = 2 * *second - *first;
            if third < 10000 && permutation(*first, *second) {
                if permutation(*second, third) && primes.check(third) {
                    return 10000 * (10000 * *first + second) + third;
                }
            }
        }
    }

    0
}

fn permutation(a: u64, b: u64) -> bool {
    let mut a: Vec<u64> = a.digits().collect();
    let mut b: Vec<u64> = b.digits().collect();

    a.sort();
    b.sort();

    a == b
}

#[test]
fn test_permutations() {
    assert!(permutation(1234, 4321));
    assert!(permutation(2313, 2331));
    assert!(permutation(8459, 4985));

    assert!(!permutation(3245, 3354));
    assert!(!permutation(1234, 2345));
}

#[test]
fn test_solve() {
    assert!(solve(0) == 148748178147);
}
