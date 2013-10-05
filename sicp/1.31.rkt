#!/usr/bin/env racket
#lang racket

(define (product-re a b factor next)
  (if (> a b)
    1
    (* (factor a)
       (product-re (next a) b factor next))))

(define (product-it a b factor next)
  (define (iter a result)
    (if (> a b)
      result
      (iter (next a) (* result (factor a)))))
  (iter a 1))

(define (orig x) x)

(define (inc x) (+ x 1))

(define (factorial n product)
  (product 1 n orig inc))

(factorial 10 product-re)
(factorial 10 product-it)

(define (pi n)
  (define (square x) (* x x))
  (define (fact-up i) (* (* i 2) (* (+ i 1) 2)))
  (define (fact-down i) (square (+ (* i 2) 1)))
  (define (pi-imp)
    (/ (product-it 1 n fact-up inc)
       (product-it 1 n fact-down inc)))
  (* 4 (pi-imp)))

(* 1.0 (pi 1000))
