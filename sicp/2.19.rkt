#!/usr/bin/env racket
#lang racket

(define us-coins (list 50 25 10 5 1))
(define uk-coins (list 100 50 20 10 5 2 1 0.5))

(define no-more? null?)

(define except-first-denomination cdr)
(define first-denomination car)

(define (cc amount coin-values)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (no-more? coin-values)) 0)
        (else
         (+ (cc amount
                (except-first-denomination coin-values))
            (cc (- amount
                   (first-denomination coin-values))
                coin-values)))))

(= (cc 100 us-coins)
   292)

(= (cc 100 (reverse us-coins))
   292)

(= (cc 100 (list 1 10 5 50 25))
   292)

; No. Because we will try every coins in the list.
