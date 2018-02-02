open OUnit2
open Solver

let suite =
  "solver-tests"
  >::: [ ( "test-digits"
         >:: fun ctx ->
         assert_equal (digits 123) [3; 2; 1] ;
         assert_equal (digits 34322) [2; 2; 3; 4; 3] ;
         assert_equal (digits 0) [] )
       ; ( "test-find"
         >:: fun ctx ->
         assert_equal (find (fun x -> x = 5)) 5 ;
         assert_equal (find (fun x -> x > 10)) 11 )
       ; ( "test-check"
         >:: fun ctx ->
         assert_bool "check known-good" (check 2 125874 = true) ;
         assert_bool "check known-bad" (check 2 123456 = false) ) ]


let main = run_test_tt_main suite
