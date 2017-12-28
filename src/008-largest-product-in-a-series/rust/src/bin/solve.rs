extern crate solver;
use std::fs::File;
use std::env::args;
use std::io::Read;

fn main() {
    // extract filename from arguments
    let file = args().nth(1).unwrap();

    // open file and extract sequence by iterating through bytes, ignoring
    // newlines and turning numbers into u8s
    let datafile = File::open(file).unwrap();
    let sequence = datafile
        .bytes()
        .map(|b| b.unwrap())
        .filter(|b| *b != ('\n' as u8))
        .map(|b| b - ('0' as u8))
        .collect::<Vec<u8>>();

    println!("{}", solver::solve(sequence, 13));
}
