#!/usr/bin/env racket
#lang racket

(define (sum a b term next)
  (if (> a b)
    0
    (+ (term a)
       (sum (next a) b term next))))

(define (inc a)
  (+ a 1))

(define (integral f a b n)
  (define (h)
    (/ (- b a) (* 1.0 n)))
  (define (factor k)
    (cond ((eq? k 0) 1)
          ((eq? k n) 1)
          ((odd? k) 4)
          (else 2)))
  (define (y k)
    (* (factor k) (f (+ a (* k (h))))))
  (* (/ (h) 3.0)
     (sum 0 n y inc))
  )

(define (cube x)
  (* x x x))

(integral cube 0 1 100)
(integral cube 0 1 1000)
