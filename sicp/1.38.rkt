#!/usr/bin/env racket
#lang racket


(define (cont-frac n d k)
  (define (cont-frac-it acc i)
    (if (= i 0)
      acc
      (cont-frac-it (/ (n i) (+ (d i) acc)) (- i 1))))
  (cont-frac-it (/ (n k) (d k)) (- k 1)))


(+ 2
   (cont-frac (lambda (i) 1.0)
              (lambda (i) (if (= 0 (remainder (+ i 1) 3))
                              (* 2 (/ (+ i 1) 3))
                              1.0))
              10))
