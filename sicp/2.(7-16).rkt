#!/usr/bin/env racket
#lang racket


(define (add-interval x y)
  (make-interval (+ (lower-bound x) (lower-bound y))
                 (+ (upper-bound x) (upper-bound y))))

;(define (mul-interval x y)
  ;(let ((p1 (* (lower-bound x) (lower-bound y)))
        ;(p2 (* (lower-bound x) (upper-bound y)))
        ;(p3 (* (upper-bound x) (lower-bound y)))
        ;(p4 (* (upper-bound x) (upper-bound y))))
    ;(make-interval (min p1 p2 p3 p4)
                   ;(max p1 p2 p3 p4))))

(define (mul-interval x y)
  (let ((lx (lower-bound x))
        (ly (lower-bound y))
        (ux (upper-bound x))
        (uy (upper-bound y)))
    (cond ((and (>= lx 0) (>= ux 0) (>= ly 0) (>= uy 0)) (make-interval (* lx ly) (* ux uy)))
          ((and (<  lx 0) (>= ux 0) (>= ly 0) (>= uy 0)) (make-interval (* lx uy) (* ux uy)))
          ((and (<  lx 0) (<  ux 0) (>= ly 0) (>= uy 0)) (make-interval (* lx uy) (* ly ux)))
          ((and (<  lx 0) (<  ux 0) (<  ly 0) (>= uy 0)) (make-interval (* lx uy) (* ly lx)))
          ((and (<  lx 0) (<  ux 0) (<  ly 0) (<  uy 0)) (make-interval (* ux uy) (* lx ly)))
          ((and (>= lx 0) (>= ux 0) (<  ly 0) (>= uy 0)) (make-interval (* ly ux) (* ux uy)))
          ((and (>= lx 0) (>= ux 0) (<  ly 0) (<  uy 0)) (make-interval (* ly ux) (* uy lx)))
          ((and (<  lx 0) (>= ux 0) (<  ly 0) (<  uy 0)) (make-interval (* ly ux) (* lx ly)))
          ((and (<  lx 0) (>= ux 0) (<  ly 0) (>= uy 0)) (make-interval (min (* lx uy) (* ly ux)) (* ux uy))))))

(define (eq-interval? a b)
  (and (= (lower-bound a) (lower-bound b))
       (= (upper-bound a) (upper-bound b))))

;(define (div-interval x y)
  ;(mul-interval x 
                ;(make-interval (/ 1.0 (upper-bound y))
                               ;(/ 1.0 (lower-bound y)))))
(define (div-interval x y)
  (if (= 0 (width y))
    (error "Divide by an interval that spans zero.")
    (mul-interval x 
                  (make-interval (/ 1.0 (upper-bound y))
                                 (/ 1.0 (lower-bound y))))))


; 2.7

(define (make-interval a b) (cons a b))

(define (upper-bound interval) (cdr interval))

(define (lower-bound interval) (car interval))

; 2.8

(define (sub-interval a b)
  (make-interval (- (lower-bound a) (upper-bound b))
                 (- (upper-bound a) (lower-bound b))))

; 2.9

(define (width interval)
  (/ (- (upper-bound interval)
        (lower-bound interval))
     2))

(define (test-sum-width a b expected)
  (= (+ (width a) (width b))
     expected))

(let ((a (make-interval 1 2))
      (b (make-interval 1 9)))
  (test-sum-width a b (width (add-interval a b))))

(let ((a (make-interval 1 2))
      (b (make-interval 9 9)))
  (test-sum-width a b (width (add-interval a b))))

(let ((a (make-interval 1 2))
      (b (make-interval 1 9)))
  (test-sum-width a b (width (sub-interval a b))))

(let ((a (make-interval 1 2))
      (b (make-interval 9 9)))
  (test-sum-width a b (width (sub-interval a b))))

(let ((a (make-interval 1 2))
      (b (make-interval 2 3))
      (c (make-interval 3 4))
      (d (make-interval 5 6)))
  (= (width (mul-interval a b))
     (width (mul-interval c d))))

(let ((a (make-interval 1 2))
      (b (make-interval 2 3))
      (c (make-interval 3 4))
      (d (make-interval 5 6)))
  (= (width (div-interval a b))
     (width (div-interval c d))))

; 2.10

