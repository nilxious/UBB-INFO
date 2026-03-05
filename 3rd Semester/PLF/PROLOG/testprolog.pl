% Predicat care verifica daca un numar este prim
% prim(N: intreg)

prim(2).
prim(N):-
   N > 2,
   prim_aux(N, 2).

%prim_aux(N: intreg, D: intreg)
prim_aux(N,D):-
     N =:= D.

prim_aux(N,D):-
    N > 2, !,
    N mod D =\= 0,
    D1 is D+1,
    prim_aux(N,D1).


% Predicat care numara cate numere prime sunt pana la primul care nu e prim
%numara_nr_prime(L: list, C: int)


numara_nr_prime([], 0).
numara_nr_prime([H|T], C):-
    numara_nr_prime_aux([H|T], 0, C).

numara_nr_prime_aux([H|T],C,Rez):-
    prim(H),
    C1 is C+1,
    numara_nr_prime_aux(T, C1, Rez).

numara_nr_prime_aux([H|T], C, C):-
    \+ prim(H).

numara_nr_prime_aux([], C, C).


% Predicat care elimina numerele prime consecutive (cel putin 2)
%elimina_prime_consecutive(L: lista, R: lista)

elimina_prime_consecutive([], []).

elimina_prime_consecutive([H|T], R):-
    numara_nr_prime([H|T], N),
    elimina_prime_consecutive_aux([H|T],N,R).

elimina_prime_consecutive_aux([H|T], N, R):-
    N > 1,
    elimina_prime_consecutive_aux(T, N, R).

elimina_prime_consecutive_aux([H|T], N, [H|R]):-
    N =:= 0,
    elimina_prime_consecutive_aux(T, N, R).


elimina_prime_consecutive_aux([H|T], N, [H|R]):-
    N =:= 1,
    elimina_prime_consecutive_aux(T, N, R).

