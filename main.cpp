using namespace std;

#include "main.h"
#include "rekening.h"
#include "relation.h"
#include "nasabah.h"

int main()
///Menu Program
{

    List_nasabah LNas;
    List_rekening LRek;
    CreateList(LNas);
    CreateList(LRek);

    char pilih,pilihC,pilihV,pilihD;

    /** Tampilan untuk Main Menu **/
    do{
        system("cls");
        cout<<endl<<endl;
        cout<<"     ================================= PROGRAM MENU ================================"<<endl;
        cout<<"     | 1. Create an Account                                                        |"<<endl;
        cout<<"     | 2. Delete Account                                                           |"<<endl;
        cout<<"     | 3. View Account Info                                                        |"<<endl;
        cout<<"     | 4. Exit Program                                                             |"<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     | Your Pick : ";
        pilih = getche();
        cout<<"                                                               |"<<endl;
        cout<<"     ==============================================================================="<<endl;
        getch();
        switch(pilih){
            case '1' :
                /** Tampilan untuk Create Menu **/
                do{
                    system("cls");
                    cout<<endl<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     ||                             Create an Account                             ||"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     | 1. New Account                                                              |"<<endl;
                    cout<<"     | 2. New Account Number                                                       |"<<endl;
                    cout<<"     | 3. Back to Main Menu                                                        |"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     | Your Pick : ";
                    pilihC = getche();
                    cout<<"                                                               |"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    getch();
                    switch(pilihC){
                        case '1' :
                            CreateNewAcc(LNas,LRek);
                            break;
                        case '2' :
                            CreateNewAccNum(LNas,LRek);
                            break;
                    }
                } while (pilihC != '3');
                break;
            case '3' :
                /** Tampilan untuk View Menu **/
                do{
                    system("cls");
                    cout<<endl<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     ||                             View Account Info                             ||"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     | 1. View Account Number                                                      |"<<endl;
                    cout<<"     | 2. View All Account Number                                                  |"<<endl;
                    cout<<"     | 3. View Account Number owned by two accounts                                |"<<endl;
                    cout<<"     | 4. View Account Number with the most balance                                |"<<endl;
                    cout<<"     | 5. Back to Main Menu                                                        |"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     | Your Pick : ";
                    pilihV = getche();
                    cout<<"                                                               |"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    getch();
                    switch(pilihV){
                        case '1' :
                            ViewAccNum(LNas,LRek);
                            break;
                        case '2' :
                            ViewAllAccNumb(LNas,LRek);
                            break;
                        case '3' :
                            ViewTwoAcc(LNas,LRek);
                            break;
                        case '4' :
                            ViewMostBal(LNas,LRek);
                            break;
                    }
                } while (pilihV != '5');
                break;
            case '2' :
                /** Tampilan untuk Delete Menu **/
                do{
                    system("cls");
                    cout<<endl<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     ||                                 Delete                                    ||"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     | 1. Account                                                                  |"<<endl;
                    cout<<"     | 2. Account Number                                                           |"<<endl;
                    cout<<"     | 3. Back to Main Menu                                                        |"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    cout<<"     | Your Pick : ";
                    pilihD = getche();
                    cout<<"                                                               |"<<endl;
                    cout<<"     ==============================================================================="<<endl;
                    getch();
                    switch(pilihD){
                        case '1' :
                            DeleteAcc(LNas);
                            break;
                        case '2' :
                            DeleteAccNum(LNas,LRek);
                            break;
                    }
                } while (pilihD != '3');
                break;
        }
    } while (pilih != '4');


    return 0;
}

/** ----------------------------------------------------------------------------------------------------------- **/

/** I.S. Terdefinisi List nasabah, list rekening dan elemen nasabah.
    F.S. Elemen rekening sudah ditambahkan ke list rekening dan list relasi. **/
void AddNewAccNum(List_nasabah &L1, List_rekening &L2, adr_nasabah &P){
    adr_relation Q;
    adr_rekening R;
    string NoRek;
    long Saldo;
    do {
        cout<<"     ==============================================================================="<<endl;
        cout<<"     ||                          Create New Account Number                        ||"<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     Input your account number : ";
        cin>>NoRek;
        Q = FindRelasi(rekening(P),NoRek);
        if (Q == NULL){
            cout<<"     Input your balance : ";
            cin>>Saldo;
            R = FindRekening(L2,NoRek);
            if (R != NULL){
                info(R).Saldo = info(R).Saldo + Saldo;
                InsertFirst(rekening(P),alokasi(R));
            } else {
                InsertFirst(L2,alokasi(NoRek,Saldo));
                R = first(L2);
                InsertFirst(rekening(P), alokasi(R));
            }
            cout<<"     ==============================================================================="<<endl;
        } else {
            cout<<endl;
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *               Sorry, Your account number is already available               *"<<endl;
            cout<<"     *******************************************************************************"<<endl;
        }
    } while (Q != NULL);
    /* adr_relation T = first(rekening(S));
    cout<<info(S).Nama<<"->"<<info(info(T)).NoRekening; */
    cout<<endl;
}

