#ifndef PROGRAMMER_H_INCLUDED
#define PROGRAMMER_H_INCLUDED

#include <iostream>

using namespace std;

#define first(L) L.first
#define next(P) P->next
#define infoProg(P) P->infoProg

typedef struct progElmList *adrProg;

struct infotype{
    string Username;
    string Pass;
    string Code;
};

struct progElmList{
    infotype infoProg;
    adrProg next;
};

struct ProgrammerList{
    adrProg first;
};

bool isEmpty(ProgrammerList L);
/*  Is.
    Fs.Memeriksa apakah Tersedia List */
adrProg CreateAccount(ProgrammerList &L);
/*  Is.
    Fs.Membuat Account dan menyimpannya pada sebuah address */
void CreateParentList(ProgrammerList &L);
/*  Is.
    Fs.Membuat List Kosong */
void insertFirst(ProgrammerList &L, adrProg P);
/*  Is.
    Fs.Memasukan address yang berisi info */
void insertAfter(adrProg &Choose,adrProg P);
/*  Is.
    Fs.Memasukan address yang berisi info */
void insertProgrammer(ProgrammerList &L,adrProg P);
/*  Is.List yang kosong atau memiliki isi
    Fs.Memasukan address yang berisi info secara terurut menggunakan procedure insert first dan after*/
adrProg FindProgList(ProgrammerList &L,string Username,string Key);
/*  Is.Tersedia List yang memiliki info
    Fs.mencari dan mengembalikan address yang dicari */
void DeleteFirst(ProgrammerList &L,adrProg &P);
/*  Is.List mungkin Kosong atau berisi
    Fs.Menghapus List yang Pertama */
void DeleteAfter(adrProg &Choose,adrProg &P);
    /*  Is.List mungkin Kosong atau berisi
    Fs.Menghapus List yang dipilih */
void DeleteProgrammer(ProgrammerList &L, string ID);
/*  Is.List mungkin Kosong atau berisi
    Fs.Menghapus List yang terpilih dan menggunakan procedure delete first dan after */
void UpdateDataProgrammer(ProgrammerList &L,string Username);
/*  Is.Tersedia List yang berisi info
    Fs.Mengupdate Info dalam List */
void ShowDataProgrammer(ProgrammerList L);
/*  Is.
    Fs.Menampilkan Data Programmer */
bool StatusProgrammer(ProgrammerList &L,string Username);
/*  Is.List mungkin Kosong atau berisi
    Fs.Mencari Project yang ingin dicari dan mengembalikan status*/
adrProg findUserP (ProgrammerList &L, string username, string password);
adrProg findUserM (ProgrammerList &L, string username, string password);


#endif // PROGRAMMER_H_INCLUDED
