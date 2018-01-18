pub fn divisor_sum(num: u64) -> u64 {
    let root = (num as f64).sqrt() as u64;
    let mut sum = 0;

    for div in 1..(root+1) {
        if (num % div) == 0 {
            sum += div;

            if (div != (num / div)) && div != 1 {
                sum += num / div;
            }
        }
    }

    sum
}

#[test]
fn test_divisor_sum() {
    assert_eq!(divisor_sum(2), 1);
    assert_eq!(divisor_sum(3), 1);
    assert_eq!(divisor_sum(4), 1+2);
    assert_eq!(divisor_sum(5), 1);
    assert_eq!(divisor_sum(6), 1+2+3);
    assert_eq!(divisor_sum(7), 1);
    assert_eq!(divisor_sum(8), 1+2+4);
    assert_eq!(divisor_sum(9), 1+3);
    assert_eq!(divisor_sum(10), 1+2+5);
    assert_eq!(divisor_sum(11), 1);
    assert_eq!(divisor_sum(12), 1+2+3+4+6);
    assert_eq!(divisor_sum(60), 1+2+3+4+5+6+10+12+15+20+30);
}
