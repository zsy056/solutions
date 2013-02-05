#!/usr/bin/env racket
#lang racket

(require "1.22.rkt")

(define (next n)
  (cond ((= n 2) 3)
        (else (+ 2 n))))

(define (find-divisor n b)
  (cond ((< n (* b b)) n)
        ((= 0 (remainder n b)) b)
        (else (find-divisor n (next b)))))

(search-for-primes 1000 3 )

(search-for-primes 1000 3 )
(search-for-primes 10000 3 )
(search-for-primes 100000 3 )
(search-for-primes 1000000 3 )
