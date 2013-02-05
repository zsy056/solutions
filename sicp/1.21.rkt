#!/usr/bin/env racket
#lang racket

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n b)
  (cond ((< n (* b b)) n)
        ((= 0 (remainder n b)) b)
        (else (find-divisor n (+ b 1)))))

(smallest-divisor 199)
(smallest-divisor 1999)
(smallest-divisor 19999)
