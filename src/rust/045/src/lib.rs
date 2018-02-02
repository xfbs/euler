pub fn triangular(n: u32) -> u64 {
    let n: u64 = n as u64;
    n * (1 + n) / 2
}

pub fn pentagonal(n: u32) -> u64 {
    let n: u64 = n as u64;
    n * (3 * n - 1) / 2
}

pub fn hexagonal(n: u32) -> u64 {
    let n: u64 = n as u64;
    n * (2 * n - 1)
}

pub fn solve(mut t: u32, mut p: u32, mut h: u32) -> u64 {
    let mut tt = triangular(t);
    let mut pp = pentagonal(p);
    let mut hh;

    loop {
        let mut is_triangular = false;
        let mut is_pentagonal = false;

        h += 1;
        hh = hexagonal(h);

        while tt <= hh {
            t += 1;
            tt = triangular(t);
            if tt == hh {
                is_triangular = true;
            }
        }

        while pp <= hh {
            p += 1;
            pp = pentagonal(p);
            if pp == hh {
                is_pentagonal = true;
            }
        }

        if is_triangular && is_pentagonal {
            return hh;
        }
    }
}

#[test]
fn test_solve() {
    assert_eq!(solve(200, 100, 100), 40755);
}
