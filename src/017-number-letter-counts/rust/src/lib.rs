fn teens_letter_count(n: u32) -> u32 {
    match n {
        1 => 3,  // one
        2 => 3,  // two
        3 => 5,  // three
        4 => 4,  // four
        5 => 4,  // five
        6 => 3,  //// six
        7 => 5,  // seven
        8 => 5,  // eight
        9 => 4,  // nine
        10 => 3, // ten
        11 => 6, // eleven
        12 => 6, // twelve
        13 => 8, // thirteen
        14 => 8, // fourteen
        15 => 7, // fifteen
        16 => 7, // sixteen
        17 => 9, // seventeen
        18 => 8, // eighteen
        19 => 8, // nineteen
        20 => 6, // twenty
        30 => 6, // thirty
        40 => 5, // forty
        50 => 5, // fifty
        60 => 5, // sixty
        70 => 7, // seventy
        80 => 6, // eighty
        90 => 6, // ninety
        _ => teens_letter_count(n % 10) + teens_letter_count(n - (n % 10)),
    }
}

fn hundreds_letter_count(n: u32) -> u32 {
    let hunnies = n / 100;
    let teens = n % 100;

    match (hunnies, teens) {
        (h, 0) => teens_letter_count(h) + 7,
        (0, t) => teens_letter_count(t),
        (h, t) => teens_letter_count(h) + teens_letter_count(t) + 10,
    }
}

fn thousands_letter_count(n: u32) -> u32 {
    let thousands = n / 1000;
    let teens = n % 1000;

    match (thousands, teens) {
        (h, 0) => hundreds_letter_count(h) + 8,
        (0, t) => hundreds_letter_count(t),
        (h, t) => hundreds_letter_count(h) + hundreds_letter_count(t) + 8,
    }
}

pub fn solve(max: u32) -> u32 {
    (1..(max + 1)).map(|n| thousands_letter_count(n)).sum()
}

#[test]
fn test_teens_letter_count() {
    assert_eq!(teens_letter_count(1), 3);
    assert_eq!(teens_letter_count(5), 4);
    assert_eq!(teens_letter_count(10), 3);
    assert_eq!(teens_letter_count(15), 7);
    assert_eq!(teens_letter_count(25), 10);
    assert_eq!(teens_letter_count(32), 9);
    assert_eq!(teens_letter_count(45), 9);
    assert_eq!(teens_letter_count(78), 12);
    assert_eq!(teens_letter_count(70), 7);
    assert_eq!(teens_letter_count(11), 6);
    assert_eq!(teens_letter_count(81), 9);
}

#[test]
fn test_hundreds_letter_count() {
    // fifty-five
    assert_eq!(9, hundreds_letter_count(55));

    // one-hundred
    assert_eq!(10, hundreds_letter_count(100));

    // one hundred and fifty-five
    assert_eq!(22, hundreds_letter_count(155));

    // seven hundred and five
    assert_eq!(19, hundreds_letter_count(705));

    // nine hundred and ninety-four
    assert_eq!(24, hundreds_letter_count(994));
}

#[test]
fn test_thousands_letter_count() {
    // one thousand
    assert_eq!(thousands_letter_count(1000), 11);

    // one thousand, seven hundred and sixty-four
    assert_eq!(thousands_letter_count(1764), 35);
}

#[test]
fn test_solve() {
    assert_eq!(solve(1), 3);
    assert_eq!(solve(10), 39);
}
