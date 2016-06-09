#!/usr/bin/env racket
#lang racket

(equal? (list 'a 'b 'c)
        '(a b c))

(equal? (list (list 'george))
        '((george)))

(equal? (cdr '((x1 x2) (y1 y2)))
        '((y1 y2)))

(equal? (cadr '((x1 x2) (y1 y2)))
        '(y1 y2))

(equal? (pair? (car '(a short list)))
        #f)

(equal? (memq 'red '((red shoes) (blue socks)))
        #f)

(equal? (memq 'red '(red shoes blue socks))
        '(red shoes blue socks))
