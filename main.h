#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>


#include "rekening.h"
#include "relation.h"
#include "nasabah.h"

///Additional
void AddNewAccNum(List_nasabah &L1, List_rekening &L2);
void InsertionSort(List_rekening &L2);

///Create Menu
void CreateNewAcc(List_nasabah &L1, List_rekening &L2);
void CreateNewAccNum(List_nasabah &L1, List_rekening &L2);

///Delete Menu
void DeleteAcc(List_nasabah &L1);
void DeleteAccNum(List_nasabah &L1, List_rekening &L2);

///View Menu
void ViewAccNum(List_nasabah L1, List_rekening L2);
void ViewAllAccNumb(List_nasabah L1, List_rekening L2);
void ViewTwoAcc(List_nasabah L1, List_rekening L2);
void ViewMostBal(List_nasabah &L1, List_rekening &L2);

#endif // MAIN_H_INCLUDED
