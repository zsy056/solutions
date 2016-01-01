#!/usr/bin/env racket
#lang racket


(define (make-point x y)
  (cons x y))

(define (x-point p)
  (car p))

(define (y-point p)
  (cdr p))

(define (average x y) (/ (+ x y) 2.0))

(define (mid-point p1 p2)
  (make-point (average (x-point p1) (x-point p2))
              (average (y-point p1) (y-point p2))))

(define (print-point p)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")")
  (newline))

(define (make-segment start end)
  (cons start end))

(define (start-segment s)
  (car s))

(define (end-segment s)
  (cdr s))

(define (midpoint-segment s)
  (mid-point (start-segment s) (end-segment s)))


(print-point 
  (midpoint-segment 
    (make-segment (make-point 0 0) 
                  (make-point 1 1))))
