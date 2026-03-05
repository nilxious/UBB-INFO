% sublista(Lista: list, PozitieStart: integer, PozitieFinala: integer, Rezultat: list)
% (i, i, i, o)

sublista([], _, _, []).

sublista([_|T], M, N, R) :-
    M > 1, !,
    M1 is M - 1,
    N1 is N - 1,
    sublista(T, M1, N1, R).


sublista([H|T], 1, N, [H|R]) :-
    N > 0, !,
    N1 is N - 1,
    sublista(T, 1, N1, R).

sublista(_, _, _, []).

% teste
%sublista([a,b,c], 1, 1, R).
%sublista([a,b,c,d,e], 1, 5, R).
%sublista([a,b,c,d,e], 2, 4, R).
%sublista([a,b,c,d,e], 3, 1, R).
%sublista([a,b,c,d], 2, 10, R).
%sublista([], 1, 3, R).
%sublista([a,b,c], 1, 0, R).
