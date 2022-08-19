#include "programmer.h"
#include <iostream>

using namespace std;

adrProg CreateAccount(ProgrammerList &L){
/*  Is.
    Fs.Membuat Account dan menyimpannya pada sebuah address */
    string NewUsername;
    string Pass;
    string Type;

    adrProg P = new progElmList;
    cout<<"Buat Username Akun : ";
    cin>>NewUsername;
    if(!(StatusProgrammer(L,NewUsername))){
        infoProg(P).Username = NewUsername;
    }else{
        while((StatusProgrammer(L,NewUsername))){
        cout<<"Username sudah ada silahkan gunakan Username lain"<<endl;
        cout<<"Buat Username Akun : ";
        cin>>NewUsername;
            if(!(StatusProgrammer(L,NewUsername))){
            infoProg(P).Username = NewUsername;
            }
        }
    }
    cout<<"Buat Password Akun : ";
    cin>>Pass;
    infoProg(P).Pass = Pass;
    cout<<"Pilih Jenis Akun :"<<endl;
    cout<<"---Programmer---"<<endl;
    cout<<"-----Manager----"<<endl;
    cout<<"Ketikan pilihan anda (huruf kecil) : ";
    cin>>Type;
    while (Type != "programmer" && Type != "manager"){
        cout<<"Ketikan pilihan anda (huruf kecil) : ";
    }

    infoProg(P).Code = Type;
    next(P) = NULL;

    return P;
}

void CreateParentList(ProgrammerList &L){
/*  Is.
    Fs.Membuat List Kosong */
    first(L) = NULL;
}

void insertFirst(ProgrammerList &L,adrProg P){
/*  Is.List Mungkin Kosong
    Fs.Memasukan address yang berisi infoProg */
    if(first(L)==NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(adrProg &Choose,adrProg P){
/*  Is.List Terdefinisi
    Fs.Memasukan address yang berisi infoProg */
    if(next(Choose) == NULL){
        next(Choose) = P;
    }else{
        next(P) = next(Choose);
        next(Choose) = P;
    }
}

void insertProgrammer(ProgrammerList &L,adrProg P){
/*  Is.List yang kosong atau memiliki isi
    Fs.Memasukan address yang berisi infoProg secara terurut menggunakan procedure insert first dan after*/
    if(first(L)==NULL){
        insertFirst(L,P);
    }else{
        if(infoProg(P).Username <= infoProg(first(L)).Username){
            insertFirst(L,P);
        }else if(infoProg(P).Username > infoProg(first(L)).Username && next(first(L)) == NULL){
            insertAfter(first(L),P);
        }else{
            adrProg Q = FindProgList(L,infoProg(P).Username,"Insert");
            insertAfter(Q,P);
        }
    }
}

adrProg FindProgList(ProgrammerList &L,string Username,string Key){
/*  Is.Tersedia List yang memiliki infoProg
    Fs.mencari dan mengembalikan address yang dicari */
    adrProg P = first(L);
    if(Key == "Insert"){
        while(next(P) != NULL){
            if(Username < infoProg(next(P)).Username){
                return P;
            }
            P = next(P);
        }
        return P;
    }else if(Key == "Update"){
        while(P != NULL){
            if(infoProg(P).Username == Username){
                return P;
            }
            P = next(P);
        }
    }else if(Key == "Delete"){
        while (P != NULL){
            if(infoProg(next(P)).Username == Username){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void DeleteFirst(ProgrammerList &L,adrProg &P){
/*  Is.List mungkin Kosong atau berisi
    Fs.Menghapus List yang Pertama */
    if(first(L)!=NULL){
        P = first(L);
        if(next(first(L)) == NULL){
            first(L) = NULL;
        }else{
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}

void DeleteAfter(adrProg &Choose,adrProg &P){
    /*  Is.List mungkin Kosong atau berisi
    Fs.Menghapus List yang dipilih */
    P = next(Choose);
    if(next(P) == NULL){
        next(Choose) = NULL;
    }else{
        next(Choose) = next(P);
        next(P) = NULL;
    }
}

void DeleteProgrammer(ProgrammerList &L, string Username){
/*  Is.List mungkin Kosong atau berisi
    Fs.Menghapus List yang terpilih dan menggunakan procedure delete first dan after */
    adrProg P;
    if(first(L)!=NULL){
        if(Username == infoProg(first(L)).Username){
            DeleteFirst(L, P);
            cout << "Delete Data BERHASIL" << endl;
        }else{
            adrProg Choose = FindProgList(L, Username, "Delete");
            if(Choose != NULL){
                DeleteAfter(Choose, P);
                cout << "Delete Data BERHASIL" << endl;
            }else{
                cout << "Data yang ingin diDelete tidak di temukan" << endl;
            }
        }
    }
}

void UpdateDataProgrammer(ProgrammerList &L,string Username){
/*  Is.Tersedia List yang berisi infoProg
    Fs.Mengupdate infoProg dalam List */

    adrProg P = FindProgList(L, Username, "Update");
    char Replace;
    if(P != NULL){
        cout << "Username : " << infoProg(P).Username << endl;
        cout << "---UPDATE---" << endl;
        cout << "Username Baru : ";
        cin>>infoProg(P).Username;
        cout << "Apakah anda ingin mengganti PASSWORD? y/n ? ";
        cin >> Replace;
        if(Replace == 'y'){
            cout << "Password Baru : ";
            cin >> infoProg(P).Pass;
            cout << "Update Data BERHASIL" <<  endl;
        }else{
            cout << "Update Data BERHASIL" <<  endl;
        }
    }else{
        cout << "Data Tidak Ditemukan" << endl;
        cout << "Update Data GAGAL" <<  endl;
    }
}

void ShowDataProgrammer(ProgrammerList L){
/*  Is.
    Fs.Menampilkan Data Programmer */
    string manager;
    cout<<"-----Data Programmer-----"<<endl;
    if(first(L)!=NULL ){

        adrProg Q = first(L);
        while(Q != NULL){
            if(Q != NULL && infoProg(Q).Code != "manager"){
                cout << "Username : " << infoProg(Q).Username<<endl;
            }
            Q = next(Q);
        }
    }else{
        cout << "Tidak ada Programmer yang tersedia" << endl;
    }
    cout << endl;
}

bool StatusProgrammer(ProgrammerList &L,string Username){
/*  Is.List mungkin Kosong atau berisi
    Fs.Mencari Project yang ingin dicari dan mengembalikan status*/
    if(first(L)==NULL){
        return false;
    }else{
        adrProg Q = first(L);
        while(Q != NULL){
            if(infoProg(Q).Username == Username){
                return true;
            }
            Q = next(Q);
        }
        return false;
    }
}

adrProg findUserP (ProgrammerList &L, string username, string password){
    adrProg P = first(L);
    while(P != NULL){
            if((infoProg(P).Username == username && infoProg(P).Pass == password && infoProg(P).Code == "programmer")){
                return P;
            }
            P = next(P);
        }
}

adrProg findUserM (ProgrammerList &L, string username, string password){
    adrProg P = first(L);
    while(P != NULL){
            if((infoProg(P).Username == username && infoProg(P).Pass == password && infoProg(P).Code == "manager")){
                return P;
            }
            P = next(P);
        }
}
