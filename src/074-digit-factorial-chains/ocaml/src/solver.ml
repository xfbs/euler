(* http://typeocaml.com/2015/01/25/memoize-rec-untying-the-recursive-knot/ *)

let factorials max =
  let rec next_factorial cur =
    match cur with
    | 0 -> [1]
    | _ ->
      match next_factorial (cur - 1) with
      | prev :: rest -> cur * prev :: prev :: rest
      | _ -> []
  in
  next_factorial max |> List.rev


let rec digit_factorial_sum factorials number =
  match number with
  | 0 -> 0
  | _ ->
      List.nth factorials (number mod 10)
      + digit_factorial_sum factorials (number / 10)

(* in the list [lst], find the element for which pred returns true. *)
let find_index pred lst =
  let rec try_next lst pos =
    match lst with
    | [] -> None
    | hd :: tl ->
      match pred hd with true -> Some pos | false -> try_next tl (pos + 1)
  in
  try_next lst 0


let digit_factorial_chain factorials number =
  let rec next_chain leading cur =
    match find_index (fun x -> x == cur) leading with
    | Some x -> x
    | None -> next_chain (cur :: leading) (digit_factorial_sum factorials cur)
  in
  next_chain [] number


let count_digit_factorial_chain_occurences max =
  let fc = factorials 10 in
  let rec next_number cur =
    let len = digit_factorial_chain fc cur in
    let sum = if len = 60 then 1 else 0 in
    if cur = 0 then sum else sum + next_number (cur - 1)
  in
  next_number max


let solve n = count_digit_factorial_chain_occurences n
