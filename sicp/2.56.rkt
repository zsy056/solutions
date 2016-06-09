#!/usr/bin/env racket
#lang racket

(define (variable? x) (symbol? x))

(variable? 'a)
(not (variable? 1))

(define (same-variable? v1 v2)
        (and (variable? v1) (variable? v2) (eq? v1 v2)))

(same-variable? 'a 'a)
(not (same-variable? 'a 'b))
(not (same-variable? 1 'a))
(not (same-variable? 1 1))

(define (sum? e)
        (and (pair? e) (eq? '+ (car e))))

(sum? '(+ a b))
(not (sum? '(- a b)))

(define (addend e) (cadr e))

(eq? 'a (addend '(+ a b)))
(not (eq? 'a (addend '(+ b a))))

(define (augend e) (caddr e))

(eq? 'a (augend '(+ b a)))
(not (eq? 'a (augend '(+ a b))))

(define (=number? a b)
        (and (number? a) (number? b) (eq? a b)))

(define (make-sum a1 a2)
        (cond ((and (=number? a1 0) (=number? a2 0)) 0)
              ((=number? a1 0) a2)
              ((=number? a2 0) a1)
              ((and (number? a1) (number? a2)) (+ a1 a2))
              (else (list '+ a1 a2))))

(sum? (make-sum 'a 'b))
(eq? 'a (addend (make-sum 'a 'b)))
(eq? 'a (make-sum 'a 0))
(eq? 0 (make-sum 0 0))
(eq? 'a (make-sum 0 'a))

(define (product? e)
        (and (pair? e) (eq? (car e) '*)))

(product? '(* a b))
(not (product? '(- a b)))

(define (multiplier e) (cadr e))

(eq? 'a (multiplier '(* a b)))
(not (eq? 'a (multiplier '(* b a))))

(define (multiplicand e) (caddr e))

(eq? 'a (multiplicand '(* b a)))
(not (eq? 'a (multiplicand '(* a b))))

(define (make-product a b)
        (cond ((or (=number? a 0) (=number? b 0)) 0)
              ((=number? a 1) b)
              ((=number? b 1) a)
              ((and (number? a) (number? b)) (* a b))
              (else (list '* a b))))

(define (exponentiation? e) (eq? '^ (car e)))

(define (make-exponentiation b e)
        (cond ((=number? e 1) b)
              ((=number? e 0) 1)
              ((=number? b 0) 0)
              ((=number? b 1) 1)
              ((and (number? b) (number? e)) (expt b e))
              (else (list '^ b e))))

(exponentiation? (make-exponentiation 'a 'b))
(exponentiation? '(^ a b))
(not (exponentiation? '(+ a b)))

(eq? 0 (make-exponentiation 0 'a))
(eq? 1 (make-exponentiation 1 'a))
(eq? 'b (make-exponentiation 'b 1))
(eq? 25 (make-exponentiation 5 2))

(define (base e) (cadr e))

(eq? 'a (base '(^ a b)))
(not (eq? 'a (base '(^ b a))))

(define (exponent e) (caddr e))

(eq? 'b (exponent '(^ a b)))
(not (eq? 'b (exponent '(^ b a))))

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

(equal? 1 (deriv '(+ x 3) 'x))
(equal? 'y (deriv '(* x y) 'x))
(equal? '(+ (* x y)
            (* y (+ x 3)))
        (deriv '(* (* x y) (+ x 3)) 'x))
(equal? '(+ (* x y) (* y (+ x 3)))
        (deriv '(* (* x y) (+ x 3)) 'x))

; 2.56

(equal? '(* 5 (^ x 4))
        (deriv '(^ x 5) 'x))

(equal? '(* 2 (* 2 x))
        (deriv '(* 2 (^ x 2)) 'x))
