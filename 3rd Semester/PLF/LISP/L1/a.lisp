; dubleaza-n (lst: lista, n: int)

(defun dubleaza-n (lst n)
  (cond 
        ((null lst) nil)
        ((= n 1) (cons (car lst) (cons (car lst) (cdr lst))))
        (t (cons 
                 (car lst)
                 (dubleaza-n (cdr lst) (1- n))))
        )
   )

; (load "C:/Users/Catalin/Desktop/LISP/L1/a.lisp")

;;; Teste:
; (dubleaza-n '(1 2 3 4 5) 3)  => (1 2 3 3 4 5)
; (dubleaza-n '(10 20 30) 1)   => (10 10 20 30)
; (dubleaza-n '(5 6 7) 5)      => (5 6 7)