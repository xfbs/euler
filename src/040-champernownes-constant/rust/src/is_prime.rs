pub fn is_prime(num: u64) -> bool {
    let sqrt = (num as f64).sqrt() as u64 + 1;

    for div in 2..sqrt {
        if (num % div) == 0 {
            return false;
        }
    }

    true
}

#[test]
fn is_prime_works() {
    assert!(is_prime(2));
    assert!(is_prime(3));
    assert!(is_prime(5));
    assert!(is_prime(7));
    assert!(is_prime(11));
    assert!(is_prime(13));
    assert!(is_prime(17));
    assert!(is_prime(19));
    assert!(is_prime(23));
    assert!(is_prime(29));
    assert!(is_prime(31));

    assert!(!is_prime(4));
    assert!(!is_prime(6));
    assert!(!is_prime(8));
    assert!(!is_prime(9));
    assert!(!is_prime(12));
    assert!(!is_prime(14));
    assert!(!is_prime(15));
    assert!(!is_prime(16));
    assert!(!is_prime(21));
}
