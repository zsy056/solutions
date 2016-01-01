#!/usr/bin/env racket
#lang racket

(define (make-rat n d)
  (let* ((g (gcd n d))
         (nn (/ n g))
         (dd (abs (/ d g))))
    (cons (if (< d 0)
              (- 0 nn)
              nn) 
          dd)))

(define (numer x) (car x))

(define (denom x) (cdr x))

(define (print-rat x)
  (display (numer x))
  (display "/")
  (display (denom x))
  (newline))


(print-rat (make-rat -1 2))
(print-rat (make-rat 1 2))
(print-rat (make-rat -1 -2))
(print-rat (make-rat 1 -2))
