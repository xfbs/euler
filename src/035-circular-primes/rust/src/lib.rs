extern crate euler;
use euler::Prime;
use euler::number_rotations::Rotatable;
use std::collections::HashSet;

pub fn solve(max: u64) -> usize {
    let primes = Prime::new()
        .into_iter()
        .take_while(|n| *n < max)
        .collect::<Vec<u64>>();

    let mut rotatable = HashSet::new();

    for prime in &primes {
        if prime.rotations().all(|rot| primes.binary_search(&rot).is_ok()) {
            for rot in prime.rotations() {
                rotatable.insert(rot);
            }
        }
    }

    rotatable.iter().count()
}

#[test]
fn test_solve() {
    assert_eq!(solve(100), 13);
}
