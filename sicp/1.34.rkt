#!/usr/bin/env racket
#lang racket

(define (f g)
        (g 2))

(f (lambda (x) (* x x)))

(f f)
; application: not a procedure;
;  expected a procedure that can be applied to arguments
;   given: 2
;   arguments...:
;    2
;   context...:
