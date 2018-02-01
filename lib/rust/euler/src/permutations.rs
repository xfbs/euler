use math::factorial;

pub struct Permutations {
    num: u8,
    req: u64,
    cur: [bool; 20]
}

impl Iterator for Permutations {
    type Item = usize;

    fn next(&mut self) -> Option<Self::Item> {
        if self.num == 0 {
            assert!(self.req == 0);
            None
        } else {
            self.num -= 1;
            let fact = factorial(self.num as u64);
            let choice = self.req / fact;
            self.req %= fact;
            let chosen = (0..20)
                .filter(|&i| !self.cur[i])
                .skip(choice as usize)
                .next()
                .unwrap();
            self.cur[chosen] = true;
            Some(chosen)
        }
    }
}

pub fn permutations(count: usize, req: usize) -> Permutations {
    Permutations {
        num: count as u8,
        req: req as u64,
        cur: [false; 20]
    }
}

#[test]
fn test_permutations() {
    type P = Vec<usize>;
    assert!(permutations(0, 0).next() == None);
    assert!(permutations(1, 0).next() == Some(0));
    assert!(permutations(1, 0).count() == 1);

    assert!(permutations(2, 0).collect::<P>() == vec![0, 1]);
    assert!(permutations(2, 1).collect::<P>() == vec![1, 0]);

    assert!(permutations(3, 0).collect::<P>() == vec![0, 1, 2]);
    assert!(permutations(3, 1).collect::<P>() == vec![0, 2, 1]);
    assert!(permutations(3, 2).collect::<P>() == vec![1, 0, 2]);
    assert!(permutations(3, 3).collect::<P>() == vec![1, 2, 0]);
    assert!(permutations(3, 4).collect::<P>() == vec![2, 0, 1]);
    assert!(permutations(3, 5).collect::<P>() == vec![2, 1, 0]);

    assert!(permutations(4, 0).collect::<P>() == vec![0, 1, 2, 3]);
    assert!(permutations(4, 6).collect::<P>() == vec![1, 0, 2, 3]);
    assert!(permutations(4, 12).collect::<P>() == vec![2, 0, 1, 3]);
    assert!(permutations(4, 18).collect::<P>() == vec![3, 0, 1, 2]);
}
