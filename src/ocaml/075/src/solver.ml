let squares_upto num =
  let rec prev_square cur =
    match cur with 0 -> [] | _ -> (cur, cur * cur) :: prev_square (cur - 1)
  in
  num |> prev_square |> List.rev


let perfect_square x =
  let root = x |> float_of_int |> sqrt |> int_of_float in
  root * root = x


let get_c aa bb =
  let cc = aa + bb in
  let c = cc |> float_of_int |> sqrt |> int_of_float in
  match c * c = cc with false -> None | true -> Some c


let given_a_find_b hasher max (a, aa) candidates =
  let try_candidate (b, bb) =
    if a + b >= max then ()
    else
      match get_c aa bb with
      | Some c when a + b + c < max -> (
        match Hashtbl.find_opt hasher (a + b + c) with
        | Some x -> Hashtbl.add hasher (a + b + c) (x + 1)
        | None -> Hashtbl.add hasher (a + b + c) 1 )
      | _ -> ()
  in
  let rec try_prev candidates =
    match candidates with
    | [] -> ()
    | cur :: prev -> try_candidate cur ; try_prev prev
  in
  try_prev candidates


let find_a max =
  let hasher = Hashtbl.create 1000 in
  let candidates = squares_upto max in
  let rec try_prev candidates =
    match candidates with
    | [] -> ()
    | cur :: prev ->
        given_a_find_b hasher max cur prev ;
        try_prev prev
  in
  try_prev candidates ;
  Hashtbl.fold (fun k v i -> if v = 1 then i + 1 else i) hasher 0


let solve n = find_a n
