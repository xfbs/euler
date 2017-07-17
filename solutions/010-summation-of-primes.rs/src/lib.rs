extern crate bit_vec;
use bit_vec::BitVec;

pub fn solve(n: u64) -> u64 {
    let primes = sieve(n);

    primes.iter()
        .filter(|&p| *p < n)
        .fold(0, |s,n| s+n)
}

pub fn sieve(n: u64) -> Vec<u64> {
    let mut s = BitVec::from_elem((n+1) as usize, true);
    s.set(0, false);
    s.set(1, false);

    let mut p: u64 = 2;
    while (p*p) <= n {
        for f in p..((n/p)+1) {
            s.set((f*p) as usize, false);
        }

        while {
            p = p + 1;
            s.get(p as usize).unwrap() == false
        } {}
    }

    let mut r: Vec<u64> = Vec::new();

    for i in 0..s.len() {
        if s.get(i).unwrap() == true {
            r.push(i as u64);
        }
    }

    r
}