use std::cmp;

pub fn solve(n: u32) -> u32 {
    let mut triplet: (u32, u32, u32) = (0,0,0);

    // choose c so that it's not bigger than n
    for c in 1..n {
        // choose b so that it's no bigger than
        // c and so that c+b are smaller than n
        for b in 1..cmp::min(c, n-c) {
            // choose a so that a+b+c=n
            let a = n-b-c;

            // check if it's a pythagorean
            // triplet, and if so, save it
            if a.pow(2) + b.pow(2) == c.pow(2) {
                triplet = (a,b,c);
            }
        }
    }

    // return product
    triplet.0 * triplet.1 * triplet.2
}

#[test]
fn test_solve() {
    assert!(solve(3+4+5) == 3*4*5);
}
