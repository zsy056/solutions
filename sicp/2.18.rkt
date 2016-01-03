#!/usr/bin/env racket
#lang racket

(define (reverse lst)
  (define (do-reverse postfix lst)
    (if (null? lst)
        postfix
        (do-reverse (cons (car lst) postfix) (cdr lst))))
  (do-reverse null lst))

(reverse (list 1 4 9 16 25))
