#! /usr/bin/env racket
#lang racket

(provide even? double halve)

(define (even? n)
 (= 0 (remainder n 2)))

(define (double a)
 (+ a a))

(define (halve a)
 (/ a 2))
