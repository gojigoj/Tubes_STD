#include "rekening.h"

///Modification
void CreateList(List_rekening &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_rekening alokasi(string X, long Y){
    adr_rekening P = new elmList_rekening;
    info(P).NoRekening = X;
    info(P).Saldo = Y;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void dealokasi(adr_rekening P){
    delete P;
}

void PrintInfoNoRek(List_rekening L, int &i){
    if (!isEmpty(L)){
        adr_rekening P = first(L);
        while ((P) != NULL) {
            cout<<"     "<<i<<". "<<info(P).NoRekening<<endl;
            P = next(P);
            i++;
        }
    } else {
        cout<<"List [empty]";
    }
}

/* bool FindRekeningB(List_rekening L, string Xrekening){
    bool found = false;
    if (!isEmpty(L)){
        adr_nasabah P = first(L);
        while ((found == false) && (P != NULL)){
            if (info(P).NoRekening == Xrekening){
                found = true;
            } else {
                P = next(P);
            }
        }
    }

    return found;
} */

adr_rekening FindRekening(List_rekening L, string Xrekening){
    adr_rekening P = NULL;
    bool found = false;
    if (!isEmpty(L)){
        P = first(L);
        while ((found == false) && (P != NULL)){
            if (info(P).NoRekening == Xrekening){
                found = true;
            } else {
                P = next(P);
            }
        }
    }

    return P;
}

bool isEmpty(List_rekening L){
    return (first(L) == NULL);
}

///Not Modification
void InsertFirst(List_rekening &L, adr_rekening P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void InsertLast(List_rekening &L, adr_rekening P){
    if (first(L) == NULL){
        InsertFirst(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void InsertAfter(List_rekening &L, adr_rekening Prec, adr_rekening P){
    if (Prec == last(L)){
        InsertLast(L,P);
    } else {
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
        prev(P) = Prec;
    }
}

void DeleteFirst(List_rekening &L, adr_rekening &P){
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

void DeleteLast(List_rekening &L, adr_rekening &P){
    P = last(L);
    if (P == first(L)){
        DeleteFirst(L,P);
    } else {
        next(prev(P)) = NULL;
        last(L) = prev(P);
        next(last(L)) = NULL;
    }
}

void DeleteAfter(List_rekening &L, adr_rekening Prec, adr_rekening &P){
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
