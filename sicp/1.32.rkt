#!/usr/bin/env racket
#lang racket

(define (accumulate-re combiner null-value term a next b)
  (if (> a b)
    null-value
    (combiner (term a)
              (accumulate-re combiner null-value term (next a) next b))))

(define (accumulate-it combiner null-value term a next b)
  (define (iter last-result a)
    (if (> a b)
      last-result
      (iter (combiner last-result (term a))
            (next a))))
  (iter null-value a))

(define (sum term a next b acc)
  (acc + 0 term a next b))

(define (orig a) a)
(define (inc a) (+ a 1))

(sum orig 1 inc 100 accumulate-re)
(sum orig 1 inc 100 accumulate-it)

(define (product a b factor next acc)
  (acc * 1 factor a next b))

(product 1 5 orig inc accumulate-re)
(product 1 5 orig inc accumulate-it)
