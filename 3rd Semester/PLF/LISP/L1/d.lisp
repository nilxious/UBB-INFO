; nr-atomi-superficiali (lst :lista)

(defun nr-atomi-superficiali (lst)
  (cond
    ((null lst) 0)
    ((atom (car lst)) (1+ (nr-atomi-superficiali (cdr lst))))
    (t (nr-atomi-superficiali (cdr lst)))))


; (load "C:/Users/Catalin/Desktop/LISP/L1/d.lisp")


;;; Teste:
; (nr-atomi-superficiali '(1 2 3))                 ; => 3 (toti sunt atomi)
; (nr-atomi-superficiali '(1 (2 3) 4))        ; => 2 (1 si 4 sunt atomi de nivel superficial)
; (nr-atomi-superficiali '(1 2 (3 (4 5) (6 7)) 8 (9 10))) 
;  => 3 (1, 2, 8 sunt atomii de nivel superficial)
; (nr-atomi-superficiali '())                       ; => 0
; (nr-atomi-superficiali '((1) ((2 3) 4)))         ; => 0 (niciun atom la nivel superficial)
