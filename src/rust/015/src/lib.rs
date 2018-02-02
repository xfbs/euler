struct LatticePaths {
    paths: Vec<Vec<u64>>,
}

impl LatticePaths {
    pub fn new(x: usize, y: usize) -> Self {
        let (x, y) = if x < y { (x, y) } else { (y, x) };
        LatticePaths {
            paths: vec![vec![0; y + 1]; x + 1],
        }
    }

    pub fn count(&mut self, x: usize, y: usize) -> u64 {
        let (x, y) = if x < y { (x, y) } else { (y, x) };

        if x == 0 {
            return 1;
        }

        if x == 1 {
            return (y + 1) as u64;
        }

        if x == 2 {
            return ((y + 1) * (y + 2) / 2) as u64;
        }

        if x < self.paths.len() && y < self.paths[x].len() {
            if self.paths[x][y] != 0 {
                return self.paths[x][y];
            }
        }

        let res = self.count(x - 1, y) + self.count(x, y - 1);

        if x < self.paths.len() && y < self.paths[x].len() {
            self.paths[x][y] = res;
        }

        res
    }
}

pub fn solve(xy: usize) -> u64 {
    LatticePaths::new(xy, xy).count(xy, xy)
}

#[test]
fn test_simple_paths() {
    let mut p = LatticePaths::new(10, 10);

    assert_eq!(p.count(0, 0), 1);

    assert_eq!(p.count(4, 0), 1);
    assert_eq!(p.count(2, 0), 1);
    assert_eq!(p.count(9, 0), 1);
    assert_eq!(p.count(3, 0), 1);

    assert_eq!(p.count(4, 1), 5);
    assert_eq!(p.count(1, 1), 2);
    assert_eq!(p.count(8, 1), 9);

    assert_eq!(p.count(1, 4), 5);
    assert_eq!(p.count(1, 8), 9);
    assert_eq!(p.count(1, 2), 3);
    assert_eq!(p.count(1, 6), 7);
}

#[test]
fn test_harder_paths() {
    let mut p = LatticePaths::new(10, 10);

    assert_eq!(p.count(2, 2), 6);
    assert_eq!(p.count(2, 3), 10);
    assert_eq!(p.count(3, 2), 10);
    assert_eq!(p.count(5, 3), 56);
    assert_eq!(p.count(4, 4), 70);
    assert_eq!(p.count(3, 4), 35);
}

#[test]
fn test_big_nums() {
    let mut p = LatticePaths::new(10, 10);

    assert_eq!(p.count(4, 6), 210);
    assert_eq!(p.count(5, 5), 252);
    assert_eq!(p.count(8, 4), 495);
    assert_eq!(p.count(5, 7), 792);

    let mut big = LatticePaths::new(20, 20);
    assert_eq!(big.count(20, 16), 7307872110);
}
