#!/usr/bin/env racket
#lang racket

(define (square-tree tree)
  (cond ((null? tree) null)
        ((not (pair? tree)) (expt tree 2))
        (else (cons (square-tree (car tree))
                    (square-tree (cdr tree))))))

(define (square-tree2 tree)
  (map (lambda (subtree) 
         (if (pair? subtree)
           (square-tree2 subtree)
           (expt subtree 2)))
       tree))

(define in  (list 1 (list 2 (list 3  4)  5) (list  6  7)))
(define out (list 1 (list 4 (list 9 16) 25) (list 36 49)))

(equal? (square-tree in)
        out)

(equal? (square-tree2 in)
        out)
