#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include "programmer.h"
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define infoProject(P) P->infoProject

using namespace std;

typedef struct projElmList *adrProj;

struct DueDate{
    string Days;
    int Dates;
    int Months;
    int Years;
};

struct Project{
    string ProjectName;
    string Description;
    DueDate Deadline;
};


struct projElmList{
    Project infoProject;
    adrProj next;
};

struct ProjectList{
    adrProj first;
};

bool isEmpty(ProjectList L);
/*  Is.
    Fs. Mengecheck apakah list berisi atau tidak */
void CreateChildList(ProjectList &L);
/*  Is.
    Fs.membuat list kosong */
adrProj CreateProject(ProjectList &L);
/*  Is.
    Fs.menbuat data Project dan mengembalikan address */
void insertFirst(ProjectList &L,adrProj P);
/* Is.List mungkin kosong
   Fs.Menambahkan List paling awal */
void insertLast(ProjectList &L,adrProj P);
/*  Is.Tersedia List
    Fs.Menambahkan List paling akhir */
void insertProject(ProjectList &L,adrProj P);
/*  Is.List Mungkin kosong
    Fs.Memasukan address yang berisi info secara terurut menggunakan procedure insert first dan after */
adrProj findProjList(ProjectList &L,string ProjectName,string Key);
/*  Is.Tersedia List
    Fs.Mencari Address yang ditandai dengan ProjectName */
void DeleteFirst(ProjectList &L,adrProj &P);
/*  Is.Tersedia List dan mungkin kosong
    Fs.Menghapus List yang Pertama */
void DeleteAfter(adrProj &Choose,adrProj &P);
/* Is.List Tidak Kosong
   Fs.Menghapus list yang dipilih */
void DeleteDataProject(ProjectList &L,string ProjectName);
/*  Is.List mungkin kosong
    Fs.Menghapus List dengan menggunakan delete first dan delete after */
void UpdateProjectData(ProjectList &L,string ProjectName);
/*  Is.List yang berisi Info
    Fs.Memperbarui Info List tersebut */
bool StatusProject(ProjectList &L,string ProjectName);
/*  Is.List mungkin Kosong atau berisi
    Fs.Mencari Project yang ingin dicari dan mengembalikan status*/
void ShowDataProject(ProjectList &TemptList);
/* Is.
   Fs.Menampilkan Data Project Berdasarkan Deadline  */
void ShowDataProjectSorted(ProjectList &TempList,adrProg Progr);

#endif // PROJECT_H_INCLUDED
