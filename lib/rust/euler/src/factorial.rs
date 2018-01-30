pub fn factorial(n: u64) -> u64 {
    (1..n + 1).fold(1, |p, n| p * n)
}

#[test]
fn test_factorial() {
    assert_eq!(factorial(0), 1);
    assert_eq!(factorial(1), 1);
    assert_eq!(factorial(2), 2);
    assert_eq!(factorial(3), 6);
    assert_eq!(factorial(4), 24);
    assert_eq!(factorial(5), 120);
    assert_eq!(factorial(6), 720);
    assert_eq!(factorial(7), 5040);
    assert_eq!(factorial(8), 40320);
}
