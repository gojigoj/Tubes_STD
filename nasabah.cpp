#include "nasabah.h"

/// Modification
void CreateList(List_nasabah &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_nasabah alokasi(string X){
    adr_nasabah P = new elmList_nasabah;
    info(P).Nama = X;
    CreateList(rekening(P));
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void dealokasi(adr_nasabah P){
    delete P;
}

/* bool FindNasabahB(List_nasabah L, string Xnasabah){
    bool found = false;
    if (!isEmpty(L)){
        adr_nasabah P = first(L);
        while ((found == false) && (P != NULL)){
            if (info(P).Nama == Xnasabah){
                found = true;
            } else {
                P = next(P);
            }
        }
    }

    return found;
} */

adr_nasabah FindNasabah(List_nasabah L, string Xnasabah){
    adr_nasabah P = NULL;
    bool found = false;
    if (!isEmpty(L)){
        P = first(L);
        while ((found == false) && (P != NULL)){
            if (info(P).Nama == Xnasabah){
                found = true;
            } else {
                P = next(P);
            }
        }
    }

    return P;
}

bool isEmpty(List_nasabah L){
    return (first(L) == NULL);
}

///Not Modification
void InsertFirst(List_nasabah &L, adr_nasabah P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void InsertLast(List_nasabah &L, adr_nasabah P){
    if (first(L) == NULL){
        InsertFirst(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void InsertAfter(List_nasabah &L, adr_nasabah Prec, adr_nasabah P){
    if (Prec == last(L)){
        InsertLast(L,P);
    } else {
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
        prev(P) = Prec;
    }
}

void DeleteFirst(List_nasabah &L, adr_nasabah &P){
    P = first(L);
    if (P == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        prev(next(P)) = NULL;
        first(L) = next(P);
        next(P) = NULL;
    }
}

void DeleteLast(List_nasabah &L, adr_nasabah &P){
    P = last(L);
    if (P == first(L)){
        DeleteFirst(L,P);
    } else {
        next(prev(P)) = NULL;
        last(L) = prev(P);
        next(last(L)) = NULL;
    }
}

void DeleteAfter(List_nasabah &L, adr_nasabah Prec, adr_nasabah &P){
    P = next(Prec);
    if (P == last(L)){
        DeleteLast(L,P);
    } else {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}
