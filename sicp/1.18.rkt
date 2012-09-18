#! /usr/bin/env racket
#lang racket

(require "common.rkt")

#! invariant: sum + a*b
(define (mul-iter sum a b)
 (cond ((= b 0) 0)
       ((= b 1) (+ sum a))
       ((even? b) (mul-iter sum (double a) (halve b)))
       (else (mul-iter (+ sum a) a (- b 1)))))

(define (* a b)
 (mul-iter 0 a b))

(* 3 4)
(* 3 5)
(* 1 3)
(* 1 4)
(* 0 3)
(* 3 0)
