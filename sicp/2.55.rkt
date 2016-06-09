#!/usr/bin/env racket
#lang racket
; from http://www.billthelizard.com/2012/03/sicp-253-255-symbolic-data.html
; ' = (quote)

(equal? (quote (quote abracadabra))
        ''abracadabra)

(equal? (quote (quote abracadabra))
        '(quote abracadabra))

(eq? (car '(quote abracadabra))
     'quote)
