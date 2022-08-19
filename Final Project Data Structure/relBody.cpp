#include "relasi.h"
#include <iostream>

using namespace std;

void createList (relasiList &R){
/*  Is.
    Fs.Membuat List Kosong */
    first(R) = NULL;
}

adrRel allocate(adrProg Progr, adrProj Proj){
    /*  Is.
    Fs.membuat data Penugasan dan mengembalikan address */

    adrRel P = new relasiElmList;
    cout << "Masukan Keyword Penugasan : ";
    cin>> infoPenugasan(P);
    parent(P) = Progr;
    child(P) = Proj;
    next(P) = NULL;
    return P;
}

void insertFirst (relasiList &L, adrRel S){
    if(first(L)==NULL){
        first(L) = S;
    }else{
        next(S) = first(L);
        first(L) = S;
    }
}

void updatePenugasan(relasiList &L,adrProg Progr,adrProj Proj){

/*  Is.List yang berisi Info
    Fs.Memperbarui Info List tersebut */

    adrRel P = findElm(L, Progr,Proj);
    if (P!=NULL){
        cout << "Masukan Keyword Penugasan Baru : ";
        cin>> infoPenugasan(P);
        cout << "Penugasan Berhasil !"<<endl;
    }
}

adrRel findElm (relasiList L, adrProg Progr, adrProj Proj){
    adrRel R=first(L);
    while (R != NULL){
        if (parent(next(R))== Progr && child(next(R)) == Proj){
            return R;
        }
        R=next(R);
    }
    return NULL;
}

void DeleteFirst(relasiList &L,adrRel &P){
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

void DeleteAfter(adrRel &Choose,adrRel &P){
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

void connect (relasiList &L, ProgrammerList PL, ProjectList JL){
    string prj, user;

    cout << "Masukan Username : ";
    cin >> user;
    adrProg P = FindProgList(PL,user,"Update");
    while (P==NULL){
        cout << "Masukan Username dengan benar : ";
        cin >> user;
    }

    cout << "Masukan nama Project : ";
    cin >> prj;
    adrProj J = findProjList(JL,prj,"Update");
    while(J==NULL){
    cout << "Masukan nama Project dengan benar : ";
    cin >> prj;
    }

    if (P!=NULL && J!=NULL){
        adrRel R=allocate(P,J);
        insertFirst(L,R);
        cout<<"Penugasan Berhasil !"<<endl;
    }
}

void disconnect (relasiList &L, adrProg Progr, adrProj Proj){
    adrRel R= NULL;
    if(first(L)!=NULL){
        if(parent(first(L))== Progr && child(first(L)) == Proj){
            DeleteFirst(L,R);
            cout << "Delete Penugasan BERHASIL" << endl;
        }else{
            adrRel Choose = findElm(L,Progr,Proj);
            if(Choose != NULL){
                DeleteAfter(Choose, R);
                cout << "Delete Data BERHASIL" << endl;
            }else{
                cout << "Data yang ingin diDelete tidak di temukan" << endl;
            }
        }
    }else{
        cout << "Data Kosong" << endl;
    }
}

void printRelP (relasiList L, ProgrammerList PL){
    adrProg P = first(PL);
    cout << "===Data Penugasan dari Programmer==="<<endl;
    while (P!=NULL){
        if(infoProg(P).Code=="programmer"){
          cout<<infoProg(P).Username<<" ~ ";
            adrRel R = first(L);
            if (R!=NULL){
                int total = 0;
                while(R!=NULL){
                    if(parent(R)==P){
                        cout<<infoProject(child(R)).ProjectName<<", ";
                        total = total + 1;
                    }
                    R = next(R);
                }
                cout << "Total Project : "<<total<<endl;
            }
        }
        cout<<endl;
        P=next(P);
    }
    cout<<endl<<endl;
}

void printRelC (relasiList L, ProjectList JL){
    adrProj P = first(JL);
    cout << "===Data Penugasan dari Project==="<<endl;
    while (P!=NULL){
        cout<<infoProject(P).ProjectName<<" ~ ";
        adrRel R = first(L);
        if (R!=NULL){
            int total = 0;
            while(R!=NULL){
                if(child(R)==P){
                    cout<<infoProg(parent(R)).Username<<", ";
                    total = total + 1;
                }
                R = next(R);
            }
            cout<<"Total Programmer : "<<total<<endl;
        }
        cout<<endl;
        P=next(P);
    }
    cout<<endl<<endl;
}

int TotalPenugasan(ProjectList L){
    int Projects = 0;
    if((isEmpty(L))){
        return 0;
    }else{
        adrProj Q =  first(L);
        while(Q != NULL){
            Projects = Projects + 1;
            Q = next(Q);
        }
        return Projects;
    }
}

void printRelasiP(relasiList &L, adrProg &Progr){
    adrRel R = first(L);
    while(R!=NULL){
        if (parent(R)==Progr){
            cout << "+++Data Penugasan untuk "<<infoProg(parent(R)).Username<<"+++"<<endl;
            cout <<"Nama Project : "<<infoProject(child(R)).ProjectName<<endl;
            cout << "DeadLine : " << infoProject(child(R)).Deadline.Days <<","<<infoProject(child(R)).Deadline.Dates<<"-"<<infoProject(child(R)).Deadline.Months<<"-"<<infoProject(child(R)).Deadline.Years<<endl;
            cout << "Penugasan : "<< infoPenugasan(R)<<endl;
            cout<<endl;
        }
        R = next(R);
    }
}

void printRelasiJ(relasiList &L, adrProj &Proj){
    adrRel R = first(L);
    while(R!=NULL){
        if (child(R)==Proj){
            cout << "+++Data Penugasan untuk Project "<<infoProject(child(R)).ProjectName<<"+++"<<endl;
            cout <<"Nama Programmer : "<<infoProg(parent(R)).Username<<endl;
        }
        R = next(R);
    }
}
