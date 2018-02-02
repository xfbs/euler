open Printf

let rec digits num = match num with
    | 0 -> []
    | _ when num < 10 -> [num]
    | _ -> (num mod 10) :: digits (num / 10)

let digits_tests = begin
    assert (digits 123 = [3; 2; 1]);
    assert (digits 123456 = [6; 5; 4; 3; 2; 1]);
end;;

let digits_uniq num = num |> digits |> List.sort_uniq compare

let main = begin
    printf "%s\n" (String.concat " " (List.map string_of_int (digits_uniq
    12319719271942187)));
end;;



(*
module A = Awesome

let primes = Prime.init |> Prime.gen
let string_of_int_list list = (String.concat " " (List.map string_of_int list))

let _ =
  printf "hello\nConverted to string we get: %s\nPrimes are %s\n"
    (A.str_of_t (A.succ A.one_t)) (primes |> string_of_int_list);
    *)
