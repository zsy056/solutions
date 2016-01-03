#!/usr/bin/env racket
#lang racket

(define (accumulate f init items)
  (if (null? items)
      init 
      (f (car items)
         (accumulate f init (cdr items)))))

(define (horner-eval x coefficient-sequence)
  (accumulate (lambda (this-coeff higher-terms) (+ this-coeff (* x higher-terms)))
              0
              coefficient-sequence))

(= (horner-eval 2 (list 1 3 0 5 0 1))
   79)
