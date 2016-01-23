; By Óscar López  
; http://stackoverflow.com/questions/13592352/compiling-sicp-picture-exercises-in-drracket
#lang racket

(require graphics/graphics)

(open-graphics)

(define vpsize 500)

(define vp (open-viewport "A Picture Language" vpsize vpsize))

(define draw (draw-viewport vp))

(define (clear) ((clear-viewport vp)))

(define (line vect1 vect2) 
  ((draw-line vp) (make-posn (xcor-vect vect1)
                             (- vpsize (ycor-vect vect1)))
                  (make-posn (xcor-vect vect2)
                             (- vpsize (ycor-vect vect2)))))

;-----

(define (right-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (right-split painter (- n 1))))
        (beside painter (below smaller smaller)))))

(define (square-limit painter n)
  (let ((quarter (corner-split painter n)))
    (let ((half (beside (flip-horiz quarter) quarter)))
      (below (flip-vert half) half))))

(define (flipped-pairs painter)
  (let ((painter2 (beside painter (flip-vert painter))))
    (below painter2 painter2)))

; 2.44 

(define (up-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (up-split painter (- n 1))))
        (below painter (beside smaller smaller)))))

(define (corner-split painter n)
  (if (= n 0)
      painter
      (let ((up    (up-split    painter (- n 1)))
            (right (right-split painter (- n 1))))
        (let ((top-left     (beside up up))
              (bottom-right (below right right))
              (corner       (corner-split painter (- n 1))))
          (beside (below painter top-left)
                  (below bottom-right corner))))))

; 2.45

(define (split first second)
  (define (do-split painter n)
    (if (= n 0)
        painter 
        (let ((smaller (do-split painter (- n 1))))
             (first painter (second smaller smaller)))))
  do-split)

; 2.46

(define (make-vect x y)
  (cons x y))

(define (xcor-vect vect)
  (car vect))

(define (ycor-vect vect)
  (cdr vect))

(define (add-vect vect1 vect2)
  (make-vect (+ (xcor-vect vect1) (xcor-vect vect2))
             (+ (ycor-vect vect1) (ycor-vect vect2))))

(define (sub-vect vect1 vect2)
  (make-vect (- (xcor-vect vect1) (xcor-vect vect2))
             (- (ycor-vect vect1) (ycor-vect vect2))))

(define (scale-vect scale vect)
  (make-vect (* scale (xcor-vect vect))
             (* scale (ycor-vect vect))))

; 2.47

(define (make-frame2 origin edge1 edge2)
  (cons origin (cons edge1 edge2)))

(define (origin2 frame)
  (car frame))

(define (edge12 frame)
  (cadr frame))

(define (edge22 frame)
  (cddr frame))

(define (make-frame origin edge1 edge2)
  (list origin edge1 edge2))

(define (origin-frame frame)
  (car frame))

(define (edge1-frame frame)
  (cadr frame))

(define (edge2-frame frame)
  (caddr frame))

(define (frame-coord-map frame)
  (lambda (v)
    (add-vect
      (origin-frame frame)
      (add-vect (scale-vect (xcor-vect v)
                            (edge1-frame frame))
                (scale-vect (ycor-vect v)
                            (edge2-frame frame))))))

(define (segments->painter segment-list)
  (lambda (frame)
    (for-each
     (lambda (segment)
       (line
        ((frame-coord-map frame) (start-segment segment))
        ((frame-coord-map frame) (end-segment segment))))
     segment-list)))

; 2.48

(define (make-segment start end)
  (cons start (list end)))

(define (start-segment segment)
  (car segment))

(define (end-segment segment)
  (cadr segment))

; 2.49

(define (outline-painter frame)
  (let ((left-bottom  (make-vect 0.0 0.0))
        (right-bottom (make-vect 1.0 0.0))
        (left-top     (make-vect 0.0 1.0))
        (right-top    (make-vect 1.0 1.0)))
    ((segments->painter (list (make-segment left-bottom  right-bottom)
                              (make-segment right-bottom right-top)
                              (make-segment right-top    left-top)
                              (make-segment left-top     left-bottom)))
     frame)))

(define (cross-painter frame)
  ((segments->painter (list (make-segment (make-vect 0.0 0.0) 
                                          (make-vect 1.0 1.0))
                            (make-segment (make-vect 1.0 0.0) 
                                          (make-vect 0.0 1.0))))
     frame))

