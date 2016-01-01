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

;(define (make-rect lower-left x-span y-span)
  ;(cons lower-left (cons x-span y-span)))

;(define (lower-left-rect rect)
  ;(car rect))

;(define (upper-right-rect rect)
  ;(let ((lr (lower-left-rect rect)))
    ;(make-point (+ (x-point lr) (x-span-rect rect))
                ;(+ (y-point lr) (y-span-rect rect)))))

;(define (x-span-rect rect)
  ;(car (cdr rect)))

;(define (y-span-rect rect)
  ;(cdr (cdr rect)))

(define (perimeter-rect rect)
  (* (+ (x-span-rect rect)
        (y-span-rect rect))
     2))

(define (area-rect rect)
  (* (x-span-rect rect)
     (y-span-rect rect)))

(define (make-rect lower-left x-span y-span)
  (cons lower-left (make-point (+ (x-point lower-left) x-span)
                              (+ (y-point lower-left) y-span))))

(define (lower-left-rect rect)
  (car rect))

(define (upper-right-rect rect)
  (cdr rect))

(define (x-span-rect rect)
  (- (x-point (upper-right-rect rect))
     (x-point (lower-left-rect rect))))

(define (y-span-rect rect)
  (- (y-point (upper-right-rect rect))
     (y-point (lower-left-rect rect))))

(perimeter-rect (make-rect (make-point 0 0) 1 2))
(area-rect (make-rect (make-point 0 0) 1 2))
