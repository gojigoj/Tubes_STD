#include "relation.h"

///Modification
void CreateList(List_relation &L){
    first(L) = NULL;
}

adr_relation alokasi(adr_rekening X){
    adr_relation P = new elmList_relation;
    info(P) = X;
    next(P) = NULL;

    return P;
}

void dealokasi(adr_relation P){
    delete P;
}

bool FindRelasiB(List_relation L, string Xrekening){
    bool found = false;
    if (!isEmpty(L)){
        adr_relation P = first(L);
        while ((found == false) && (P != NULL)){
            if (info(info(P)).NoRekening == Xrekening){
                found = true;
            } else {
                P = next(P);
            }
        }
    }

    return found;
}

adr_relation FindRelasi(List_relation L, string Xrekening){
    adr_relation P = NULL;
    bool found = false;
    if (!isEmpty(L)){
        P = first(L);
        while ((found == false) && (P != NULL)){
            if (info(info(P)).NoRekening == Xrekening){
                found = true;
            } else {
                P = next(P);
            }
        }
    }

    return P;
}

bool isEmpty(List_relation L){
    return (first(L) == NULL);
}

///Not Modification
void InsertFirst(List_relation &L, adr_relation P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void InsertLast(List_relation &L, adr_relation P){
    if (first(L) == NULL){
        InsertFirst(L,P);
    } else {
        adr_relation Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void InsertAfter(List_relation &L, adr_relation Prec, adr_relation P){
    if (next(Prec) == NULL){
        InsertLast(L,P);
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void DeleteFirst(List_relation &L, adr_relation &P){
    P = first(L);
    if (next(P) == NULL){
        first(L) = NULL;
    } else {
        first(L) = next(P);
        next(P) = NULL;
    }
}

void DeleteLast(List_relation &L, adr_relation &P){
    if (next(first(L)) == NULL){
        DeleteFirst(L,P);
    } else {
        adr_relation Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

void DeleteAfter(List_relation &L, adr_relation Prec, adr_relation &P){
    next(Prec) = P;
    if (next(P) == NULL){
        DeleteLast(L,P);
    } else {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
