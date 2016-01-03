#!/usr/bin/env racket
#lang racket

(define (deep-reverse lst)
  (define (do-deep-reverse answer lst)
    (if (null? lst)
        answer
        (do-deep-reverse (cons (if (pair? (car lst))
                                   (deep-reverse (car lst))
                                   (car lst))
                               answer)
                         (cdr lst))))
  (do-deep-reverse null lst))


(define x (list (list 1 2) (list 3 4)))

(equal? (deep-reverse x)
        (list (list 4 3) (list 2 1)))
