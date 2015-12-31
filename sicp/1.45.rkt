#!/usr/bin/env racket
#lang racket

(define (average a b) (/ (+ a b) 2))

(define (average-damp f)
  (lambda (x) (average x (f x))))

(define (repeated f n)
  (if (<= n 1)
      f
      (compose f (repeated f (- n 1)))))

(define tolerance 0.00001)

(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
        next
        (try next))))
  (try first-guess))

(define (fixed-point-of-transform g transform guess)
  (fixed-point (transform g) guess))

(define (square-root x)
  (fixed-point-of-transform (lambda (y) (/ x y)) average-damp 1.0))

(define (cube-root x)
  (fixed-point-of-transform (lambda (y) (/ x (* y y))) average-damp 1.0))

(define (forth-root x)
  (fixed-point-of-transform (lambda (y) (/ x (* y y y))) (repeated average-damp 2) 1.0))

(define (nth-root x n)
  (fixed-point-of-transform (lambda (y) (/ x (expt y (- n 1)))) 
                            (repeated average-damp (/ n 2)) 
                            1.0))


(square-root 4)
(cube-root -8)
(forth-root 16)
(nth-root 1024 10)
