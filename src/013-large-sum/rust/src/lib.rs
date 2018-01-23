pub fn solve(nums: &[String], len: usize) -> u64 {
    let mut temp = nums.iter()
        .map(|i| i[..(len + 1)].parse::<u64>().unwrap())
        .fold(0, |m, c| m + c);

    while temp >= 10u64.pow(len as u32) {
        temp /= 10;
    }

    temp
}

#[test]
fn test_solve() {
    assert_eq!(
        solve(
            vec![String::from("12345678"), String::from("12345678")].as_slice(),
            5
        ),
        24691
    );

    assert_eq!(
        solve(
            vec![
                String::from("3414234792"),
                String::from("3414234792"),
                String::from("3414234792"),
                String::from("3414234792"),
                String::from("2341234798"),
            ].as_slice(),
            5
        ),
        15998
    );
}
