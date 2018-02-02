let rec digits_count base num =
  if num < base
  then 1
  else 1 + digits_count base (num / base)

let is_even n = 
  n mod 2 = 0

let pow base exp =
  let rec aux acc base = function
    | 0 -> acc
    | 1 -> base * acc
    | e when is_even e -> aux acc (base * base) (e / 2)
    | e -> aux (base * acc) (base * base) ((e - 1) / 2) in
  aux 1 base exp

let nth_power_n_digits_count power =
  let rec find_max base =
    let cur = pow base power |> digits_count 10 in
    match compare cur power with
    | -1 -> find_max (base + 1)
    | 0 -> 1 + find_max (base + 1)
    | _ -> 0
  in find_max 1

let solve x = digits_count 10 x
