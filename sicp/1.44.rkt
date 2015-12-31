#!/usr/bin/env racket
#lang racket

(define dx 0.00001)

(define (smooth f)
  (lambda (x) (/ (+ (f x) (f (- x dx)) (f (+ x dx))) 3)))

(define (repeated f n)
  (if (<= n 1)
      f
      (compose f (repeated f (- n 1)))))

(define (n-fold-smooth f n)
  ((repeated smooth n) f))


((smooth (lambda (x) (+ x 2))) 2)
((n-fold-smooth (lambda (x) (+ x 2)) 4) 2)
