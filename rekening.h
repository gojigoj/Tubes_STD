#ifndef REKENING_H_INCLUDED
#define REKENING_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define NIL NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

///ADT
struct Isirekening{
    string NoRekening;
    long Saldo;
};

typedef struct Isirekening infotype_rekening;
typedef struct elmList_rekening *adr_rekening;

struct elmList_rekening{
    infotype_rekening info;
    adr_rekening prev;
    adr_rekening next;
};

struct List_rekening{
    adr_rekening first;
    adr_rekening last;
};

///Not Modification
void CreateList(List_rekening &L);
void InsertFirst(List_rekening &L, adr_rekening P);
void InsertLast(List_rekening &L, adr_rekening P);
void InsertAfter(List_rekening &L, adr_rekening Prec, adr_rekening P);
void DeleteFirst(List_rekening &L, adr_rekening &P);
void DeleteLast(List_rekening &L, adr_rekening &P);
void DeleteAfter(List_rekening &L, adr_rekening Prec, adr_rekening &P);


///Modification
adr_rekening alokasi(string X, long Y);
void dealokasi(adr_rekening P);
void PrintInfoNoRek(List_rekening L, int &i);
adr_rekening FindRekening(List_rekening L, string Xrekening);
bool isEmpty(List_rekening L);

#endif // REKENING_H_INCLUDED
