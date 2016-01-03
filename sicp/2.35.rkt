#!/usr/bin/env racket
#lang racket

(define (accumulate f init items)
  (if (null? items)
      init 
      (f (car items)
         (accumulate f init (cdr items)))))

(define (count-leaves tree)
  (accumulate + 
              0 
              (map (lambda (subtree) 
                     (if (pair? subtree)
                         (count-leaves subtree)
                         1))
                   tree))) 

(= (count-leaves (list 1 2 3))
   3)

(= (count-leaves (list 1 (list 2 (list 3) 4 5) 6))
   6)
