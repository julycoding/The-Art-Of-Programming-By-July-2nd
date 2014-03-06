#!/usr/bin/guile -s
!#

;author lmdyyh 3/6/2014
;compiled with guile,executed the cod using 1m38.903s with array size of 5000000,if you don't have guile,you can delete these two lines below then compile it with the compiler what you have installed.  ./chapter36
;vector initialized with 1

(define SIZE 50000)
(define sum (make-vector SIZE 1))

(define (all-sum i)
   (define (estra j)
      (if (< j SIZE)
      (begin (vector-set! sum j (+ (vector-ref sum j) i))
             (estra (+ j i)))))
   (if (< (+ i i) SIZE)
    (begin
       (estra (+ i i))
       (all-sum (+ i 1)))
    ))
(all-sum 2)

(define (amiable i)
  (if (< i SIZE)
    (begin 
      (if (and (> (vector-ref sum i) i) (< (vector-ref sum i) SIZE) (= (vector-ref sum (vector-ref sum i)) i)) (begin (display i) (display " ") (display (vector-ref sum i)) (newline)))
      (amiable (+ i 1)))))

(amiable 220)
