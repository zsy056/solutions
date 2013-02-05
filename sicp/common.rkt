#! /usr/bin/env racket
#lang racket

(provide double halve)

(define (double a)
 (+ a a))

(define (halve a)
 (/ a 2))
