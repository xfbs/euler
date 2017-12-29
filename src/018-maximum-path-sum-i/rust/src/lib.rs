fn max_path_sum(triangle: &Vec<Vec<u8>>) -> u32 {
    if triangle.len() == 1 {
        triangle[0][0] as u32
    } else {
        let mut pos = 1;
        let mut cur: Vec<u32> = triangle[triangle.len()-pos].iter().map(|n| *n as u32).collect();
        let mut prv: Vec<u32>;

        while triangle.len() > pos {
            pos += 1;
            prv = cur;
            cur = triangle[triangle.len()-pos].iter().map(|n| *n as u32).collect();

            for i in 0..cur.len() {
                if prv[i] > prv[i+1] {
                    cur[i] = cur[i] + prv[i];
                } else {
                    cur[i] = cur[i] + prv[i+1];
                }
            }

        }

        cur[0]
    }
}

pub fn solve(triangle: &Vec<Vec<u8>>) -> u32 {
    max_path_sum(triangle)
}

#[test]
fn test_max_path_sum() {
    let vecs = vec![
        vec![1],
        vec![2, 3]];

    assert_eq!(max_path_sum(&vecs), 1+3);

    let vecs = vec![
        vec![1],
        vec![3, 3],
        vec![2, 3, 4]];

    assert_eq!(max_path_sum(&vecs), 1+3+4);
}

#[test]
fn test_solve() {
    let vecs = vec![
        vec![1],
        vec![2, 3],
        vec![4, 5, 6],
        vec![7, 7, 7, 7]];

    assert_eq!(solve(&vecs), 1+3+6+7);
}
