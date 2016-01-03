#!/usr/bin/env racket
#lang racket

(define (fringe tree)
  (cond ((null? tree) null)
        ((pair? (car tree)) (append (fringe (car tree)) (fringe (cdr tree))))
        (else tree)))

(define x (list (list 1 2) (list 3 4)))

(equal? (fringe x)
        (list 1 2 3 4))

(equal? (fringe (list x x))
        (list 1 2 3 4 1 2 3 4))
