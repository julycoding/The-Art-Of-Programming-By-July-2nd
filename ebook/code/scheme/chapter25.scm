(define (binary-search lst val)
  (define (helper left right)
    (if (> left right) #f
      (let* ((idx (quotient (+ left right) 2))
            (mid (list-ref lst idx)))
       (cond ((= mid val) idx)
             ((> mid val) (helper left (- mid 1)))
             ((< mid val) (helper (+ mid 1) right))))))
  (helper 0 (- (length lst) 1)))
