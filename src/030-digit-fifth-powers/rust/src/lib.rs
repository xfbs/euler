use std::u32;

pub fn solve(max: u32) -> u32 {
    let fifth_powers = (0u32..10).map(|n| n.pow(5)).collect::<Vec<u32>>();

    (3..(max + 1))
        .filter(|n| is_curious(&fifth_powers, *n))
        .sum()
}

pub fn is_curious(digit_mapping: &[u32], num: u32) -> bool {
    let mut sum = 0;
    let mut cur = num;

    while sum < num && 0 < cur {
        let digit = cur % 10;
        sum += digit_mapping[digit as usize];
        cur /= 10;
    }

    (cur == 0) && (sum == num)
}

#[test]
fn test_is_curious() {
    let fourth_powers = (0u32..10).map(|n| n.pow(4)).collect::<Vec<u32>>();

    assert!(is_curious(&fourth_powers, 1634));
    assert!(is_curious(&fourth_powers, 8208));
    assert!(is_curious(&fourth_powers, 9474));
}
