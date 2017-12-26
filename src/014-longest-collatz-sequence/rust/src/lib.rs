struct CollatzLength {
    cache: Vec<u32>
}

impl CollatzLength {
    fn new(size: usize) -> CollatzLength {
        let mut cache = vec![0; size];
        cache[1] = 1;

        CollatzLength {
            cache: cache
        }
    }

    fn len(&mut self, num: u32) -> u32 {
        let mut num = num;
        let mut add = 0;

        while num > 1 && (num % 2) == 0 {
            num /= 2;
            add += 1;
        }

        let cacheable = (num as usize) < self.cache.len();

        if cacheable && self.cache[num as usize] != 0 {
            add + self.cache[num as usize]
        } else {
            let len = 1 + add + self.len(3 * num + 1);

            if cacheable {
                self.cache[num as usize] = len - add;
            }

            len
        }
    }

    fn longest(&mut self, max: u32) -> u32 {
        (1..max)
            .map(|n| (n, self.len(n as u32)))
            .max_by_key(|n| n.1)
            .unwrap().0 as u32
    }
}

pub fn solve(max: u32) -> u32 {
    let mut collatz = CollatzLength::new(max as usize);
    collatz.longest(max)
}

#[test]
fn test_collatz_length_len() {
    let mut cl = CollatzLength::new(10);
    let mut cs = CollatzLength::new(1000);

    for i in 4..30 {
        let num = (2 as u32).pow(i-1);
        assert_eq!(cl.len(num), i);
        assert_eq!(cs.len(num), i);

        if ((num - 1) % 3) == 0 && (((num - 1) / 3) % 2) == 1 {
            let num = (num-1)/3;
            assert_eq!(cl.len(num), i+1);
            assert_eq!(cs.len(num), i+1);
        }
    }

    let mut cl = CollatzLength::new(10);
    let mut cs = CollatzLength::new(1000);
    let v = vec![1, 2, 4, 8, 16, 5, 10, 20, 40, 13, 26, 52, 17, 34, 11];
    for (i, n) in v.iter().enumerate() {
        assert_eq!(cs.len(*n as u32), (i+1) as u32);
        assert_eq!(cl.len(*n as u32), (i+1) as u32);
    }

    for i in 1..500 {
        println!("i is {}", i);
        assert_eq!(cl.len(i), cs.len(i));
    }
}

#[test]
fn test_collatz_longest() {
    let mut cs = CollatzLength::new(1000);
    let maxs = vec![20, 100, 235];

    for max in maxs.iter() {
        let longest = cs.longest(*max);
        let length = cs.len(longest);

        for i in 1..(max+1) {
            if i != longest {
                assert!(cs.len(i) <= length);
            }
        }
    }
}
