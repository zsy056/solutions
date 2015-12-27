#!/usr/bin/env racket
#lang racket


(define (cont-frac n d k)
  (define (cont-frac-it acc i)
    (if (= i 0)
      acc
      (cont-frac-it (/ (n i) (+ (d i) acc)) (- i 1))))
  (cont-frac-it (/ (n k) (d k)) (- k 1)))

(define (tan-cf x k)
  (cont-frac (lambda (i) (if (= i 1)
                             x
                             (- (* x x))))
             (lambda (i) (- (* i 2.0) 1))
             k))

(tan 1)
(tan-cf 1 10)
