let num_mod m number =
  let rec num_mod_aux num =
    if num < m then [num] else num mod m :: num_mod_aux (num / m)
  in
  number |> num_mod_aux |> List.rev


let mult_mod m mult num =
  let rec mult_mod_aux num =
    match num with
    | cur :: rest ->
        let over, prev = mult_mod_aux rest in
        let cur = cur * mult + over in
        (cur / m, cur mod m :: prev)
    | [] -> (0, [])
  in
  match mult_mod_aux num with 0, l -> l | o, l -> o :: l

let sum l = List.fold_right (fun a b -> a + b) l 0

let digit_sum_mod num =
  num |> List.map (fun x -> (x mod 10) + (x / 10)) |> sum

let max_digit_sum_power base max_exp =
  let modulo = 100 in
  let rec try_next cur exp =
    let cur_sum = digit_sum_mod cur in
    match exp with
    | 1 -> cur_sum
    | _ -> max cur_sum (try_next (mult_mod modulo base cur) (exp - 1))
  in try_next (num_mod modulo base) max_exp

let rec max_digit_sum_powers max_base max_exp =
  let cur = max_digit_sum_power max_base max_exp in
  match max_base with
  | 0 -> cur
  | _ -> max cur (max_digit_sum_powers (max_base - 1) max_exp)

let solve a b = max_digit_sum_powers 99 99
