extern crate euler;
use euler::Prime;
use euler::factorial;
use euler::permutations;

pub fn solve(digit: u8) -> u64 {
    let mut primes = Prime::new();

    for n_iter in 0..digit {
        let n = digit - n_iter;
        let fact = factorial(n as u64);

        for nth_iter in 0..fact {
            let nth = fact - nth_iter - 1;

            let num = permutations(n as usize, nth as usize)
                .map(|p| p + 1)
                .fold(0, |m, c| 10 * m + c as u64);

            if primes.check(num) {
                return num;
            }
        }
    }

    0
}

#[test]
fn test_solve() {
    let solve_4 = solve(4);
    assert!(solve_4 > 2143);

    let solve_5 = solve(5);
    assert!(solve_5 <= 54321);
    assert!(solve_4 <= solve_5);

    let solve_6 = solve(6);
    assert!(solve_6 <= 654321);
    assert!(solve_5 <= solve_6);

    let solve_7 = solve(7);
    assert!(solve_7 <= 7654321);
    assert!(solve_6 <= solve_7);

    let solve_8 = solve(8);
    assert!(solve_8 <= 87654321);
    assert!(solve_7 <= solve_8);
}
