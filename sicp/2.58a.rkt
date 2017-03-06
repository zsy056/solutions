#!/usr/bin/env racket
#lang racket

(define (variable? x) (symbol? x))

(define (same-variable? x y)
        (and (variable? x) (variable? y) (eq? x y)))

(define (=number? a b)
        (and (number? a) (number? b) (eq? a b)))

(define (make-sum a b)
        (cond ((and (number? a) (number? b)) (+ a b))
              ((=number? a 0) b)
              ((=number? b 0) a)
              (else (list a '+ b))))

(define (sum? e)
        (and (pair? e) (eq? '+ (cadr e))))

(define (addend e) (car e))

(define (augend e) (caddr e))

(define (make-product a b)
        (cond ((and (number? a) (number? b)) (* a b))
              ((or (=number? a 0) (=number? b 0)) 0)
              ((=number? a 1) b)
              ((=number? b 1) a)
              (else (list a '* b))))

(define (product? e)
        (and (pair? e) (eq? '* (cadr e))))

(define (multiplier e) (car e))

(define (multiplicand e) (caddr e))

(define (make-exponentiation b e)
        (cond ((=number? e 1) b)
              ((=number? e 0) 1)
              ((=number? b 0) 0)
              ((=number? b 1) 1)
              ((and (number? b) (number? e)) (expt b e))
              (else (list b '^ e))))

(define (exponentiation? e) (eq? '^ (cadr e)))

(define (base e) (car e))

(define (exponent e) (caddr e))

(define (deriv e var)
  (cond ((number? e) 0)
        ((variable? e) 
         (if (same-variable? e var) 1 0))
        ((sum? e) (make-sum (deriv (addend e) var) (deriv (augend e) var)))
        ((product? e) 
         (let ((a (deriv (multiplier e) var))
               (b (deriv (multiplicand e) var)))
              (make-sum (make-product (multiplier e) b)
                        (make-product a (multiplicand e)))))
        ((exponentiation? e)
         (let ((ba (base e))
               (ex (exponent e)))
              (make-product ex
                            (make-product (make-exponentiation ba (make-sum ex -1))
                                          (deriv ba var)))))
        (else (error "unknown expression type -- DERIV" exp))))


(equal? '((2 * x) + 3)
        (deriv '((x ^ 2) + (5 + (3 * x))) 'x))
