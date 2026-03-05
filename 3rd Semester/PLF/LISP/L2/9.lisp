(defun convert (tree) ;; -> (rezultat.rest_lista)
  (cond
    ;; nod fara subarbori
    ((= (cadr tree) 0)
     (cons (list (car tree))
           (cddr tree)))

    ;; nod cu un subarbore
    ((= (cadr tree) 1)
     (cons
      (cons (car tree)
            (list (car (convert (cddr tree)))))
      (cdr (convert (cddr tree)))))

    ;; nod cu 2 subarbori
    ((= (cadr tree) 2)
     (cons
      (cons (car tree)
            ;; aplicam convert pe fiecare subarbore
            (mapcar #'car
                    (list
                     (convert (cddr tree)) ;; subarbore 1
                     (convert (cdr (convert (cddr tree))))))) ;; subarbore 2
      ;; restul listei dupa subarbori
      (cdr (convert (cdr (convert (cddr tree)))))))))

(defun convert-1-2 (tree)
  (car (convert tree)))

(defun nr_noduri (tree)
    (cond 
       ( (null tree) 0)
       (t
         (+ 1 (nr_noduri (cddr tree)))
       )
     )
)


;; (load "C:/Users/Catalin/Desktop/LISP/L2/9.lisp")

;; (load "C:/Users/Catalin/Desktop/LISP/L2/92.lisp")

;; (convert-1-2 '(A 2 B 0 C 2 D 0 E 0))
;; (convert-1-2 '(B 0 C 2 D 0 E 0))

;; (convert-1-2 '(1 2 2 2 4 1 6 1 7 2 8 0 9 2 10 0 11 1 12 0 5 0 3 2 13 0 14 1 15 1 16 2 17 1 19 2 20 0 21 0 18 0))