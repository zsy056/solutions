#!/usr/bin/env racket
#lang racket

(define (sum term a next b)
  (define (iter a result)
    (if (> a b)
      result
      (iter (next a) (+ result (term a)))))
  (iter a 0))

(define (orig a) a)

(define (inc a)
  (+ a 1))

(sum orig 1 inc 100)
