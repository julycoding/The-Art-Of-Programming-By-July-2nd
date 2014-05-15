#!/usr/bin/guile -s
!#
(define (binary-search lst val)
   (define (helper left right)
      (if (> left right) (display "no value")
          (let* ((idx (quotient (+ left right  1) 2))
                 (mid (list-ref lst idx)))
	     (cond ((= mid val) (display idx))
	           ((> mid val) (helper left (- idx 1)))
	           ((< mid val) (helper (+ idx 1) right))))))
      (helper 0 (- (length lst) 1)))

(binary-search (list 1 3 5 7 9 15 19 24 36 ) 5)
