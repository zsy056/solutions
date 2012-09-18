#! /usr/bin/env racket
#lang racket

(require "common.rkt")

#! invariant: a * (b^n)
(define (expt-iter a b n)
 (cond ((= n 0) a)
       ((even? n) (expt-iter a (* b b) (/ n 2)))
       (else (expt-iter (* a b) b (- n 1)))))
        

(define (fast-expt b n)
 (expt-iter 1 b n))

(fast-expt 10 9)
(fast-expt 10 2)
(fast-expt 10 1)
(fast-expt 10 0)
