pub fn solve(sequence: Vec<u8>, length: usize) -> u64 {
    // step one: find the earliest sequence of non-zero numbers with the
    // specified length. offset denotes the start of this sequence. product is
    // the product of the numbers in this sequence.

    let (offset, product) = sequence
        .iter()
        .enumerate()
        .fold((0, 1u64), |(offset, product), (index, num)|
              if (index - offset) >= length {
                  (offset, product)
              } else if *num == 0 {
                  (index + 1, 1)
              } else {
                  (offset, product * (*num as u64))
              });

    // step two: iterate through the rest of the sequence. when we encounter
    // zeroes, we flag this by raising the zeroes counter until we have moved
    // past the zero, and ignoring the product until then. we keep track of the
    // biggest products seen in max.
    let (max, _, _) = (0..sequence.len().saturating_sub(length+offset))
        .fold((product, product, 0i64), |(max, mut product, mut zeroes), i| {
              let out = sequence[i+offset];
              let cur = sequence[i+offset+length];

              if out == 0 {
                  zeroes += 1;
              } else {
                  product = product / (out as u64);
              }

              if cur == 0 {
                  zeroes -= 1;
              } else {
                  product = product * (cur as u64);
              }

              (if product > max && zeroes == 0 {product} else {max},
               product,
               zeroes)
        });

    if (sequence.len() - offset) < length {
        0
    } else {
        max
    }
}

#[test]
fn test_solve() {
    assert_eq!(solve(vec![], 0), 1);
    assert_eq!(solve(vec![1], 0), 1);
    assert_eq!(solve(vec![1,2], 0), 1);
    assert_eq!(solve(vec![1,2,3], 0), 1);
    assert_eq!(solve(vec![1,2,3,2,4,0,7,1,2,8,9,2,3], 0), 1);
    assert_eq!(solve(vec![0,0,0], 0), 1);

    // invalid: string empty
    assert_eq!(solve(vec![], 1), 0);
    assert_eq!(solve(vec![], 2), 0);
    assert_eq!(solve(vec![], 3), 0);
    assert_eq!(solve(vec![], 4), 0);

    // invalid: string too short
    assert_eq!(solve(vec![1,2,3], 4), 0);
    assert_eq!(solve(vec![1,2,3,2,4,2], 10), 0);
    assert_eq!(solve(vec![1], 4), 0);
    assert_eq!(solve(vec![1,2,2,3,4,1,8,6,3], 12), 0);

    // valid
    assert_eq!(solve(vec![1,2,3], 3), 6);
    assert_eq!(solve(vec![1,2,3,0,1,2,3,4,0,1,2,3], 4), 1*2*3*4);
    assert_eq!(solve(vec![0,9,7,5,4,9,0,8,7,2,4,9,9,8,3], 3), 9*9*8);
    assert_eq!(solve(vec![1,2,3,4,5,6,7,8,9], 7), 9*8*7*6*5*4*3);

    // embedded zeroes
    assert_eq!(solve(vec![9,9,0,9,9,0,9,9], 3), 0);
    assert_eq!(solve(vec![9,9,0,9,9,0,9,9], 4), 0);
    assert_eq!(solve(vec![9,9,0,9,9,0,9,9], 2), 9*9);
    assert_eq!(solve(vec![9,3,4,1,9,1,0,1,2], 7), 0);
}
