mod is_prime;
use is_prime::is_prime;

pub fn solve(num: u64) -> u64 {
    let mut prime = 2;
    let mut cur = num;

    while !is_prime(cur) {
        while cur != prime && (cur % prime) == 0 {
            cur /= prime;
        }

        prime += 1;
        while !is_prime(prime) {
            prime += 1;
        }
    }

    cur
}

#[test]
fn solve_works() {
    assert!(solve(2) == 2);
    assert!(solve(6) == 3);
    assert!(solve(15) == 5);
    assert!(solve(32) == 2);
    assert!(solve(31) == 31);
    assert!(solve(39) == 13);
}
