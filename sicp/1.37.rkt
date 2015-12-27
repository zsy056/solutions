#!/usr/bin/env racket
#lang racket


(define (cont-frac n d k)
  (define (cont-frac-it acc i)
    (if (= i 0)
      acc
      (cont-frac-it (/ (n i) (+ (d i) acc)) (- i 1))))
  (cont-frac-it (/ (n k) (d k)) (- k 1)))

(define (cont-frac-r n d k)
  (define (do-cont-frac i)
    (if (= k i)
      (/ (n k) (d k))
      (/ (n i) (+ (d i) (do-cont-frac (+ i 1))))))
  (do-cont-frac 1))


(cont-frac (lambda (i) 1.0)
           (lambda (i) 1.0)
           11)

(cont-frac-r (lambda (i) 1.0)
             (lambda (i) 1.0)
             11)
