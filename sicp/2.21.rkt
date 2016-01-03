#!/usr/bin/env racket
#lang racket

(define (square-list items)
  (if (null? items)
      null 
      (cons (expt (car items) 2) (square-list (cdr items)))))

(define (square-list2 items)
  (map (lambda (x) (expt x 2)) items))

(equal? (square-list (list 1 2 3 4))
        (list 1 4 9 16))

(equal? (square-list2 (list 1 2 3 4))
        (list 1 4 9 16))
