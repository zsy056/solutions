#!/usr/bin/env racket
#lang racket


(define (for-each f lst)
  (if (null? lst)
      null
      (begin (f (car lst))
             (for-each f (cdr lst)))))

(for-each (lambda (x) (display x) (newline))
          (list 57 321 88))