;(let ((a (make-interval 1 2))
      ;(b (make-interval 1 1)))
  ;(div-interval a b))

(let ((a (make-interval 2 4))
      (b (make-interval 2 4))
      (expected (make-interval 0.5 2)))
  (eq-interval? (div-interval a b)
                expected))

; 2.11

(let ((a (make-interval 1 2))
      (b (make-interval 3 4))
      (expected (make-interval 3 8)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((a (make-interval -1 2))
      (b (make-interval 3 4))
      (expected (make-interval -4 8)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((a (make-interval -2 -1))
      (b (make-interval 3 4))
      (expected (make-interval -8 -3)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((a (make-interval -2 -1))
      (b (make-interval -4 3))
      (expected (make-interval -6 8)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((a (make-interval -2 -1))
      (b (make-interval -4 -3))
      (expected (make-interval 3 8)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((a (make-interval 1 2))
      (b (make-interval -4 3))
      (expected (make-interval -8 6)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((b (make-interval -2 -1))
      (a (make-interval 3 4))
      (expected (make-interval -8 -3)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((a (make-interval -2 4))
      (b (make-interval -4 -3))
      (expected (make-interval -16 8)))
  (eq-interval? (mul-interval a b)
                expected))

(let ((a (make-interval -2 4))
      (b (make-interval -3 4))
      (expected (make-interval -12 16)))
  (eq-interval? (mul-interval a b)
                expected))

; 2.12

(define (make-center-width c w)
  (make-interval (- c w) (+ c w)))

(define (center i)
  (/ (+ (lower-bound i) (upper-bound i)) 2))

(define (make-center-percent c p)
  (make-center-width c (* c 0.01 p)))

(define (percent i)
  (* 100 (/ (width i) (center i))))

(eq-interval? (make-interval 1 3)
              (make-center-percent 2 50))

(= (percent (make-center-percent 2 50))
   50)

; 2.13
; (a - ax, a + ax) * (b - by, b + by)
; ((a - ax) * (b - by), (a + ax) * (b + by))
; (ab - ab * (x + y) + abxy, ab + ab * (x + y) + abxy)
; ab * (1 + xy) +- ab * (x + y)
; xy -> 0
; ab +- ab * (x + y)
; tolerance = x + y
(define (mul-tolerance t1 t2)
  (+ t1 t2))

(percent (mul-interval (make-center-percent 100 2)
                       (make-center-percent 230 3)))

; 2.14

(define (par1 r1 r2)
  (div-interval (mul-interval r1 r2)
                (add-interval r1 r2)))

(define (par2 r1 r2)
  (let ((one (make-interval 1 1))) 
    (div-interval one
                  (add-interval (div-interval one r1)
                                (div-interval one r2)))))

(define i1 (make-center-percent 100 2))
(define i2 (make-center-percent 210 3))

(define par1-res (par1 i1 i2))
(define par2-res (par2 i1 i2))

(center par1-res)
(center par2-res)

(percent par1-res)
(percent par2-res)

(define ab (div-interval i1 i2))
(define aa (div-interval i1 i1))

(center ab)
(center aa)

(percent ab)
(percent aa)

(define i1-reverse (div-interval (make-interval 1 1) i1))

(center i1-reverse)
(percent i1-reverse)

; 2.15
; Right.
; When same uncertain number appears more than once,
; the uncertainty we get will be larger than the actual uncertainty.
; Since the different instances of the same uncertain number is not independent.

; 2.16
; https://wqzhang.wordpress.com/2009/06/18/sicp-exercise-2-16/

;1. We should take Eva Lu Ator’s suggestion (SICP Exercise 2.15) 
   ;to avoid repeated appearance of intervals.
;2. Remember the Taylor expansion: 
   ;f(x,y) \approx f(x_0,y_0) + \frac{\partial f}{\partial x} \Delta x + \frac{\partial f}{\partial y} \Delta y. 
   ;Maybe we could design a system which utilizes the Taylor expansion, assuming that percentage tolerances are small. 
   ;To compute the resulting center of an expression, we perform normal arithmetics on the centers of argument intervals. 
   ;Then we compute the partial derivatives by varying the value of one interval while keeping the others fixed.
   ;Finally we combine the partial derivatives and percentage tolerances together to obtain the resulting percentage tolerance.
;3. For really complicated systems, we could also perform Monte carlo simulations to get an answer that is good enough.
