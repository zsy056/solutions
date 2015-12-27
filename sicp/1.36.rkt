#!/usr/bin/env racket
#lang racket

(define tolerance 0.00001)

(define (close-enough? v1 v2)
  (< (abs (- v1 v2)) tolerance))

(define (display-line x)
  (display x)
  (newline))

(define (fixed-point-avg f first-guess)
  (define (try guess)
    (display-line guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
        next
        (try (/ (+ next guess) 2)))))
  (try first-guess))

(define (fixed-point f first-guess)
  (define (try guess)
    (display-line guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
        next
        (try next))))
  (try first-guess))

(define (fx x)
  (/ (log 1000) (log x)))

(fixed-point-avg fx 15)
(fixed-point fx 15)
