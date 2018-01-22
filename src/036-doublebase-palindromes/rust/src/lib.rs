extern crate euler;
use euler::ToPalindrome;
use euler::IsPalindrome;
use std::iter::once;

pub fn solve(max: u32) -> u32 {
    (1..)
        .map(|n| n.to_palindrome(10))
        .take_while(|&(small, big)| small < max)
        .flat_map(|(small, big)| once(small).chain(once(big)))
        .filter(|&n| n < max)
        .filter(|&n| n.is_palindrome(2))
        .sum()
}

#[test]
fn test_solve() {
    assert_eq!(solve(10), 1 + 3 + 5 + 7 + 9);
}

#[test]
fn test_is_palindrome() {
    assert!(585.is_palindrome(10));
    assert!(585.is_palindrome(2));
    assert!(!584.is_palindrome(10));
    assert!(!584.is_palindrome(2));
}
