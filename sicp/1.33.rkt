#!/usr/bin/env racket
#lang racket

(define (filtered-accumulate combiner init term a next b filter-func)
  (if (<= a b)
      (combiner (if (filter-func a) (term a) init)
                (filtered-accumulate combiner init term (next a) next b filter-func))
      init))

(define (all a next b condition)
  (if (> a b) true
      (if (condition a)
          (all (next a) next b condition)
          false)))

(define (id a) a)

(define (square a) (* a a))

(define (inc a) (+ a 1))

(define (relatively-prime? a b) (= 1 (gcd a b)))

(define (prime? a)
  (if (<= a 1)
      false
      (all 2 inc (- a 1) (lambda (x) (relatively-prime? a x)))))

(define (sum-prime-square a b)
  (filtered-accumulate + 0 square a inc b prime?))

(define (product-relatively-prime a)
  (filtered-accumulate * 1 id 1 inc (- a 1) (lambda (x) (relatively-prime? a x))))

(sum-prime-square 1 4)

(product-relatively-prime 5)
