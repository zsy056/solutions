#!/usr/bin/env racket
#lang racket

(require "2.36.rkt")

(define (dot-product v w)
  (accumulate + 0 (map * v w)))

(define (matrix-*-vector m v)
  (map (lambda (x) (accumulate + 0 (map * x v))) m))

(define (transpose mat)
  (accumulate-n cons null mat))

(define (matrix-*-matrix m n)
  (let ((cols (transpose n)))
    (map (lambda (x) (matrix-*-vector cols x)) m)))

(define mtx (list (list 1 2 3 4)
                  (list 4 5 6 6)
                  (list 6 7 8 9)))

(define mtx2 (list (list 1 2 3)
                   (list 2 3 4)
                   (list 3 4 5)
                   (list 4 5 6)))

(define v (list 1 2 3 4))

(equal? (matrix-*-vector mtx v)
        (list 30 56 80))

(equal? (transpose mtx)
        (list (list 1 4 6)
              (list 2 5 7)
              (list 3 6 8)
              (list 4 6 9)))

(equal? (matrix-*-matrix mtx mtx2)
        (list (list 30  40  50)
              (list 56  77  98)
              (list 80 110 140)))
