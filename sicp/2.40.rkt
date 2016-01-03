#!/usr/bin/env racket
#lang racket

(require "2.38.rkt")

(define (up-to a b)
  (if (>= a b)
      null
      (cons a (up-to (+ a 1) b))))

(define (flatten items)
  (if (null? items)
      null 
      (append (car items) (flatten (cdr items)))))

(define (flat-map f items)
  (flatten (map f items)))

(define (unique-pairs n)
  (flat-map (lambda (i) (map (lambda (j) (list i j)) (up-to 1 i)))
       (up-to 1(+ 1 n))))

(provide (all-defined-out))

(equal? (unique-pairs 4)
        (list (list 2 1) (list 3 1) (list 3 2) (list 4 1) (list 4 2) (list 4 3)))

(define (not-divisible-from-to n from to)
  (if (>= from to)
      #t
      (and (not (= (remainder n from) 0))
           (not-divisible-from-to n (+ 1 from) to))))

(define (prime? n)
  (if (= n 1)
      #f
      (not-divisible-from-to n 2 (+ 1 (floor (sqrt n))))))

(define (prime-sum? pair)
  (prime? (+ (car pair) (cadr pair))))

(define (make-pair-sum pair)
  (list (car pair) (cadr pair) (+ (car pair) (cadr pair))))

(define (prime-sum-pairs n)
  (map make-pair-sum 
       (filter prime-sum? (unique-pairs n))))

(equal? (prime-sum-pairs 6)
        (list (list 2 1  3)
              (list 3 2  5)
              (list 4 1  5)
              (list 4 3  7)
              (list 5 2  7)
              (list 6 1  7)
              (list 6 5 11)))
