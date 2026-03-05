% inlocuieste(lista: list, einlocuit: integer, enou:integer, R:list)
% model de flux (i, i, i, o)

inlocuieste([],_,_,[]).

inlocuieste([H|T],E,X,[X|R]):-
    H==E,
    inlocuieste(T,E,X,R).

inlocuieste([H|T],E,X,[H|R]):-
    H\=E,
    inlocuieste(T,E,X,R).

% teste
%inlocuieste([],3,4,R).
%inlocuieste([1,2,3,4,5],0,7,R).
%inlocuieste([1,2,3,4,5],3,10,R).
