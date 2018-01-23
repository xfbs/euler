pub fn solve(value: u32) -> usize {
    let coins = vec![200, 100, 50, 20, 10, 5, 2, 1];
    change(&coins, value, 0)
}

pub fn change(coins: &Vec<u32>, value: u32, pos: usize) -> usize {
    if value == 0 || (pos + 1) == coins.len() {
        if value % coins.last().unwrap() == 0 {
            1
        } else {
            0
        }
    } else {
        (0..(value / coins[pos] + 1))
            .map(|n| change(coins, value - n * coins[pos], pos + 1))
            .sum()
    }
}

#[test]
fn test_change() {
    assert_eq!(change(&vec![1], 5, 0), 1);
    assert_eq!(change(&vec![1], 2, 0), 1);

    assert_eq!(change(&vec![2, 1], 1, 0), 1);
    assert_eq!(change(&vec![2, 1], 2, 0), 2);
    assert_eq!(change(&vec![2, 1], 3, 0), 2);
    assert_eq!(change(&vec![2, 1], 4, 0), 3);

    assert_eq!(change(&vec![5, 2, 1], 5, 0), 4);
    assert_eq!(change(&vec![5, 2, 1], 6, 0), 5);

    assert_eq!(change(&vec![5, 2], 1, 0), 0);
    assert_eq!(change(&vec![5, 2], 2, 0), 1);
    assert_eq!(change(&vec![5, 2], 3, 0), 0);
    assert_eq!(change(&vec![5, 2], 4, 0), 1);
    assert_eq!(change(&vec![5, 2], 5, 0), 1);
}
