#include "project.h"
#include <iostream>

using namespace std;

bool isEmpty(ProjectList L){
/*  Is.
    Fs. Mengecheck apakah list berisi atau tidak */
    return first(L) == NULL;
}

void CreateChildList(ProjectList &L){
/*  Is.
    Fs.membuat list kosong */
    first(L) = NULL;
}

adrProj CreateProject(ProjectList &L){
/*  Is.
    Fs.menbuat data Project dan mengembalikan address */

    string NewProject;
    string Desc;
    string Day;
    int Date;
    int Month;
    int Year;

    adrProj P = new projElmList;
    cout<< "Masukan Nama Project : ";
    cin>>NewProject;
    if(!(StatusProject(L,NewProject))){
        infoProject(P).ProjectName = NewProject;
    }
    cout<< "Deadline Project : "<<endl;
    cout<< "Masukan Hari : ";
    cin>>Day;
    infoProject(P).Days = Day;
    cout<< "Masukan Tanggal : ";
    cin>>Date;
    infoProject(P).Dates = Date;
    cout<< "Masukan Bulan : ";
    cin>> Month;
    infoProject(P).Months = Month;
    cout<< "Masukan Tahun :";
    cin>> Year;
    infoProject(P).Years = Year;
    cout<< "Masukan Ketentuan / Deskripsi Tugas : "<<endl;
    cin>> Desc;
    infoProject(P).Description = Desc;
    next(P) = NULL;

    return P;
}

