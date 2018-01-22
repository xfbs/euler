extern crate euler;
use euler::ToDigits;
use std::collections::HashSet;

pub fn solve() -> u32 {
    // try every two numbers to see if they and their product make a pandigital
    // triplet. the resulting products are collected into a HashSet, which takes
    // care of deduplication (since multiple (a, b, p) triplets might have the
    // same p), and the result is the sum of the deduplicated contents.
    (0u32..100)
        .flat_map(|a| (0u32..10000).filter_map(move |b| pandigital_product(a, b)))
        .collect::<HashSet<u32>>()
        .iter()
        .sum()
}

pub fn pandigital_product(a: u32, b: u32) -> Option<u32> {
    let product = a * b;
    let mut digits = [false; 10];

    for &num in [a, b, product].iter() {
        for digit in num.digits() {
            if digits[digit as usize] {
                return None;
            } else {
                digits[digit as usize] = true;
            }
        }
    }

    if digits[0] == true || digits.iter().skip(1).any(|&n| n != true) {
        return None;
    }

    Some(product)
}

#[test]
fn test_pandigital_product() {
    assert_eq!(pandigital_product(1, 1), None);
    assert_eq!(pandigital_product(39, 186), Some(7254));
    assert_eq!(pandigital_product(40, 186), None);
    assert_eq!(pandigital_product(38, 186), None);
    assert_eq!(pandigital_product(39, 185), None);
    assert_eq!(pandigital_product(39, 187), None);
}
