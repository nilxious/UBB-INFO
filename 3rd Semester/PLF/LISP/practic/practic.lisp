
;; L - lista liniara
(defun numerici(L)
	(cond
		( (null L) nil)
		( (not (numberp (car L))) (numerici (cdr L)) )
		(T (cons (car L) (numerici (cdr L))))
	)
)

;; L1, L2 - liste liniare
(defun interclasare(L1 L2)
	(cond
		( (null L1) (numerici L2) )
		( (null L2) (numerici L1) )
		( ( not (numberp (car L1)) ) (interclasare (cdr L1) L2) )
		( ( not (numberp (car L2)) ) (interclasare L1 (cdr L2)) )
  		((= (car L1) (car L2))
     		(cons (car L1)
           		(cons (car L2)
                 	(interclasare (cdr L1) (cdr L2)))))
		( (> (car L1) (car L2)) (cons (car L2) (interclasare L1 (cdr L2))))
		(t (cons (car L1) (interclasare (cdr L1) L2)))
	)
)

		


;; (interclasare '(1 B 2 3 A 4 5) '(C 1 2 3 4 5))


;; (load "C:/Users/Catalin/Desktop/LISP/practic/practic.lisp")	