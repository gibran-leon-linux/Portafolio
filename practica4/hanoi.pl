mover(1,X,Y,_) :-
write('Mover disco superior desde '), write(X), write(' a '), write(Y), nl.

mover(N,X,Y,Z) :- N>1, M is N-1,

mover(M,X,Z,Y),
mover(1,X,Y,_),
mover(M,Z,Y,X).