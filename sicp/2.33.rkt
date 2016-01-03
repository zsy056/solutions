#!/usr/bin/env racket
#lang racket

(define (accumulate op init items)
  (if (null? items)
    init 
    (op (car items)
        (accumulate op init (cdr items)))))

(define (map p sequence)
  (accumulate (lambda (x y) (cons (p x) y)) null sequence))

(define (append seq1 seq2)
  (accumulate cons seq2 seq1))

(define (length sequence)
  (accumulate (lambda (x y) (+ y 1)) 0 sequence))


(equal? (map (lambda (x) (* x 2)) (list 1 2 3))
        (list 2 4 6))

(equal? (append (list 1 2) (list 3 4))
        (list 1 2 3 4))

(= (length (list 5 6 7))
   3)

