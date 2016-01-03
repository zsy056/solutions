#!/usr/bin/env racket
#lang racket

(require "2.36.rkt")

(define fold-right accumulate)

(define (fold-left op init items)
  (if (null? items)
      init 
      (fold-left op (op init (car items)) (cdr items))))

(provide (all-defined-out))

(= (fold-right / 1 (list 1 2 3))
   (/ 3 2))
(= (fold-left / 1 (list 1 2 3))
   (/ 1 6))
(equal? (fold-right list null (list 1 2 3))
        (list 1 (list 2 (list 3 null))))
(equal? (fold-left list null (list 1 2 3))
        (list (list (list null 1) 2) 3))

; (op x y) == (op y x)
