pub fn solve(words: &mut Vec<String>) -> usize {
    words.sort_unstable();
    words
        .iter()
        .enumerate()
        .map(|(index, word)| (index + 1) * worth(word))
        .sum()
}

pub fn worth(s: &str) -> usize {
    s.chars().map(|c| c as usize - 'A' as usize + 1).sum()
}

#[test]
fn test_worth() {
    assert_eq!(worth("A"), 1);
    assert_eq!(worth("B"), 2);
    assert_eq!(worth("Z"), 26);
    assert_eq!(worth("COLIN"), 53);
}

#[test]
fn test_solve() {
    assert_eq!(solve(&mut vec!["A".to_string()]), 1);
    assert_eq!(
        solve(&mut vec![
            "A".to_string(),
            "Z".to_string(),
            "COLIN".to_string(),
        ]),
        1 * 1 + 2 * 53 + 3 * 26
    );
}
