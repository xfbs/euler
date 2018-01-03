(library (solver)
  (export solve fibonacci even-fibonacci sum-upto)
  (import (rnrs))

  ; returns the nth fibonacci number
  (define (fibonacci n)
    (let
      ((root5 (sqrt 5))
       (phi (/ (+ 1 (sqrt 5)) 2)))
      (exact (round (/ (expt phi n) root5)))))

  ; returns the nth even fibonacci numbers (every third fibonacci number is
  ; even)
  (define (even-fibonacci n)
    (fibonacci (* 3 n)))

  ; for a continuously increasing function fn, return the sum of all values up
  ; to mx starting at start
  (define (sum-upto start mx fn)
    (let
      ((candidate (fn start)))
      (if (> candidate mx)
        0
        (+ candidate (sum-upto (+ start 1) mx fn)))))

  ; returns the sum of all even fibonacci numbers up to m
  (define (solve m)
    (sum-upto 0 m even-fibonacci)))

