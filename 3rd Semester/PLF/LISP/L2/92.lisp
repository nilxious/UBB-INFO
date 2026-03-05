(defun convert (tree)
  (cond
    ;; nod fara subarbori
    ((= (cadr tree) 0)
     (cons (list (car tree)) (cddr tree)))

    ;; nod cu un subarbore
    ((= (cadr tree) 1)
     (cons
      (cons (car tree)
            (list (car (convert (cddr tree)))))
      (cdr (convert (cddr tree)))))

    ;; nod cu doi subarbori
    ((= (cadr tree) 2)
     (cons
      (cons (car tree)
            (list
             (car (convert (cddr tree)))
             (car (convert (cdr (convert (cddr tree)))))))
      (cdr (convert (cdr (convert (cddr tree)))))))))
      
(defun convert-1-2 (tree)
  (car (convert tree)))
