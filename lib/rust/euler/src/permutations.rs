use math::factorial;

/// An iterator over the permutation of elements.
pub struct Permutations {
    num: u8,
    req: u64,
    cur: [bool; 20]
}

impl Permutations {
    /// Returns an iterator over the `nth` permutation of `count` elements.
    ///
    /// Given a count (which must be lower than 20) and `nth`, returns an
    /// iterator of length `count`, that for each position of the `nth`
    /// permutations yields which element of the original would be at that
    /// position.
    ///
    /// So for example, if the original was `[1, 2, 3, 4]` and that permutation
    /// was `[3, 1, 4, 2]`, the iterator would return `[2, 0, 3, 1]` for that
    /// permutation.
    ///
    /// You'll probably want to use `euler::permutations()` to call this
    /// function, which is more concise.
    ///
    /// ## Examples
    ///
    /// To get the `nth` permutation of an array that is `len` long, just do
    /// this:
    ///
    /// ```
    /// use euler::Permutations;
    ///
    /// let original = [1290, 2132, 3901, 4881, 5893];
    /// let nth = 94;
    /// let permuted = Permutations::of(original.len(), nth)
    ///     .map(|i| original[i])
    ///     .collect::<Vec<u32>>();
    /// assert_eq!(permuted, vec![4881, 5893, 3901, 1290, 2132]);
    /// ```
    pub fn of(count: usize, nth: usize) -> Self {
        Permutations {
            num: count as u8,
            req: nth as u64,
            cur: [false; 20]
        }
    }
}

impl Iterator for Permutations {
    type Item = usize;

    fn next(&mut self) -> Option<Self::Item> {
        if self.num == 0 {
            assert!(self.req == 0);
            None
        } else {
            self.num -= 1;
            let fact = factorial(self.num as u64).unwrap();
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

/// Returns an iterator over the `nth` permutation of `count` elements.
///
/// See `Permutations::of()` for more information.
///
/// ## Examples
///
/// ```
/// use euler::permutations;
///
/// let elements = vec![2, 4, 7, 8, 0, 1];
/// let nth = 56;
/// let permuted = permutations(elements.len(), nth)
///     .map(|pos| elements[pos])
///     .collect::<Vec<u32>>();
/// assert_eq!(permuted, vec![2, 8, 7, 0, 4, 1]);
/// ```
pub fn permutations(count: usize, nth: usize) -> Permutations {
    Permutations::of(count, nth)
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
