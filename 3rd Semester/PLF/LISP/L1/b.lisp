; asocieri (l1: list, l2:list)

(defun asocieri (l1 l2)
  (cond ((or (null l1) (null l2)) nil)
        (t (cons (list (car l1) (car l2))
                 (asocieri (cdr l1) (cdr l2))))))

;;; Teste:
; (asocieri '(A B C) '(X Y Z))   ; => ((A X) (B Y) (C Z))
; (asocieri '(1 2 3) '(4 5 6))   ; => ((1 4) (2 5) (3 6))
; (asocieri '(1 2) '(10 20 30))  ; => ((1 10) (2 20)) ; scurteaza dupa lista mai scurta
; (asocieri '() '(1 2 3))        ; => nil
; (asocieri '(a b c) '())        ; => nil    
