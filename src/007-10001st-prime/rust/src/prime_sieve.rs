extern crate bit_vec;
use self::bit_vec::BitVec;
use std::cmp;

pub fn sieve(nth: u64) -> u64 {
    let mut s = BitVec::from_elem(512, true);
    s.set(0, false);
    s.set(1, false);

    // minimum bound over which to sieve (in case the
    // sieve has been expanded, we don't want to do
    // duplicate work)
    let mut min_bound: u64 = 0;

    // while we have less than nth amount of primes
    while s.iter().fold(0, |s,i| if i {s+1} else {s}) < nth {
        // double the size of the sieve
        let old_len = s.len();
        s.grow(old_len, true);

        // make sure we only sieve with primes p so
        // that p^2 is smaller than the size of the sieve
        let mut p: u64 = 2;
        while (p*p) <= (s.len() as u64) {
            for f in cmp::max(min_bound/p, p)..(((s.len()-1) as u64/p)+1) {
                s.set((f*p) as usize, false);
            }

            // find the next prime to use for sieving
            while {
                p = p + 1;
                s.get(p as usize).unwrap() == false
            } {}
        }

        min_bound = s.len() as u64;
    }

    // extract the nth prime
    let mut count = 0;
    let mut prime = 0;

    while count != nth {
        prime = prime + 1;

        if s.get(prime).unwrap() == true {
            count = count + 1;
        }
    }

    prime as u64
}
