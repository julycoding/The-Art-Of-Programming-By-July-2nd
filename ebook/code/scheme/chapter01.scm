#!/usr/bin/guile -s
!#

(define (leftshift str n)
    (display 
      (reverse (append (reverse (string->list (substring str 0 (- (string-length str) n)))) 
                 (reverse (string->list (substring str (- (string-length str) n) (string-length str))))))))

(leftshift "helloworld" 3)
