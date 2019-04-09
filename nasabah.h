#ifndef NASABAH_H_INCLUDED
#define NASABAH_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "relation.h"

#define NIL NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define rekening(P) (P)->rekening
#define first(L) ((L).first)
#define last(L) ((L).last)

///ADT
struct nasabah{
    string Nama;
};

typedef struct nasabah infotype_nasabah;
typedef struct elmList_nasabah *adr_nasabah;

struct elmList_nasabah{
    infotype_nasabah info;
    List_relation rekening;
    adr_nasabah prev;
    adr_nasabah next;
};

struct List_nasabah{
    adr_nasabah first;
    adr_nasabah last;
};

///Not modification
void CreateList(List_nasabah &L);
void InsertFirst(List_nasabah &L, adr_nasabah P);
void InsertLast(List_nasabah &L, adr_nasabah P);
void InsertAfter(List_nasabah &L, adr_nasabah Prec, adr_nasabah P);
void DeleteFirst(List_nasabah &L, adr_nasabah &P);
void DeleteLast(List_nasabah &L, adr_nasabah &P);
void DeleteAfter(List_nasabah &L, adr_nasabah Prec, adr_nasabah &P);

///Modification
adr_nasabah alokasi(string X);
void dealokasi(adr_nasabah P);
adr_nasabah FindNasabah(List_nasabah L, string Xnasabah);
bool isEmpty(List_nasabah L);


#endif // NASABAH_H_INCLUDED
