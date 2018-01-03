(library (solver)
  (export solve sum-divisible)
  (import (rnrs) (srfi s64 testing))

  (define (sum-divisible num div)
    (let
      ((num (- num (mod num div))))
      (/ (* num (+ (/ num div) 1)) 2)))

  (define (solve num x y)
    (-
      (+
        (sum-divisible num x)
        (sum-divisible num y))
      (sum-divisible num (lcm x y))))

  (define (solver-test)
    (begin
      (test-begin "mytest")
      (test-end "mytest"))))
