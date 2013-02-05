#!/usr/bin/env racket
#lang racket

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n b)
  (cond ((< n (* b b)) n)
        ((= 0 (remainder n b)) b)
        (else (find-divisor n (+ b 1)))))

(define (prime? n)
  (= (smallest-divisor n) n))

(define (search-for-primes base num)
  (cond ((= num 0))
        ((timed-prime-test base) 
         (search-for-primes
           (+ base 1) 
           (- num 1)))
        (else (search-for-primes (+ base 1) num))))

(define (timed-prime-test n )
  (start-prime-test n (current-inexact-milliseconds) ))

(define (start-prime-test n start-time )
  (if (prime? n )
      (report-prime (- (current-inexact-milliseconds) start-time) n)
      false))

(define (report-prime elapsed-time n)
  (display n)
  (display " *** ")
  (display elapsed-time)
  (newline))

(search-for-primes 1000 3 )

(search-for-primes 1000 3 )
(search-for-primes 10000 3 )
(search-for-primes 100000 3 )
(search-for-primes 1000000 3 )