void insertFirst(ProjectList &L,adrProj P){
/* Is.List mungkin kosong
   Fs.Menambahkan List paling awal */
    if(isEmpty(L)){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(adrProj &Choose,adrProj P){
/*  Is.Tersedia List
    Fs.Menambahkan List paling akhir */
    if(next(Choose) == NULL){
        next(Choose) = P;
    }else{
        next(P) = next(Choose);
        next(Choose) = P;
    }
}
void insertProject(ProjectList &L,adrProj P){
/*  Is.List Mungkin kosong
    Fs.Memasukan address yang berisi info secara terurut menggunakan procedure insert first dan after */
    if(isEmpty(L)){
        insertFirst(L,P);
    }else{
        adrProj Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        insertAfter(Q,P);
    }
}

adrProj findProjList(ProjectList &L,string ProjectName,string Key){
/*  Is.Tersedia List
    Fs.Mencari Address yang ditandai dengan ProjectName */
    adrProj P = first(L);
    if(Key == "Update"){
        while(P != NULL){
            if(infoProject(P).ProjectName == ProjectName){
                return P;
            }
            P = next(P);
        }
    }else if(Key == "Delete"){
        while (P != NULL){
            if(info(next(P)).ProjectName == ProjectName){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}
void DeleteFirst(ProjectList &L,adrProj &P){
/*  Is.Tersedia List dan mungkin kosong
    Fs.Menghapus List yang Pertama */
    if(!isEmpty(L)){
        P = first(L);
        if(next(first(L)) == NULL){
            first(L) == NULL;
        }else{
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}
void DeleteAfter(adrProj &Choose,adrProj &P){
/* Is.List Tidak Kosong
   Fs.Menghapus list yang dipilih */
    P = next(Choose);
    if(next(P) == NULL){
        next(Choose) = NULL;
    }else{
        next(Choose) = next(P);
        next(P) = NULL;
    }
}
void DeleteDataProject(ProjectList &L,string ProjectName,adrProj &P){
/*  Is.List mungkin kosong
    Fs.Menghapus List dengan menggunakan delete first dan delete after */
   if(!isEmpty(L)){
        if(ProjectName == info(first(L)).ProjectName){
            deleteFirst(L, P);
            cout << "Delete Data BERHASIL" << endl;
        }else{
            Parentaddress Choose = findProjList(L, ProjectName, "Delete");
            if(Choose != NULL){
            deleteAfter(Choose, P);
            cout << "Delete Data BERHASIL" << endl;
            }else{
            cout<< "Data yang ingin diDelete tidak di temukan"<<endl;
            }
        }
    }
}

void UpdateProjectData(ProjectList &L,string ProjectName){
/*  Is.List yang berisi Info
    Fs.Memperbarui Info List tersebut */

    adrProj P = findProjList(L, ProjectName, "Update");
    char Replace;
    string NewProject;
    if(P != NULL){
        cout << "Nama Project : " << infoProject(P).ProjectName << endl;
        cout << "---UPDATE---" << endl;
        cout << "Nama Project Baru : ";
        cin>>NewProject;
        if(!(StatusProject(L,NewProject))){
            infoProject(P).ProjectName = NewProject;
        }
        cout << "Apakah anda ingin mengganti Deadline? y/n ? ";
        cin >> Replace;
        if(Replace == 'y'){
            cout << "Masukan Hari Deadline : ";
            cin >> infoProject(P).Days;
            cout<< "Masukan Tanggal Deadline : ";
            cin>> infoProject(P).Dates;
            cout<< "Masukan Bulan Deadline ; ";
            cin>> infoProject(P).Months;
            cout<< "Masukan Tahun Deadline ; ";
            cin>> infoProject(P).Years;
            cout<< "Apakah anda ingin mengubah Ketentuan / Deskripsi Project ? y/n ?";
            cin >> Replace;
            if(Replace == 'y'){
                cout<< "Masukan Deskripsi / Ketentuan : ";
                cin>>infoProject(P).Description;
                cout<<"Update Data BERHASIL"<<endl;
            }else{
            cout << "Update Data BERHASIL" <<  endl;
            }
        }else{
            cout << "Update Data BERHASIL" <<  endl;
        }
    }else{
        cout << "Data Tidak Ditemukan" << endl;
        cout << "Update Data GAGAL" <<  endl;
    }
}

bool StatusProject(ProjectList &L,string ProjectName){
/*  Is.List mungkin Kosong atau berisi
    Fs.Mencari Project yang ingin dicari dan mengembalikan status*/

    if(isEmpty(L)){
        return false;
    }else{
        adrProj Q = first(L);
        while(Q != NULL){
            if(info(Q).ProjectName == ProjectName){
                return true;
            }
            Q = next(Q);
        }
        return false;
    }
}

void ShowDataProject(ProjectList &TempList){
/* Is.
   Fs.Menampilkan Data Project Berdasarkan Deadline  */
   cout<<"-----Data Project-----"<<endl;
    if(!isEmpty(L)){
            adrProj Q = first(TempList);
            while(Q != NULL){
            cout << "Project : " << infoProject(P).ProjectName<<endl;
            cout << "DeadLine : " << infoProject(P).Days <<","<<infoProject(P).Dates<<"-"<<infoProject(P).Months<<"-"<<infoProject(P).Years<<endl;
            Q = next(Q);
            }
    }else{
        cout << "Tidak ada Project yang tersedia" << endl;
    }
    cout << endl;
}

void ListProjectSorted(ProjectList L,ProjectList &TempList){
/* Is.Tersedia List awal yang berisi info
   Fs.Menginputkan List Baru dengan List Lama dan Menyusun Berdasar Deadline */
   first(TempList) = NULL;

    if(!(isEmpty(L))){
        Q = first(L);
        while(Q != NULL){
            adrProj P = Q;
            adrProj Temp = P;
            adrProj Finder = next(P);
            while(P != NULL && Finder != NULL){
                if(infoProject(P).Dates <= infoProject(Finder).Dates && infoProject(P).Months <= infoProject(Finder).Months && infoProject(P).Years <= infoProject(Finder).Years){
                Finder = next(Finder);
                }else{
                P = Finder;
                Temp = P
                Finder = next(Finder);
                }
            }
            insertProject(TempList,P);
            DeleteDataProject(L,infoProject(P).ProjectName,Q);
            Q = first(L);
        }
    }
}
