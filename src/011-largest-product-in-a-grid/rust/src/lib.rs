pub fn solve(grid: &Vec<Vec<u8>>, len: u32) -> u64 {
    // directions - these are (x, y) pairs. they represent down, right, diagonal
    // (right), diagonal (left)
    let dirs = [(1, 0), (0, 1), (1, 1), (1, -1)];

    // for every direction, find out what the maximum product of len numbers is
    // and find the maximum of those, or 0 if none were found.
    dirs.iter()
        .map(|dir| max_product(grid, *dir, len))
        .max()
        .unwrap_or(0u64)
}

fn max_product(grid: &Vec<Vec<u8>>, dir: (i32, i32), len: u32) -> u64 {
    let (dx, dy) = dir;

    (0..grid.len()).map({|x|
        (0..grid[x].len()).map({|y|
            (0..len).fold(Some(1u64), {|m, c|
                match m {
                    None => None,
                    Some(v) => {
                        let cur_x = (x as i32) + (dx * (c as i32));
                        let cur_y = (y as i32) + (dy * (c as i32));
                        if cur_x < 0 || cur_y < 0 {
                            None
                        } else {
                            match grid.get(cur_x as usize) {
                                None => None,
                                Some(row) => match row.get(cur_y as usize) {
                                    None => None,
                                    Some(val) => Some(v * (*val as u64))
                                }
                            }
                        }
                    }
                }})
        }).filter(|n| n.is_some())
        .map(|n| n.unwrap())
        .max()
        .unwrap_or(0u64)
    }).max()
        .unwrap_or(0u64)
}

#[test]
fn test_max_product() {
    let test_vec = vec![
        vec![1, 2, 3, 4],
        vec![2, 3, 5, 7],
        vec![3, 4, 5, 6],
        vec![4, 5, 6, 7]
    ];

    assert_eq!(max_product(&test_vec, (1, 0), 1), 7);
    assert_eq!(max_product(&test_vec, (1, 0), 2), 7*6);
    assert_eq!(max_product(&test_vec, (1, 0), 3), 7*6*7);
    assert_eq!(max_product(&test_vec, (1, 0), 4), 4*7*6*7);
    assert_eq!(max_product(&test_vec, (1, 0), 5), 0);

    assert_eq!(max_product(&test_vec, (0, 1), 1), 7);
    assert_eq!(max_product(&test_vec, (0, 1), 2), 6*7);
    assert_eq!(max_product(&test_vec, (0, 1), 3), 5*6*7);
    assert_eq!(max_product(&test_vec, (0, 1), 4), 4*5*6*7);
    assert_eq!(max_product(&test_vec, (0, 1), 5), 0);

    assert_eq!(max_product(&test_vec, (1, 1), 1), 7);
    assert_eq!(max_product(&test_vec, (1, 1), 2), 5*7);
    assert_eq!(max_product(&test_vec, (1, 1), 3), 3*5*7);
    assert_eq!(max_product(&test_vec, (1, 1), 4), 1*3*5*7);
    assert_eq!(max_product(&test_vec, (1, 1), 5), 0);

    assert_eq!(max_product(&test_vec, (1, -1), 1), 7);
    assert_eq!(max_product(&test_vec, (1, -1), 2), 6*6);
    assert_eq!(max_product(&test_vec, (1, -1), 3), 5*5*7);
    assert_eq!(max_product(&test_vec, (1, -1), 4), 4*5*4*4);
    assert_eq!(max_product(&test_vec, (1, -1), 5), 0);
}

#[test]
fn test_solve() {
    let test_vec = vec![
        vec![1, 2, 3, 4],
        vec![2, 3, 5, 7],
        vec![3, 4, 5, 6],
        vec![4, 5, 6, 7]
    ];

    assert_eq!(solve(&test_vec, 1), 7);
    assert_eq!(solve(&test_vec, 2), 6*7);
    assert_eq!(solve(&test_vec, 3), 7*6*7);
    assert_eq!(solve(&test_vec, 4), 4*7*6*7);
}