/** I.S. Terdefinisi List rekening.
    F.S. List rekening sudah terurut berdasarkan descending dari saldonya **/
void InsertionSort(List_rekening &L2){
    List_rekening L3;
    CreateList(L3);
    adr_rekening P,Q;
    while (first(L2) != NULL){
        DeleteFirst(L2,P);
        if (first(L3) == NULL){
            InsertFirst(L3,P);
        } else if (info(P).Saldo >= info(first(L3)).Saldo){
                InsertFirst(L3,P);
        } else if (info(P).Saldo <= info(last(L3)).Saldo){
                InsertLast(L3,P);
        } else {
                Q = first(L3);
                while (info(P).Saldo <= info(next(Q)).Saldo){
                        Q = next(Q);
                }
                InsertAfter(L3,Q,P);
        }
    }
    L2 = L3;
}

/** ----------------------------------------------------------------------------------------------------------- **/

/** I.S. Terdefinisi List Nasabah dan List Rekening. List nasabah dan List rekening kemungkinan kosong.
    F.S. Elemen nasabah ditambahkan ke list nasabah dan elemen rekening sudah ditambahkan ke list rekening dan list relasi. **/
void CreateNewAcc(List_nasabah &L1, List_rekening &L2){
    adr_nasabah S;
    adr_rekening Q;
    string Name;
    char Pilihan;
    do{
        system("cls");
        cout<<endl<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     ||                          1. Create New Account                            ||"<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     Input your name : ";
        cin>>Name;
        cout<<"     ==============================================================================="<<endl;
        cout<<endl<<endl;
        adr_nasabah P = FindNasabah(L1,Name);
        if (P == NULL){
            InsertFirst(L1,alokasi(Name));
            if (isEmpty(L2)){
                S = first(L1);
                AddNewAccNum(L1,L2,S);
            } else {
                string NoRek;
                long Saldo;
                cout<<"     ==============================================================================="<<endl;
                cout<<"     ||                          Create New Account Number                        ||"<<endl;
                cout<<"     ==============================================================================="<<endl;
                cout<<"     Input your account number : ";
                cin>>NoRek;
                cout<<"     Input your balance : ";
                cin>>Saldo;
                cout<<"     ==============================================================================="<<endl;
                Q = FindRekening(L2,NoRek);
                if (Q != NULL){
                    info(Q).Saldo = info(Q).Saldo + Saldo;
                    S = first(L1);
                    InsertFirst(rekening(S),alokasi(Q));
                } else {
                    InsertFirst(L2,alokasi(NoRek,Saldo));
                    S = first(L1);
                    Q = first(L2);
                    InsertFirst(rekening(S), alokasi(Q));
                }
            }
        } else {
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *                Sorry, Your name account is already available                *"<<endl;
            cout<<"     *******************************************************************************"<<endl;
        }
        cout<<endl<<endl;
        cout<<"     Do you want to create an account again ? (Y/N)"<<endl;
        cout<<"     -------------------------------------------------------------------------------"<<endl;
        cout<<"     Your Pick : ";
        Pilihan = getche();
        getch();
    } while ((Pilihan == 'Y') || (Pilihan == 'y'));

}

/** I.S. Terdefinisi List Nasabah dan List Rekening. List nasabah kemungkinan kosong.
    F.S. Elemen rekening sudah ditambahkan ke list rekening dan list relasi **/
