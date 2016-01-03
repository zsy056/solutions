#!/usr/bin/env racket
#lang racket

(= (car (cdr (car (cdr (cdr (list 1 3 (list 5 7) 9))))))
   7)

(= (car (car (list (list 7))))
   7)

(= (car (cdr
          (car 
            (cdr
              (car 
                (cdr
                  (car
                    (cdr
                      (car 
                        (cdr
                          (car 
                            (cdr
                              (list 1 (list 2 (list 3 (list 4 (list 5 (list 6 7))))))))))))))))))
   7)
