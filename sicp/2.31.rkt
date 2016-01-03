#!/usr/bin/env racket
#lang racket

(define (tree-map f tree)
  (map (lambda (subtree)
         (if (pair? subtree)
           (tree-map f subtree)
           (f subtree)))
       tree))

(define (square-tree tree)
  (tree-map (lambda (x) (expt x 2)) tree))

(define in  (list 1 (list 2 (list 3  4)  5) (list  6  7)))
(define out (list 1 (list 4 (list 9 16) 25) (list 36 49)))

(equal? (square-tree in)
        out)