void CreateNewAccNum(List_nasabah &L1, List_rekening &L2){
    char Pilihan1,Pilihan2;
    do{
        system("cls");
        string Name;
        cout<<endl<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     ||                              Input Account                                ||"<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     Input your account name : ";
        cin>>Name;
        cout<<"     ==============================================================================="<<endl;
        adr_nasabah P = FindNasabah(L1,Name);
        if (P != NULL){
            AddNewAccNum(L1,L2,P);
            cout<<"     Do you want to create a new account number again ? (Y/N)"<<endl;
            cout<<"     -------------------------------------------------------------------------------"<<endl;
            cout<<"     Your Pick : ";
            Pilihan1 = getche();
            getch();
        } else {
            cout<<endl<<endl;
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *                    Sorry, Your name account is unavailable                  *"<<endl;
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     Do you want to create an account ? (Y/N)"<<endl;
            cout<<"     -------------------------------------------------------------------------------"<<endl;
            cout<<"     Your Pick : ";
            Pilihan2 = getche();
            getch();
        }
    } while (((Pilihan1 != 'N') && (Pilihan1 != 'n')) && ((Pilihan2 != 'N') && (Pilihan2 != 'n')));
    if ((Pilihan2 == 'Y') || (Pilihan2 == 'y')){
                CreateNewAcc(L1,L2);
    }
}

/** I.S. Terdefinisi List Nasabah. List nasabah kemungkinan kosong.
    F.S. Elemen nasabah tertentu telah dihapus. **/
void DeleteAcc(List_nasabah &L1){
    bool found = false;
    char PilihanN,cancel;
    adr_relation R;
    do{
        system("cls");
        string Name;
        cout<<endl<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     ||                             Delete Account                                ||"<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     Input your account name : ";
        cin>>Name;
        cout<<"     ==============================================================================="<<endl;
        adr_nasabah P = FindNasabah(L1,Name);
        if (P != NULL){
            found = true;
            cout<<"     Are you sure to delete your account ? (Y/N)"<<endl;
            cout<<"     Your account : "<<info(P).Nama<<endl;
            cout<<"     -------------------------------------------------------------------------------"<<endl;
            cout<<"     Your Pick : ";
            PilihanN = getche();
            getch();
            if ((PilihanN == 'Y') || (PilihanN == 'y')) {
                while (!(isEmpty(rekening(P)))){
                    DeleteFirst(rekening(P),R);
                    dealokasi(R);
                }
                if (P == first(L1)){
                    DeleteFirst(L1,P);
                } else {
                    adr_nasabah Q = first(L1);
                    while (next(Q) != P){
                        Q = next(Q);
                    }
                    DeleteAfter(L1,Q,P);
                    dealokasi(P);
                }
                cout<<endl<<endl;
                cout<<"     *******************************************************************************"<<endl;
                cout<<"     *                        Your account has been deleted                        *"<<endl;
                cout<<"     *******************************************************************************"<<endl;
                getch();
            }
        } else {
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *                    Sorry, Your name account is unavailable                  *"<<endl;
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *Press N to cancel"<<endl;
            cancel = getch();
        }
    } while ((found == false) && ((cancel != 'N') && (cancel != 'n')));
}

/** I.S. Terdefinisi List Nasabah dan list rekening. List rekening kemungkinan kosong.
    F.S. Elemen rekening tertentu telah dihapus. elemen relasi ke rekening tersebut telah dihapus **/
void DeleteAccNum(List_nasabah &L1, List_rekening &L2){
    bool found = false;
    char PilihanN,cancel;
    do{
        system("cls");
        string NoRek;
        cout<<endl<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     ||                             Delete Account                                ||"<<endl;
        cout<<"     ==============================================================================="<<endl;
        cout<<"     Input your account number : ";
        cin>>NoRek;
        cout<<"     ==============================================================================="<<endl;
        adr_rekening P = FindRekening(L2,NoRek);
        if (P != NULL){
            found = true;
            cout<<"     Are you sure to delete your account number ? (Y/N)"<<endl;
            cout<<"     Your account number : "<<info(P).NoRekening<<endl;
            cout<<"     Your balance : "<<info(P).Saldo<<endl;
            cout<<"     -------------------------------------------------------------------------------"<<endl;
            cout<<"     Your Pick : ";
            PilihanN = getche();
            getch();
            if ((PilihanN == 'Y') || (PilihanN == 'y')){
                adr_nasabah Q = first(L1);
                while (Q != NULL){
                    adr_relation R = FindRelasi(rekening(Q),NoRek);
                    if (R != NULL){
                        if (R == first(rekening(Q))){
                            DeleteFirst(rekening(Q),R);
                            dealokasi(R);
                        } else {
                            adr_relation S = first(rekening(Q));
                            while (next(S) != R){
                                S = next(S);
                            }
                            DeleteAfter(rekening(Q),S,R);
                            dealokasi(R);
                        }
                    }
                    Q = next(Q);
                }
                if (P == first(L2)){
                    DeleteFirst(L2,P);
                } else {
                    adr_rekening T = first(L2);
                    while (next(T) != P){
                        T = next(T);
                    }
                    DeleteAfter(L2,T,P);
                    dealokasi(P);
                }
                cout<<endl<<endl;
                cout<<"     *******************************************************************************"<<endl;
                cout<<"     *                   Your account number has been deleted                      *"<<endl;
                cout<<"     *******************************************************************************"<<endl;
                getch();
            }
        } else {
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *                   Sorry, Your account number is unavailable                 *"<<endl;
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *Press N to cancel"<<endl;
            cancel = getch();
        }
    } while ((found == false) && ((cancel != 'N') && (cancel != 'n')));
}

