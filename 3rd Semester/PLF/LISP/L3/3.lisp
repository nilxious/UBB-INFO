(defun apartenenta (arb n)
  (cond
    ((and (atom arb) (eql arb n)) t)
    ((atom arb) nil)
    (t (some (lambda (x) (apartenenta x n)) arb))
  )
)


;; (load "C:/Users/Catalin/Desktop/LISP/L3/3.lisp")

;; (apartenenta '(a (b (c)) (d) (e (f))) 'b)