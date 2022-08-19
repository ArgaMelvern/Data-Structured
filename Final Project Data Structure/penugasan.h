#ifndef PENUGASAN_H_INCLUDED
#define PENUGASAN_H_INCLUDED

#include "programmer.h"
#include "project.h"
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define parent(P) P->parent
#define child(P) P->child

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
void updatePenugasan(adrRel &L,adrProg Progr,adrProj Proj);
void deleteElm (relasiList &L, adrRel &E);
adrRel findElm (relasiList L, adrProg Progr, adrProj Proj);
void connect (relasiList &L, ProgrammerList PL, ProjectList JL);
void disconnect (relasiList &L);
void printRel (relasiList RL);


#endif // PENUGASAN_H_INCLUDED