/** I.S. Terdefinisi List Nasabah dan list rekening. List nasabah kemungkinan kosong.
    F.S. Menampilkan list relasi dari nasabah tertentu. **/
void ViewAccNum(List_nasabah L1, List_rekening L2){
    char Pilihan,cancel;
    if (!isEmpty(L1)){
        do {
            system("cls");
            string Name;
            cout<<endl<<endl;
            cout<<"     ==============================================================================="<<endl;
            cout<<"     ||                           View Account Number                             ||"<<endl;
            cout<<"     ==============================================================================="<<endl;
            cout<<"     Input your account name : ";
            cin>>Name;
            cout<<"     ==============================================================================="<<endl;
            adr_nasabah P = FindNasabah(L1,Name);
            if (P != NULL){
                cout<<"     ==============================================================================="<<endl;
                cout<<"     ||                          List of Account Number                           ||"<<endl;
                cout<<"     ==============================================================================="<<endl;
                adr_relation Q = first(rekening(P));
                while (Q != NULL){
                    cout<<endl;
                    cout<<"     -------------------------------------------------------------------------------"<<endl;
                    cout<<"     Account Number : "<<info(info(Q)).NoRekening<<endl;
                    cout<<"     Balance : "<<info(info(Q)).Saldo<<endl;
                    cout<<"     -------------------------------------------------------------------------------"<<endl;
                    Q = next(Q);
                }
                cout<<endl;
                cout<<"     ==============================================================================="<<endl;
                cout<<"     Do you want to view another account number ? (Y/N)"<<endl;
                cout<<"     -------------------------------------------------------------------------------"<<endl;
                cout<<"     Your Pick : ";
                Pilihan = getche();
                getch();
            } else {
                cout<<"     *******************************************************************************"<<endl;
                cout<<"     *                    Sorry, Your name account is unavailable                  *"<<endl;
                cout<<"     *******************************************************************************"<<endl;
                cout<<"     *Press N to cancel"<<endl;
                cancel = getch();
            }
        } while (((Pilihan == 'Y') || (Pilihan == 'y')) && ((cancel != 'N') && (cancel != 'n')));
    } else {
        cout<<"     *******************************************************************************"<<endl;
        cout<<"     *                  Sorry, Your list of account name is empty                  *"<<endl;
        cout<<"     *******************************************************************************"<<endl;
        getch();
    }
}

/** I.S. Terdefinisi List Nasabah dan list rekening. List rekening kemungkinan kosong.
    F.S. Menampilkan semua elemen dari list rekening dan nasabahnya. **/
void ViewAllAccNumb(List_nasabah L1, List_rekening L2){
    system("cls");
    cout<<endl<<endl;
    cout<<"     ==============================================================================="<<endl;
    cout<<"     ||                          List of Account Number                           ||"<<endl;
    cout<<"     ==============================================================================="<<endl;
    if (!isEmpty(L2)){
        adr_rekening P = first(L2);
        while (P != NULL){
            cout<<endl;
            cout<<"     -------------------------------------------------------------------------------"<<endl;
            cout<<"     Account Number : "<<info(P).NoRekening<<endl;
            cout<<"     Balance : "<<info(P).Saldo<<endl;
            cout<<"     -------------------------------------------------------------------------------"<<endl;
            cout<<"     This account number has owned by :"<<endl;
            adr_nasabah Q = first(L1);
            int i = 1;
            while (Q != NULL){
                if(FindRelasiB(rekening(Q),info(P).NoRekening)){
                    cout<<"     "<<i<<". "<<info(Q).Nama<<endl;
                    ++i;
                }
                Q = next(Q);
            }
            cout<<"     -------------------------------------------------------------------------------"<<endl;
            P = next(P);
        }
        cout<<"     *Press any key to back"<<endl;
        getch();
    } else {
        cout<<endl;
        cout<<"     *******************************************************************************"<<endl;
        cout<<"     *                  Sorry, your list of account number is empty                *"<<endl;
        cout<<"     *******************************************************************************"<<endl;
        cout<<"     *Press any key to back"<<endl;
        getch();
    }
}

