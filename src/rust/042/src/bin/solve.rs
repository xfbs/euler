extern crate solver;
use std::io::{BufRead, BufReader};
use std::fs::File;
use std::env::args;

fn main() {
    // extract filename from arguments
    let filename = args().nth(1).unwrap();

    // extract words, chop off quotation marks, turn into vec
    let datafile = File::open(filename).unwrap();
    let mut words = BufReader::new(datafile)
        .split(',' as u8)
        .map(|word| {
            let word = word.unwrap();
            let word = String::from_utf8(word[1..word.len() - 1].to_vec());
            word.unwrap()
        })
        .collect::<Vec<String>>();

    println!("{}", solver::solve(&mut words));
}
