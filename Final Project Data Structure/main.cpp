#include <iostream>
#include "relasi.h"
#include "Menu.h"

using namespace std;


int main(){
    adrProg Progr;
    adrProj Proj;
    adrRel L;

    ProgrammerList L_Programmer;
    ProjectList L_Project;
    relasiList L_relasi;


    CreateParentList(L_Programmer);
    CreateChildList(L_Project);
    createList(L_relasi);

    mainMen(L_Programmer,L_Project,L_relasi,L,Progr,Proj);
    return 0;
}
