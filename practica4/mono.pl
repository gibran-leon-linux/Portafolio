mover(estado(medio,enCaja,medio,noTiene), 
        agarrar, 
        estado(medio,enCaja,medio,tiene)).

mover(estado(P,enPiso,P,H), 
        escalar,
        estado(P,enCaja,P,H)).

mover(estado(P1,enPiso,P1,H), 
        jalar(P1,P2),
        estado(P2,enPiso,P2,H)).

mover(estado(P1,enPiso,B,H), 
        caminar(P1,P2),
        estado(P2,enPiso,B,H)).

puedeObtener(estado(_,_,_,tiene)).
puedeObtener(Estado1) :- 
        mover(Estado1,_,Estado2), 
        puedeObtener(Estado2).