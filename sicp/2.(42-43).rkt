#!/usr/bin/env racket
#lang racket

(require "2.40.rkt")

(define empty-board null)

(define (enumerate-interval a b)
  (up-to a (+ 1 b)))

(define (adjoin-position new-row k rest-of-queens)
  (cons (list new-row k) rest-of-queens))

(define (exists? i items)
  (not (null? (filter (lambda (x) (equal? x i)) items))))

(exists? 5 (list 1 2 3 4 5))
(not (exists? 6 (list 1 2 3 4 5)))

(define (safe? k positions)
  (define (id1 pos)
    (+ (car pos) (cadr pos)))
  (define (id2 pos)
    (- (car pos) (cadr pos)))
  (let* ((new-pos   (car  positions))
         (new-x     (car  new-pos))
         (new-y     (cadr new-pos))
         (old-poses (cdr  positions)))
    (and (not (exists? new-x (map car old-poses)))
         (not (exists? new-y (map cadr old-poses)))
         (not (exists? (id1 new-pos) (map id1 old-poses)))
         (not (exists? (id2 new-pos) (map id2 old-poses))))))

(safe? 4 (list (list 1 2) (list 3 1) (list 2 4) (list 4 3)))
(not (safe? 4 (list (list 2 2) (list 3 1) (list 2 4) (list 4 3))))

(define (queens board-size)
  (define (queen-cols k)  
    (if (= k 0)
      (list empty-board)
      (filter
        (lambda (positions) (safe? k positions))
        (flat-map
          (lambda (rest-of-queens)
            (map (lambda (new-row)
                   (adjoin-position new-row k rest-of-queens))
                 (enumerate-interval 1 board-size)))
          (queen-cols (- k 1))))))
  (queen-cols board-size))

(queens 6)

; 2.43

; Because it will recompute the (k - 1) cases for each column.
; T(x) = T(x-1) + O(x)
; T'(x) = O(x) * T'(x-1)
