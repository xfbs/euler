
let init = [ 3; 2 ]

let int_sqrt num = num |> float_of_int |> sqrt |> int_of_float

let rec relevant_primes primes candidate =
    let sqrt = int_sqrt candidate;
    in match primes with
    | prime :: rest when prime > sqrt -> relevant_primes rest candidate
    | _ -> primes

let rec is_divisible numbers x = match numbers with
    | div :: rest when div == x -> is_divisible rest x
    | div :: rest -> (x mod div == 0) || is_divisible rest x
    | _ -> false

let rec next_do primes cur =
    let relevant = relevant_primes primes cur in
    match is_divisible relevant cur with
    | false -> cur
    | true -> next_do primes (cur + 2)

let next primes = match primes with
    | [] -> 2
    | [2] -> 3
    | last :: rest -> next_do primes (last + 2)

let rec gen primes n = match n with
    | 0 -> primes
    | _ -> gen (next primes :: primes) (n - 1)

let tests = begin
    assert (init = [3; 2]);
    assert (int_sqrt 4 = 2);
    assert (int_sqrt 9 = 3);
    assert (relevant_primes [7; 5; 3; 2] 9 = [3; 2]);
    assert (relevant_primes [7; 5; 3; 2] 25 = [5; 3; 2]);
    assert (is_divisible [5; 3; 2] 4 = true);
    assert (is_divisible [5; 3; 2] 3 = false);
    assert (next_do [3; 2] 5 = 5);
    assert (next_do [5; 3; 2] 7 = 7);
    assert (next_do [7; 5; 3; 2] 9 = 11);
    assert (next [] = 2);
    assert (next [2] = 3);
    assert (next [3; 2] = 5);
    assert (next [5; 3; 2] = 7);
    assert (gen [] 3 = [5; 3; 2]);
    assert (gen [3; 2] 3 = [11; 7; 5; 3; 2]);
end;;
