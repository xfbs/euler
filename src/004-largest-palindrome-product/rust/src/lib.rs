mod palindrome;
use palindrome::Palindrome;

pub fn solve(n: u8) -> u32 {
    let min = 10_u32.pow((n-1) as u32);
    let max = 10_u32.pow(n as u32);
    (min..max).map(|i|
        (min..max).map(|j|
            i*j).filter(|p|
                p.is_palindrome()
            ).max().unwrap_or(0)
        ).max().unwrap()
}

#[test]
fn test_solve() {
    assert!(solve(2) == 9009);
}
