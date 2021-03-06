extern crate euler;
use euler::factorial;

// FIXME: rewrite using euler::permutations
pub fn solve(n: usize) -> u64 {
    let v = nth_permutation(vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9], n - 1);
    v.iter().fold(0, |m, c| (m * 10) + (*c as u64))
}

fn nth_permutation(mut arr: Vec<u8>, mut n: usize) -> Vec<u8> {
    let mut result = vec![];

    while arr.len() > 0 {
        let permutations = factorial(arr.len() as u64 - 1).unwrap() as usize;
        result.push(arr.remove(n / permutations));
        n %= permutations;
    }

    result
}

#[test]
fn test_nth_permutation() {
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 0), vec![1, 2, 3, 4]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 1), vec![1, 2, 4, 3]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 2), vec![1, 3, 2, 4]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 3), vec![1, 3, 4, 2]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 4), vec![1, 4, 2, 3]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 5), vec![1, 4, 3, 2]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 6), vec![2, 1, 3, 4]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 7), vec![2, 1, 4, 3]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 8), vec![2, 3, 1, 4]);
    assert_eq!(nth_permutation(vec![1, 2, 3, 4], 9), vec![2, 3, 4, 1]);
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 123456789);
    assert_eq!(solve(2), 123456798);
    assert_eq!(solve(3), 123456879);
    assert_eq!(solve(4), 123456897);
}
