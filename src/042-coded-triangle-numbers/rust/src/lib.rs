pub fn solve(words: &mut Vec<String>) -> usize {
    words.iter()
        .map(|word| worth(word))
        .filter(|worth| is_triangular_number(*worth as u64))
        .count()
}

pub fn worth(s: &str) -> usize {
    s.chars().map(|c| c as usize - 'A' as usize + 1).sum()
}

fn is_triangular_number(y: u64) -> bool {
    let x = (2.0 * y as f64).sqrt() as u64;
    y == (x * (x + 1) / 2)
}

#[test]
fn test_solve() {
    assert_eq!(solve(&mut vec!["A".to_string()]), 1);
    assert_eq!(solve(&mut vec![
                     "A".to_string(),
                     "Z".to_string(),
                     "SKY".to_string()]), 2);
}
