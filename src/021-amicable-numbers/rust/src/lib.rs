pub fn solve(max: u32) -> u64 {
    (1..max).map(|n| amicable(n as u64)).sum()
}

pub fn amicable(num: u64) -> u64 {
    let partner = divisor_sum(num);

    if num != partner && num == divisor_sum(partner) {
        partner
    } else {
        0
    }
}

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

#[test]
fn test_amicable() {
    assert_eq!(amicable(220), 284);
    assert_eq!(amicable(219), 0);
    assert_eq!(amicable(221), 0);
    assert_eq!(amicable(284), 220);
    assert_eq!(amicable(283), 0);
    assert_eq!(amicable(285), 0);
}

#[test]
fn test_solution() {
    assert_eq!(solve(285), 220+284);
}
