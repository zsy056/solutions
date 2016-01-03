#!/usr/bin/env racket
#lang racket

(define (square-list items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons answer
                    (expt(car things) 2)))))
  (iter items null))

(square-list (list 1 2 3 4))

; cons can only add element to head

(define (square-list2 items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (append answer
                      (list (expt(car things) 2))))))
  (iter items null))

(square-list2 (list 1 2 3 4))
