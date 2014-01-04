; SICP ch1 exercise 19
(define (fib n)
  (fib-iter 1 0 0 1 n))

(define (fib-iter a b p q count)
  (cond ((= count 0)    b)
        ((even? count)  (fib-iter a
                                  b
                                  (+ (* p p) (* q q))
                                  (+ (* 2 p q) (* q q))
                                  (/ count 2)))
        (else           (fib-iter (+ (* b q) (* a q) (* a p))
                                  (+ (* b p) (* a q))
                                  p
                                  q
                                  (- count 1)
                                  ))))


(display (fib 10))
(newline)
