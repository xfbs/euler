pub trait Palindrome : PartialEq + Clone {
    fn reversed(&self) -> Self;
    fn is_palindrome(&self) -> bool {
        *self == self.reversed()
    }
}

impl Palindrome for u32 {
    fn reversed(&self) -> u32 {
        let mut r = 0;
        let mut o = self.clone();

        while o != 0 {
            r = r * 10 + (o % 10);
            o = o / 10;
        }

        r
    }
}

#[test]
fn test_palindromes() {
    assert!(121.is_palindrome());
    assert!(32123.is_palindrome());
    assert!(11511.is_palindrome());
    assert!(923329.is_palindrome());
    assert!(23232.is_palindrome());
    assert!(55055.is_palindrome());

    assert!(!123.is_palindrome());
    assert!(!9989.is_palindrome());
    assert!(!123432.is_palindrome());
    assert!(!110.is_palindrome());
    assert!(!5243.is_palindrome());
}
