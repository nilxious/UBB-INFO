; numar-subliste-aux (lst: lista)

(defun numar-subliste-aux (lst)
  (cond
    ((null lst) 0)
    ((listp (car lst))
     (+ 1
        (numar-subliste-aux (car lst))
        (numar-subliste-aux (cdr lst))))
    (t (numar-subliste-aux (cdr lst)))))

(defun numar-subliste (lst)
  (cond
    ((null lst) 1)
    (t (+ 1
          (numar-subliste-aux lst)))))


; (load "C:/Users/Catalin/Desktop/LISP/L1/c.lisp")

;;; Teste:
; (numar-subliste '(1 2 3))  ; => 1 (doar lista principala, nu sunt subliste interne)
; (numar-subliste '(1 (2 3) 4))                 ; => 2 (lista principală + (2 3))
; (numar-subliste '(1 2 (3 (4 5) (6 7)) 8 (9 10))) 
;  => 5 (lista principala, (3 (4 5) (6 7)), (4 5), (6 7), (9 10))
; (numar-subliste '())                           ; => 1 (lista goala se pune ca sublista)
; (numar-subliste '((1) ((2 3) 4)))      ; => 4 (lista principala + (1) + ((2 3) 4) + (2 3))

