#!/usr/bin/env racket
#lang racket

(define (cons a b)
  (* (expt 2 a)
     (expt 3 b)))

(define (max-exp x p)
  (let ((rem (remainder x p)))
    (if (= 0 rem)
        (+ 1 (max-exp (/ x p) p))
        0)))

(define (car p)
  (max-exp p 2))

(define (cdr p)
  (max-exp p 3))

(define c0 (cons 0 1))
(car c0)
(cdr c0)

(define c1 (cons 0 0))
(car c1)
(cdr c1)

(define c2 (cons 2 3))
(car c2)
(cdr c2)
