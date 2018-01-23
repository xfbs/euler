pub fn solve(divisors: &[u64; 8]) -> u64 {
    choose_pandigitals(divisors).iter().sum()
}

fn choose_pandigitals(divs: &[u64; 8]) -> Vec<u64> {
    let mut collect = Vec::new();

    for first in 1..10 {
        for second in 0..10 {
            let mut state = [first, second, 0, 0, 0, 0, 0, 0, 0, 0];

            if first != second {
                for palin in choose_rest(&mut state, divs, 2) {
                    collect.push(palin);
                }
            }
        }
    }

    collect
}

fn choose_rest(state: &mut [u64; 10], divs: &[u64; 8], pos: usize) -> Vec<u64> {
    if pos == 10 {
        vec![state.into_iter().fold(0, |memo, &mut cur| 10 * memo + cur)]
    } else {
        let mut collect = Vec::new();

        for choice in 0..10 {
            state[pos] = choice;

            // make sure digits are unique (such that the resulting number is a
            // pandigital number)
            if state[0..pos].iter().any(|&prev| choice == prev) {
                continue;
            }

            // compute the current number
            let cur = state[(pos-2)..(pos+1)]
                .iter()
                .fold(0, |memo, &cur| 10 * memo + cur);

            // make sure current number is divisible by the appropriate divisor
            if cur % divs[pos - 2] != 0 {
                continue;
            }

            for palin in choose_rest(state, divs, pos + 1) {
                collect.push(palin);
            }
        }

        collect
    }
}
