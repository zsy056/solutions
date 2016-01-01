#!/usr/bin/env racket
#lang racket

(define zero (lambda (f) (lambda (x) x)))

(define (add-1 n)
  (lambda (f) (lambda (x) (f ((n f) x)))))

(define one
  (lambda (f) (lambda (x) (f x))))

(define two
  (lambda (f) (lambda (x) (f (f x)))))

(define (add a b)
  (lambda (f) (lambda (x) ((a f) ((b f) x)))))

(define (cn->int cn)
  ((cn (lambda (x) (+ x 1))) 0))


(cn->int zero)
(cn->int (add zero zero))
(cn->int (add-1 zero))
(cn->int one)
(cn->int two)
