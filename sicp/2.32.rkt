#!/usr/bin/env racket
#lang racket

(define (subsets s)
  (if (null? s)
    (list null)
    (let ((rest (subsets (cdr s))))
      (append rest (map (lambda (x) (cons (car s) x)) rest)))))

(subsets (list 1 2 3))

; 1. When s is (), (subsets s) is (()), which is all subsets of ()
; 2. Assume subsets works on s1 with element k.
; 3. If s2 has (k+1) elements, 
;    rest has all the subsets of s1
;    We can divide s2's subsets into two classes, w/o the element (s2 - s1)
;    We can get the subsets w/ (s2 - s1) by adding (s2 - s1) to each set in rest.
