cmmdc(A,0,A):-
    A =\= 0.

cmmdc(A,B,R):-
    R1 is A mod B,
    cmmdc(B,R1,R).