(define (diamond-painter frame)
  (let ((bottom (make-vect 0.5 0.0))
        (top    (make-vect 0.5 1.0))
        (left   (make-vect 0.0 0.5))
        (right  (make-vect 1.0 0.5)))
    ((segments->painter (list (make-segment bottom left)
                              (make-segment left   top)
                              (make-segment top    right)
                              (make-segment right  bottom)))
     frame)))


; from http://lispor.is-programmer.com/posts/25406.html

(define wave-orgin-data '(((36 60) (40 50) (36 40) (42 40) (60 18))
                          ((60 10) (36 30) (44 0))
                          ((36  0) (30 20) (24 0))
                          ((16  0) (24 30) (20 36) (10 30) (0 42))
                          ((0  50) (10 38) (20 40) (24 40) (20 50) (24 60))))
 
(define wave-vects-data (map (lambda (vs)
                               (map (lambda (xy)
                                      (let ((x (car xy))
                                            (y (cadr xy)))
                                        (make-vect (/ x 60.0) (/ y 60.0))))
                                    vs))
                             wave-orgin-data))
 
(define wave-segments (foldr append
                             '()
                             (map (lambda (vs)
                                    (define (loop xys)
                                      (if (null? (cdr xys))
                                          '()
                                          (cons (make-segment (car xys) (cadr xys))
                                                (loop (cdr xys)))))
                                    (loop vs))
                                  wave-vects-data)))
 
(define (wave frame)
  ((segments->painter wave-segments) frame))


(define (transform-painter painter origin corner1 corner2)
  (lambda (frame)
    (let ((m (frame-coord-map frame)))
      (let ((new-origin (m origin)))
        (painter
         (make-frame new-origin
                     (sub-vect (m corner1) new-origin)
                     (sub-vect (m corner2) new-origin)))))))

(define (flip-vert painter)
  (transform-painter painter
                     (make-vect 0.0 1.0)   ; new origin
                     (make-vect 1.0 1.0)   ; new end of edge1
                     (make-vect 0.0 0.0))) ; new end of edge2

(define (shrink-to-upper-right painter)
  (transform-painter painter
                     (make-vect 0.5 0.5)
                     (make-vect 1.0 0.5)
                     (make-vect 0.5 1.0)))

(define (rotate90 painter)
  (transform-painter painter
                     (make-vect 1.0 0.0)
                     (make-vect 1.0 1.0)
                     (make-vect 0.0 0.0)))

(define (squash-inwards painter)
  (transform-painter painter
                     (make-vect 0.0 0.0)
                     (make-vect 0.65 0.35)
                     (make-vect 0.35 0.65)))

; 2.50

(define (flip-horiz painter)
  (transform-painter painter 
                     (make-vect 1.0 0.0)
                     (make-vect 0.0 0.0)
                     (make-vect 1.0 1.0)))

(define (rotate180 painter)
  (transform-painter painter 
                     (make-vect 1.0 1.0)
                     (make-vect 0.0 1.0)
                     (make-vect 1.0 0.0)))

(define (rotate270 painter)
  (transform-painter painter 
                     (make-vect 0.0 1.0)
                     (make-vect 0.0 0.0)
                     (make-vect 1.0 1.0)))

; 2.51

(define (beside painter1 painter2)
  (let ((split-point (make-vect 0.5 0.0)))
    (let ((paint-left
           (transform-painter painter1
                              (make-vect 0.0 0.0)
                              split-point
                              (make-vect 0.0 1.0)))
          (paint-right
           (transform-painter painter2
                              split-point
                              (make-vect 1.0 0.0)
                              (make-vect 0.5 1.0))))
      (lambda (frame)
        (paint-left frame)
        (paint-right frame)))))


(define (below painter1 painter2)
  (let* ((split-point (make-vect 0.0 0.5))
         (paint-bottom (transform-painter painter1 
                                          (make-vect 0.0 0.0)
                                          (make-vect 1.0 0.0)
                                          (make-vect 0.0 0.5)))
         (paint-up  (transform-painter painter2 
                                       (make-vect 0.0 0.5)
                                       (make-vect 1.0 0.5)
                                       (make-vect 0.0 1.0))))
    (lambda (frame)
      (paint-bottom frame)
      (paint-up frame))))

(define (below2 painter1 painter2)
  (rotate90 
    (beside (rotate270 painter1) 
            (rotate270 painter2))))

; 2.52

;
(define vpframe 
  (make-frame (make-vect 0.0 0.0)
              (make-vect vpsize 0.0)
              (make-vect 0.0 vpsize)))

(provide (all-defined-out))


