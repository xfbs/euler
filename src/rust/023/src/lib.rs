extern crate euler;
use euler::ToDivisors;

pub fn solve(max: u64) -> u64 {
    let mut possible = vec![false; max as usize];

    let abundant = (1..max)
        .filter(|n| n.divisors().sum::<u64>() > *n)
        .collect::<Vec<u64>>();

    for a in 0..abundant.len() {
        for b in a..abundant.len() {
            let sum = abundant[a] + abundant[b];

            if sum >= max {
                break;
            }

            possible[sum as usize] = true;
        }
    }

    possible
        .iter()
        .enumerate()
        .filter(|&(_, poss)| !poss)
        .map(|(index, _)| index as u64)
        .sum()
}

#[test]
fn test_solve() {
    assert_eq!(solve(10), 45);
    assert_eq!(solve(20), 190);
    assert_eq!(solve(25), 276);
    assert_eq!(solve(32), 442);
}
