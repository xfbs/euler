extern crate solver;
use std::io::{BufReader,BufRead};
use std::fs::File;
use std::env::args;

fn main() {
    // extract filename from arguments
    let filename = args().nth(1).unwrap();

    // extract numbers
    let datafile = File::open(filename).unwrap();
    let numbers = BufReader::new(datafile)
        .lines()
        .map(|i| i.unwrap())
        .collect::<Vec<String>>();

    println!("{}", solver::solve(numbers.as_slice(), 10));
}
