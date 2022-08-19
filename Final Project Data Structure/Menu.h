#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "relasi.h"
#include <iostream>

using namespace std;

void mainMen(ProgrammerList &L_Programmer,ProjectList &L_Project,relasiList &L_relasi,adrRel &L, adrProg &Progr, adrProj &Proj);

void menuAdmin(ProgrammerList &L_Programmer,ProjectList &L_Project,relasiList &L_relasi,adrRel &L,adrProg &Progr, adrProj &Proj);

void menuManager (ProgrammerList &L_Programmer,ProjectList &L_Project,relasiList &L_relasi,adrRel &L,adrProg &Progr, adrProj &Proj);

void menuProgrammer(ProgrammerList &L_Programmer,ProjectList &L_Project,relasiList &L_relasi,adrRel &L,adrProg &Progr, adrProj &Proj);

#endif // MENU_H_INCLUDED