/** I.S. Terdefinisi List Nasabah dan list rekening. List rekening kemungkinan kosong.
    F.S. Menampilkan semua elemen dari list rekening yang dipunyai oleh dua nasabah. **/
void ViewTwoAcc(List_nasabah L1, List_rekening L2){
    int i;
    string Nama1;
    string Nama2;
    string Nama3;
    system("cls");
    cout<<endl<<endl;
    cout<<"     ==============================================================================="<<endl;
    cout<<"     ||                          List of Account Number                           ||"<<endl;
    cout<<"     ==============================================================================="<<endl;
    if (!isEmpty(L2)){
        adr_rekening P = first(L2);
        i = 0;
        while (P != NULL){
            adr_nasabah Q = first(L1);
            Nama1 = "0";
            Nama2 = "0";
            Nama3 = "0";
            while (Q != NULL){
                if (FindRelasiB(rekening(Q),info(P).NoRekening)){
                    if (Nama1 == "0") {
                        Nama1 = info(Q).Nama;
                    } else if (Nama2 != "0") {
                        Nama3 = info(Q).Nama;
                    } else {
                        Nama2 = info(Q).Nama;
                    }
                }
                Q = next(Q);
            }
            if ((Nama2 != "0") && (Nama3 == "0")){
                ++i;
                cout<<endl;
                cout<<"     -------------------------------------------------------------------------------"<<endl;
                cout<<"     Account Number : "<<info(P).NoRekening<<endl;
                cout<<"     Balance : "<<info(P).Saldo<<endl;
                cout<<"     -------------------------------------------------------------------------------"<<endl;
                cout<<"     This account number has owned by :"<<endl;
                cout<<"     1. "<<Nama1<<endl;
                cout<<"     2. "<<Nama2<<endl;
                cout<<"     -------------------------------------------------------------------------------"<<endl;
            }
            P = next(P);
        }
        if (i == 0){
            cout<<endl;
            cout<<"     *******************************************************************************"<<endl;
            cout<<"     *      Sorry, You don't have any account number owned by two account name     *"<<endl;
            cout<<"     *******************************************************************************"<<endl;
        }
        cout<<"     *Press any key to back"<<endl;
        getch();
    } else {
        cout<<endl;
        cout<<"     *******************************************************************************"<<endl;
        cout<<"     *                  Sorry, your list of account number is empty                *"<<endl;
        cout<<"     *******************************************************************************"<<endl;
        cout<<"     *Press any key to back"<<endl;
        getch();
    }
}

/** I.S. Terdefinisi List Nasabah dan list rekening. List rekening kemungkinan kosong.
    F.S. Menampilkan elemen rekening dengan jumlah saldo terbesar beserta dengan nasabahnya. **/
void ViewMostBal(List_nasabah &L1, List_rekening &L2){
    system("cls");
    cout<<endl<<endl;
    cout<<"     ==============================================================================="<<endl;
    cout<<"     ||                    Account number with the most balance                   ||"<<endl;
    cout<<"     ==============================================================================="<<endl;
    if (!isEmpty(L2)){
        InsertionSort(L2);
        cout<<endl;
        cout<<"     -------------------------------------------------------------------------------"<<endl;
        cout<<"     Account Number : "<<info(first(L2)).NoRekening<<endl;
        cout<<"     Balance : "<<info(first(L2)).Saldo<<endl;
        cout<<"     -------------------------------------------------------------------------------"<<endl;
        cout<<"     This account number has owned by :"<<endl;
        adr_nasabah Q = first(L1);
        int i = 1;
        while (Q != NULL){
            if(FindRelasiB(rekening(Q),info(first(L2)).NoRekening)){
                cout<<"     "<<i<<". "<<info(Q).Nama<<endl;
                ++i;
            }
            Q = next(Q);
        }
        cout<<"     -------------------------------------------------------------------------------"<<endl;
        cout<<"     *Press any key to back"<<endl;
        getch();
    } else {
        cout<<endl;
        cout<<"     *******************************************************************************"<<endl;
        cout<<"     *                  Sorry, your list of account number is empty                *"<<endl;
        cout<<"     *******************************************************************************"<<endl;
        cout<<"     *Press any key to back"<<endl;
        getch();
    }
}
