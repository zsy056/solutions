#! /usr/bin/env racket
#lang racket

(require "common.rkt")

(define (do-mul a b)
 (cond ((= b 0) 0)
       ((= b 1) a)
       ((even? b) (do-mul (double a) (halve b)))
       (else (+ a (do-mul a (- b 1))))))

(define (* a b)
 (do-mul a b))

(* 3 4)
(* 3 5)
(* 1 3)
(* 1 4)
(* 0 3)
(* 3 0)
