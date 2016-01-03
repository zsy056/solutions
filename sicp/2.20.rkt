#!/usr/bin/env racket
#lang racket

(define (same-parity . lst)
  (filter (lambda (x) (= (remainder (car lst) 2) (remainder x 2))) lst))


(equal? (same-parity 1 2 3 4 5 6 7)
        (list 1 3 5 7))

(equal? (same-parity 2 3 4 5 6 7)
        (list 2 4 6))

