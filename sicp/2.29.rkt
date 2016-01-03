#!/usr/bin/env racket
#lang racket

(define (make-mobile left right)
  (list left right))

(define (make-branch length structure)
  (list length structure))

; a

(define left-branch car)
(define (right-branch mobile) (car (cdr mobile)))

(= (left-branch (make-mobile 1 2))
   1)
(= (right-branch (make-mobile 1 2))
   2)

(define branch-length car)
(define (branch-structure branch) (car (cdr branch)))

(= (branch-length (make-branch 10 null))
   10)
(equal? (branch-structure (make-branch 10 null))
        null)

; b

(define (total-weight mobile)
  (define (branch-weight branch)
    (let ((struct (branch-structure branch)))
      (if (pair? struct)
        (total-weight struct)
        struct)))
  (+ (branch-weight (left-branch mobile))
     (branch-weight (right-branch mobile))))

(define mx (make-mobile (make-branch 10 10)
                        (make-branch 5
                                     (make-mobile (make-branch 1 2)
                                                  (make-branch 3 4)))))

(= (total-weight mx)
   16)

; c

(define (balanced? mobile)
  (let* ((lb (left-branch mobile))
         (rb (right-branch mobile))
         (lbl (branch-length lb))
         (rbl (branch-length rb))
         (lbs (branch-structure lb))
         (rbs (branch-structure rb))
         (lbw (if (pair? lbs)
                (total-weight lbs)
                lbs))
         (rbw (if (pair? rbs)
                (total-weight rbs)
                rbs)))
    (and (if (pair? lbs)
           (balanced? lbs)
           #t)
         (if (pair? rbs)
           (balanced? rbs)
           #t)
         (= (* lbl lbw)
            (* rbl rbw)))))

(define mx1 (make-mobile (make-branch 2 10) 
                         (make-branch 1 (make-mobile (make-branch 2 18) 
                                                     (make-branch 18 2)))))

(balanced? mx1)

(define mx2 (make-mobile (make-branch 2 10) 
                         (make-branch 1 (make-mobile (make-branch 3 18) 
                                                     (make-branch 18 3)))))
(not (balanced? mx2))

(define mx3 (make-mobile (make-branch 2 3) 
                         (make-branch 1 (make-mobile (make-branch 2 5) 
                                                     (make-branch 5 1)))))

(not (balanced? mx3))

; d

; Need to change the accessor branch-structure, right-branch
