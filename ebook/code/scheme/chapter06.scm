(define (square x) (* x x))

(define (factor n)
  (define (helper r ret)
    (if (> (square r) n) ret
      (cond ((= 0 (remainder n r)) (helper (+ 1 r) (append ret (list r (/ n r)))))
            (else
              (helper (+ 1 r) ret)))))
  (helper 1 '()))

(define (sum-factor n)
  (- (apply + (factor n)) n))

(define (isAmicable? n)
  (let ((ss (sum-factor n)))
   (and (not (= ss n)) (= n (sum-factor ss)))))

(define (loop start stop ret)
  (if (> start stop) ret
    (begin (if (isAmicable? start)
             (loop (+ start 1) stop (cons start ret))
             (loop (+ start 1) stop ret)))))

(define (main n)
  (apply + (loop 2 n '())))

(display (main 10000))
(newline)
