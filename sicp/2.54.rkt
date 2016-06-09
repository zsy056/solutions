#!/usr/bin/env racket
#lang racket

(define (myequal? a b)
  (cond 
    ((and (null? a)
          (null? b))
     #t)
    ((or (null? a)
         (null? b))
     #f)
    (else 
      (let ((cara (car a))
            (carb (car b)))
           (cond
             ((and (pair? cara)
                   (pair? carb)
                   (myequal? cara carb))
              (myequal? (cdr a) (cdr b)))
             ((or (pair? cara)
                  (pair? carb))
              #f)
             ((eq? cara carb)
              (myequal? (cdr a) (cdr b)))
             (else #f))))))

(eq? (myequal? '(this is a list) '(this is a list))
     #t)

(eq? (myequal? '(this is a list) '(this (is a) list))
     #f)

