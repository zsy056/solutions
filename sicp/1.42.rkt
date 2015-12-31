#!/usr/bin/env racket
#lang racket

(define (compose f g)
  (lambda (x) (f (g x))))

(define (inc x) (+ 1 x))

(define (square x) (* x x))

((compose square inc) 6)
