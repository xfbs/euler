let rec digits num =
  match num with
  | 0 -> []
  | _ when num < 10 -> [num]
  | _ -> num mod 10 :: digits (num / 10)


let check mult number =
  let digits_sorted d = d |> digits |> List.sort compare in
  let rec check_alt digits number mult =
    if mult > 1 then
      digits = digits_sorted (mult * number)
      && check_alt digits number (mult - 1)
    else true
  in
  check_alt (digits_sorted number) number mult


let find predicate =
  let rec find_aux pred n = if pred n then n else find_aux pred (n + 1) in
  find_aux predicate 1


let solve n = n |> check |> find
