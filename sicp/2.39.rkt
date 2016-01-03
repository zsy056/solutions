#!/usr/bin/env racket
#lang racket

(require "2.38.rkt")

(define (reverse0 sequence)
  (fold-right (lambda (x y) (append y (list x))) null sequence))

(define (reverse1 sequence)
  (fold-left (lambda (x y) (cons y x)) null sequence))

(equal? (reverse0 (list 1 2 3 4))
        (list 4 3 2 1))

(equal? (reverse1 (list 1 2 3 4))
        (list 4 3 2 1))
