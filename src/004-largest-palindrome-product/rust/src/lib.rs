mod palindrome;
use palindrome::Palindrome;

pub fn solve() -> i32 {
    (100..1000).map(|i|
        (100..1000).map(|j|
            i*j).filter(|p|
                p.is_palindrome()
            ).max().unwrap_or(0)
        ).max().unwrap()
}
