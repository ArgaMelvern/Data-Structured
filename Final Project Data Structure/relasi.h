#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "programmer.h"
#include "project.h"
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define parent(P) P->parent
#define child(P) P->child
#define infoPenugasan(P) P->infoPenugasan

using namespace std;

typedef struct relasiElmList *adrRel;

struct relasiElmList{
    string infoPenugasan;
    adrProg parent;
    adrProj child;
    adrRel next;
};

struct relasiList{
    adrRel first;
};

void createList (relasiList &R);
adrRel allocate(adrProg Progr, adrProj Proj);
void insertFirst (relasiList &L, adrRel E);
void updatePenugasan(relasiList &L,adrProg Progr,adrProj Proj);
void deleteElm (relasiList &L, adrRel &E);
adrRel findElm (relasiList L, adrProg Progr, adrProj Proj);
void connect (relasiList &L, ProgrammerList PL, ProjectList JL);
void disconnect (relasiList &L, adrProg Progr, adrProj Proj);
void printRelP (relasiList RL,ProgrammerList PL);
void printRelC (relasiList RL,ProjectList JL);
int TotalPenugasan(ProjectList L);
void printRelasiP(relasiList &L, adrProg &Progr);
void printRelasiJ(relasiList &L, adrProj &Proj);

#endif // RELASI_H_INCLUDED
