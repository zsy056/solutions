#!/usr/bin/env racket
#lang racket

(define (filtered-accumulate combiner null-value term a next b filter-func)
  (define (iter last-result a)
    (define (get-result a)
      (if (filter-func a)
        (term a)
        last-result))
    (if (> a b)
      last-result
      (combiner (get-result a)
                (filtered-accumulate combiner null-value term a next b filter-func)))))

(define (sum-prime term a next b)
  (filtered-accumulate + 0 term a next b prime?))

(define (product-p factor a next b)
  (define (p? a) (eq 1 (gcd a n)))
  (filtered-accumulate * 1 factor a next b p?))
