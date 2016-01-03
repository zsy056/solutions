#!/usr/bin/env racket
#lang racket

(define (last-pair lst)
  (let ((tail (cdr lst)))
    (if (null? tail)
        (car lst)
        (last-pair tail))))

(last-pair (list 23 72 149 34))
