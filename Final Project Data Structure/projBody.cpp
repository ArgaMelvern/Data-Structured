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
    cout<< "==Deadline Project=="<<endl;
    cout<< "Masukan Hari : ";
    cin>>Day;
    infoProject(P).Deadline.Days = Day;
    cout<< "Masukan Tanggal : ";
    cin>>Date;
    infoProject(P).Deadline.Dates = Date;
    cout<< "Masukan Bulan : ";
    cin>> Month;
    infoProject(P).Deadline.Months = Month;
    cout<< "Masukan Tahun : ";
    cin>> Year;
    infoProject(P).Deadline.Years = Year;
    cout<< "Masukan Ketentuan / Deskripsi Tugas : ";
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
    Fs.Memasukan address yang berisi infoProject secara terurut menggunakan procedure insert first dan after */
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
            if(infoProject(next(P)).ProjectName == ProjectName){
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
            first(L) = NULL;
        } else{
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

void DeleteDataProject(ProjectList &L,string ProjectName){
/*  Is.List mungkin kosong
    Fs.Menghapus List dengan menggunakan delete first dan delete after */
   adrProj P;
   if(first(L)!=NULL){
        if(ProjectName == infoProject(first(L)).ProjectName){
            DeleteFirst(L, P);
            cout << "Delete Data BERHASIL" << endl;
        }else{
            adrProj Choose = findProjList(L, ProjectName, "Delete");
            if(Choose != NULL){
                DeleteAfter(Choose, P);
                cout << "Delete Data BERHASIL" << endl;
            }
        }
    }else{
        cout<< "Data yang ingin diDelete tidak ditemukan"<<endl;
    }
}

void UpdateProjectData(ProjectList &L,string ProjectName){
/*  Is.List yang berisi infoProject
    Fs.Memperbarui infoProject List tersebut */

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
            cin >> infoProject(P).Deadline.Days;
            cout<< "Masukan Tanggal Deadline : ";
            cin>> infoProject(P).Deadline.Dates;
            cout<< "Masukan Bulan Deadline ; ";
            cin>> infoProject(P).Deadline.Months;
            cout<< "Masukan Tahun Deadline ; ";
            cin>> infoProject(P).Deadline.Years;
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
            if(infoProject(Q).ProjectName == ProjectName){
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
    if(first(TempList)){
            adrProj P = first(TempList);
            while(P != NULL){
            cout << "Project : " << infoProject(P).ProjectName<<endl;
            cout << "DeadLine : " << infoProject(P).Deadline.Days <<","<<infoProject(P).Deadline.Dates<<"-"<<infoProject(P).Deadline.Months<<"-"<<infoProject(P).Deadline.Years<<endl;
            P = next(P);
            }
    }else{
        cout << "Tidak ada Project yang tersedia" << endl;
    }
    cout << endl;
}

void ShowDataProjectSorted(ProjectList &TempList,adrProg Progr){
/* Is.
   Fs.Menampilkan Data Project Berdasarkan Deadline  */
   cout<<"-----Data Project-----"<<endl;
    if(first(TempList)!=NULL){
            adrProj P = first(TempList);
            while(P != NULL){
                adrProj Q = next(P);
                while(Q!=NULL){
                    if (infoProject(Q).Deadline.Years < infoProject(P).Deadline.Years && infoProject(Q).Deadline.Months < infoProject(P).Deadline.Months && infoProject(Q).Deadline.Dates < infoProject(P).Deadline.Dates){
                        cout << "Project : " << infoProject(Q).ProjectName<<endl;
                        cout << "DeadLine : " << infoProject(Q).Deadline.Days <<","<<infoProject(Q).Deadline.Dates<<"-"<<infoProject(Q).Deadline.Months<<"-"<<infoProject(Q).Deadline.Years<<endl;
                    }
                    Q = next(Q);
                }
                P = next(P);
            }
    }else{
        cout << "Tidak ada Project yang tersedia" << endl;
    }
    cout << endl;

}
