#!/usr/bin/env racket
#lang racket


(define (iterative-improvement good-enough? improve)
  (define (improve-driver guess)
    (if (good-enough? guess)
        guess
        (improve-driver (improve guess))))
  improve-driver)

(define tolerance 0.0001)

(define (good-enough? actual excepted)
  (<= (abs (- actual excepted)) tolerance))

(define (average a b) (/ (+ a b) 2))

(define (sqrt x)
  (define (improve guess) (average guess (/ x guess)))
  ((iterative-improvement (lambda (guess) (good-enough? x (* guess guess))) 
                          improve) 
   1.0))

(define (fixed-point f guess)
  (define (improve guess) (average guess (f guess)))
  ((iterative-improvement (lambda (guess) (good-enough? (f guess) guess))
                          improve)
   guess))

(define (sqrt2 x)
  (fixed-point (lambda (y) (/ x y))
               1.0))


(sqrt 4)
(sqrt2 4)
