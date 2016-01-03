#!/usr/bin/env racket
#lang racket

(require "2.38.rkt")
(require "2.40.rkt")

(define (pair->three-sum pair sum)
  (list (car pair) (cadr pair) (- sum (fold-left + 0 pair))))

(define (three-sum n sum)
  (map (lambda (pair) (pair->three-sum pair sum))
       (filter (lambda (pair)
                 (let ((third (- sum (fold-left + 0 pair))))
                   (and (< (cadr pair) third)
                        (<= third n))))
               (map reverse (unique-pairs n)))))

(equal? (three-sum 5 8)
        (list (list 1 2 5)
              (list 1 3 4)))

(equal? (three-sum 5 12)
        (list (list 3 4 5)))

(equal? (three-sum 5 13)
        null)

