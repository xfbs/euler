pub fn solve() -> u64 {
    // for all bases between one and 10000 (base can't be bigger than this),
    // find the largest pandigital
    (1..10000)
        .filter_map(|n| pandigital_multiple(n))
        .max()
        .unwrap()
}

// for a given base, return it's pandigital (or None if none exists)
pub fn pandigital_multiple(base: u32) -> Option<u64> {
    // all digits that have already been taken
    let mut taken = [false; 10];

    // digit 0 is not allowed
    taken[0] = true;

    for n in 1..10 {
        let mut cur = base * n;

        // check the digits of cur
        while cur != 0 {
            if taken[(cur % 10) as usize] {
                return None;
            }

            taken[(cur % 10) as usize] = true;
            cur /= 10;
        }

        if n > 1 && taken == [true; 10] {
            return Some(make_pandigital_multiple(base, n as u8));
        }
    }

    None
}

pub fn make_pandigital_multiple(base: u32, n: u8) -> u64 {
    (2..(n + 1)).fold(base as u64, |pandigital, c| {
        let cur = base as u64 * c as u64;
        let mut mag = 1;

        while (cur / mag) > 0 {
            mag *= 10;
        }

        mag * pandigital + cur
    })
}

#[test]
fn test_make_pandigital_multiple() {
    assert_eq!(make_pandigital_multiple(12, 1), 12);
    assert_eq!(make_pandigital_multiple(12, 2), 1224);
    assert_eq!(make_pandigital_multiple(12, 3), 122436);
    assert_eq!(make_pandigital_multiple(1, 3), 123);
    assert_eq!(make_pandigital_multiple(99, 3), 99198297);
    assert_eq!(make_pandigital_multiple(0, 7), 0);
}

#[test]
fn test_pandigital_multiple() {
    assert_eq!(pandigital_multiple(11), None);
    assert_eq!(pandigital_multiple(12), None);
    assert_eq!(pandigital_multiple(13), None);
    assert_eq!(pandigital_multiple(14), None);

    assert_eq!(pandigital_multiple(192), Some(192384576));
    assert_eq!(pandigital_multiple(9), Some(918273645));
}
