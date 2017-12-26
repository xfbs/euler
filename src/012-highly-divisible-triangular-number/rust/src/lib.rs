extern crate euler;
use euler::prime::Prime;

pub fn solve(max: u32) -> u32 {
    let mut triangle = 1;
    let mut index = 1;
    let mut primes = Prime::new();

    while factors(&mut primes, triangle) <= max {
        index += 1;
        triangle += index;
    }

    triangle
}

fn factors(primes: &mut Prime, num: u32) -> u32 {
    let mut num = num;
    let mut count = 1;
    let mut cur = 1;

    while num != 1 {
        let mut factors = 1;
        let prime = primes.nth(cur);

        while (num % (prime as u32)) == 0 {
            factors += 1;
            num /= prime as u32;
        }

        count *= factors;
        cur += 1;
    }

    count
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 3);
    assert_eq!(solve(2), 6);
    assert_eq!(solve(4), 28);
}

#[test]
fn test_factors() {
    let mut p = Prime::new();

    assert_eq!(factors(&mut p, 1), 1);
    assert_eq!(factors(&mut p, 2), 2);
    assert_eq!(factors(&mut p, 3), 2);
    assert_eq!(factors(&mut p, 4), 3);
    assert_eq!(factors(&mut p, 5), 2);
    assert_eq!(factors(&mut p, 6), 4);
    assert_eq!(factors(&mut p, 7), 2);
    assert_eq!(factors(&mut p, 8), 4);
    assert_eq!(factors(&mut p, 9), 3);
    assert_eq!(factors(&mut p, 10), 4);
    assert_eq!(factors(&mut p, 15), 4);
    assert_eq!(factors(&mut p, 21), 4);
    assert_eq!(factors(&mut p, 28), 6);
}
