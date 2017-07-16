pub fn solve(max: i32) -> i32 {
    let square_of_sums = (max.pow(2) * (max + 1).pow(2)) / 4;
    let sum_of_squares = (max * (max + 1) * (2 * max + 1)) / 6;

    square_of_sums - sum_of_squares
}
