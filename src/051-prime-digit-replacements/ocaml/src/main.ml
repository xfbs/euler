(*
  An example project that uses merlin
*)
open Printf

let string_of_int_list list = (String.concat " " (List.map string_of_int list))
let primes = Prime.gen [] 20000

let _ = printf "%i\n" (List.hd primes)

(*
module A = Awesome

let primes = Prime.init |> Prime.gen
let string_of_int_list list = (String.concat " " (List.map string_of_int list))

let _ =
  printf "hello\nConverted to string we get: %s\nPrimes are %s\n"
    (A.str_of_t (A.succ A.one_t)) (primes |> string_of_int_list);
    *)
