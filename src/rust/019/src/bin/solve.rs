extern crate solver;
use solver::Date;

fn main() {
    let mut start = Date::new(0, 1, 0, 1900);

    for _ in 0..12 {
        start = start.next_month();
    }

    let end = Date::new(0, 31, 11, 2000);
    println!("{}", solver::solve(start, end));
}
