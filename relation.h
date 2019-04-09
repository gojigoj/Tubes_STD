#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "relation.h"
#include "rekening.h"

#define NIL NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

///ADT
typedef struct elmList_relation *adr_relation;

struct elmList_relation{
    adr_rekening info;
    adr_relation next;
};

struct List_relation{
    adr_relation first;
};


///Not Modification
void CreateList(List_relation &L);
void CreateList(List_relation &L);
void InsertFirst(List_relation &L, adr_relation P);
void InsertLast(List_relation &L, adr_relation P);
void InsertAfter(List_relation &L, adr_relation Prec, adr_relation P);
void DeleteFirst(List_relation &L, adr_relation &P);
void DeleteLast(List_relation &L, adr_relation &P);
void DeleteAfter(List_relation &L, adr_relation Prec, adr_relation &P);


///Modification
adr_relation alokasi(adr_rekening X);
void dealokasi(adr_relation P);
bool isEmpty(List_relation L);
adr_relation FindRelasi(List_relation L, string Xrekening);
bool FindRelasiB(List_relation L, string Xrekening);

#endif // RELATION_H_INCLUDED
