extern crate euler;
use euler::Prime;
use std::collections::HashSet;
const FACTORS_SIZE: usize = 10240;

pub fn solve(count: u8) -> u64 {
    let mut primes = Prime::new();

    for factors_offset in (0..).map(|n| n * (FACTORS_SIZE - count as usize)) {
        let factors_max = factors_offset + FACTORS_SIZE;
        let factors = make_factors(&mut primes, factors_offset, count);

        let mut skip = 0;
        for num in factors_offset..(factors_max - count as usize) {
            if skip > 0 {
                skip -= 1;
            } else {
                let offset =
                    (0..(count as usize)).find(|&n| factors[num - factors_offset + n] != count);

                if offset == None {
                    if distinct_prime_factors(&mut primes, num as u64, count) {
                        return num as u64;
                    }
                } else {
                    skip = offset.unwrap();
                }
            }
        }
    }

    0
}

fn make_factors(primes: &mut Prime, offset: usize, count: u8) -> [u8; FACTORS_SIZE] {
    let mut factors = [0u8; FACTORS_SIZE];
    let max = offset + FACTORS_SIZE;

    primes
        .into_iter()
        .take_while(|&prime| (prime as usize) < max)
        .for_each(|prime| {
            (0..)
                .map(|n| (n * prime) as usize)
                .skip_while(|&mul| mul < offset)
                .take_while(|&mul| mul < max)
                .for_each(|mul| {
                    if factors[mul - offset] <= count {
                        factors[mul - offset] += 1;
                    }
                })
        });

    factors
}

fn distinct_prime_factors(primes: &mut Prime, start: u64, count: u8) -> bool {
    let mut prime_factors = HashSet::new();

    for num in (0..count).map(|n| n as u64 + start) {
        let mut cur = num;

        for prime in primes.into_iter() {
            let mut factor = prime;

            if cur == 1 {
                break;
            }

            if cur % factor == 0 {
                while cur % (factor * prime) == 0 {
                    factor *= prime;
                }

                if !prime_factors.insert(factor) {
                    return false;
                }

                cur /= factor;
            }
        }
    }

    prime_factors.len() == (count as usize) * (count as usize)
}

#[test]
fn test_distince_prime_factors() {
    let mut primes = Prime::new();

    assert!(distinct_prime_factors(&mut primes, 14, 2));
    assert!(distinct_prime_factors(&mut primes, 644, 3));

    assert!(!distinct_prime_factors(&mut primes, 13, 2));
    assert!(!distinct_prime_factors(&mut primes, 15, 2));
    assert!(!distinct_prime_factors(&mut primes, 14, 3));

    assert!(!distinct_prime_factors(&mut primes, 643, 3));
    assert!(!distinct_prime_factors(&mut primes, 645, 3));
    assert!(!distinct_prime_factors(&mut primes, 644, 4));
}
