open OUnit2
open Solver

let suite =
  "Solver"
  >::: [ ( "num_mod"
         >:: fun ctx ->
         assert_equal (num_mod 100 1234) [12; 34] ;
         assert_equal (num_mod 10 4928) [4; 9; 2; 8] ;
         assert_equal (num_mod 1000 129) [129] )
       ; ( "mult_mod"
         >:: fun ctd ->
         assert_equal (mult_mod 10 2 (num_mod 10 123)) (num_mod 10 246) ;
         assert_equal (mult_mod 10 9 (num_mod 10 123)) (num_mod 10 1107) ;
         assert_equal
           (mult_mod 10 9 (num_mod 10 43979897))
           (num_mod 10 395819073) ) ]


let main = run_test_tt_main suite
