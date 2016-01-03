#!/usr/bin/env racket
#lang racket

(define (accumulate f init items)
  (if (null? items)
      init 
      (f (car items)
         (accumulate f init (cdr items)))))

(define (accumulate-n op init seqs)
  (if (null? (car seqs))
      null
      (cons (accumulate   op init (map car seqs))
            (accumulate-n op init (map cdr seqs)))))

(equal? (accumulate-n + 0 (list (list 1 2 3) (list 4 5 6) (list 7 8 9) (list 10 11 12)))
        (list 22 26  30))

(provide (all-defined-out))
