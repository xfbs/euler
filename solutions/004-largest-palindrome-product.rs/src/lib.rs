trait Palindrome : PartialEq + Clone {
    fn reversed(&self) -> Self;
    fn is_palindrome(&self) -> bool {
        *self == self.reversed()
    }
}

impl Palindrome for i32 {
    fn reversed(&self) -> i32 {
        let mut r = 0;
        let mut o = self.clone();

        while o != 0 {
            r = r * 10 + (o % 10);
            o = o / 10;
        }

        r
    }
}

pub fn solve() -> i32 {
    (100..1000).map(|i|
        (100..1000).map(|j|
            i*j).filter(|p|
                p.is_palindrome()
            ).max().unwrap_or(0)
        ).max().unwrap()
}
