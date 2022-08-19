#include "Menu.h"
#include "stdlib.h"

using namespace std;

void mainMen(ProgrammerList &L_Programmer,ProjectList &L_Project,relasiList &L_relasi,adrRel &L, adrProg &Progr, adrProj &Proj){
 int log;

 system("CLS");

    cout << "+SELAMAT DATANG DI APLIKASI PROJECT MANAGEMENT+"<<endl;
    cout << "========Silahkan login terlebih dahulu=========" << endl;
    cout << "==LOGIN==" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Manager" << endl;
    cout << "3. Programmer" << endl;
    cout << "Pilihan anda (ketikan nomor menu) : ";
    cin >> log;
    while (log > 3 || log < 0){
        cout << "Mohon ketikan nomor menu yang sesuai : ";
        cin >> log;
    }

    string x,y;

    if (log == 1){
        system("CLS");
        cout << "==LOGIN ADMIN=="<<endl;
        cout << "Username : ";
        cin >> x;
        cout << "Password : ";
        cin >> y;

        cout<<endl;

        while ((x != "admin") || (y != "1010")){
            cout << " You're not admin!"<<endl;
            cout << endl;
            cout << "Username : ";
            cin >> x;
            cout << "Password : ";
            cin >> y;
        }

        menuAdmin(L_Programmer,L_Project,L_relasi,L,Progr,Proj);

    } else if (log == 2){
        system("CLS");
        cout << "==LOGIN Manager=="<<endl;
        cout << "Username : ";
        cin >> x;
        cout << "Password : ";
        cin >> y;

        cout<< endl;

        Progr = findUserM(L_Programmer,x,y);

        while (Progr==NULL){
            cout << "You're not Manager!"<<endl;
            cout << "Username : ";
            cin >> x;
            cout << "Password : ";
            cin >> y;
        }

        menuManager(L_Programmer,L_Project,L_relasi , L, Progr, Proj);
    } else if (log == 3){
        system("CLS");
        cout << "==LOGIN Programmer=="<<endl;
        cout << "Username : ";
        cin >> x;
        cout << "Password : ";
        cin >> y;

        cout<<endl;

        Progr = findUserP(L_Programmer,x,y);

        while (Progr==NULL){
            cout << "You're not Programmer!"<<endl;
            cout << "Username : ";
            cin >> x;
            cout << "Password : ";
            cin >> y;
        }

        menuProgrammer(L_Programmer, L_Project, L_relasi, L, Progr, Proj);
    }

}


void menuAdmin(ProgrammerList &L_Programmer,ProjectList &L_Project,relasiList &L_relasi,adrRel &L,adrProg &Progr, adrProj &Proj){
    int mark;

    system("CLS");

    cout << "+++++++++MENU ADMIN+++++++++" << endl;
    cout << "1. Tambah Data Programmer" << endl;
    cout << "2. Edit Data Programmer" << endl;
    cout << "3. Hapus Data Programmer" << endl;
    cout << "4. Tambah Project" << endl;
    cout << "5. Edit Project" << endl;
    cout << "6. Hapus Project" << endl;
    cout << "7. List Data" << endl;
    cout << "8. Keluar" << endl;
    cout << "++++++++++++++++++++++++++++" << endl;
    cout << "Pilihan anda (ketikan nomor menu): ";
    cin >> mark;
     while (mark > 8 || mark < 0){
        cout << "Mohon ketikan nomor menu yang sesuai : ";
        cin >> mark;
    }

    cout << endl;

    cout << endl;
    string user, prj;


    if (mark == 1){//tambah data programmer
        Progr = CreateAccount(L_Programmer);
        insertProgrammer(L_Programmer,Progr);


    } else if (mark == 2){//edit data programmer

        cout << "Masukan Username Programmer : ";
        cin >> user;

        UpdateDataProgrammer(L_Programmer, user);

    } else if (mark == 3){//hapus data programmer
        cout << "Masukan Username Programmer : ";
        cin >> user;

        DeleteProgrammer(L_Programmer,user);

    } else if (mark == 4){// tambah data project

        Proj = CreateProject(L_Project);
        insertProject(L_Project,Proj);

    } else if (mark == 5){//edit data project

        cout << "Masukan Nama Project : ";
        cin >> prj;

        UpdateProjectData(L_Project,prj);

    } else if (mark == 6){//hapus data project
        cout << "Masukan Nama Project : ";
        cin >> prj;

        DeleteDataProject(L_Project, prj);

    } else if (mark == 7){
        int T;

        system("CLS");

        cout << "+++++SILAHKAN PILIH MENU+++++"<<endl;
        cout << "1. Programmer"<<endl;
        cout << "2. Project"<<endl;
        cout << "+++++++++++++++++++++++++++++"<<endl;
        cout << "Silahkan ketikan nomor menu : ";
        cin >> T;
        while (T > 2 || T < 0){
            cout << "Ketikan nomor menu yang sesuai : ";
            cin >> T;
        }

        if (T == 1){
            ShowDataProgrammer(L_Programmer);
        }else if (T == 2){
            ShowDataProject(L_Project);
        }

    }else if (mark == 8){
        mainMen(L_Programmer,L_Project,L_relasi,L,Progr,Proj);
    }

    cout<<endl;
    cout << "Ketik 'back' untuk kembali ke menu : ";
    string x;
    cin >> x;
    if (x == "back" ){
        menuAdmin(L_Programmer,L_Project,L_relasi,L,Progr,Proj);
    }
    cout << endl;
}


void menuManager (ProgrammerList &L_Programmer,ProjectList &L_Project,relasiList &L_relasi,adrRel &L,adrProg &Progr, adrProj &Proj){
    int mark;

    system("CLS");

    cout << "+++++++++MENU MANAGER+++++++++" << endl;
    cout << "1. Tambah Penugasan" << endl;
    cout << "2. Ubah Penugasan" << endl;
    cout << "3. Hapus Penugasan" << endl;
    cout << "4. List Data" << endl;
    cout << "5. Keluar"<<endl;
    cout << "++++++++++++++++++++++++++++++" << endl;
    cout << "Pilihan anda (ketikan nomor menu): ";
    cin >> mark;
     while (mark > 5 || mark < 0){
        cout << "Mohon ketikan nomor menu yang sesuai : ";
        cin >> mark;
    }
    cout << endl;

    string task, user, prj;


    if (mark == 1){//tambah penugasan

        connect(L_relasi,L_Programmer,L_Project);

    } else if (mark == 2){//edit penugasan

        cout << "Masukan Username Programmer : ";
        cin >> user;
        cout << "Masukan Nama Project : ";
        cin >> prj;

        Progr = FindProgList(L_Programmer,user,"Update");
        Proj = findProjList(L_Project,prj,"Update");
        updatePenugasan(L_relasi,Progr,Proj);

        cout<<endl;

    }else if (mark == 3){//delete penugasan
        string key = "Update";

        cout << "Masukan Username Programmer : ";
        cin >> user;
        cout << "Masukan nama Project : ";
        cin >> prj;


        Progr = FindProgList(L_Programmer,user, key);
        Proj = findProjList(L_Project,prj, key);
        disconnect(L_relasi,Progr,Proj);

    } else if (mark == 4){//list data
        int W;

        cout << "+++++SILAHKAN PILIH MENU+++++"<<endl;
        cout << "1. Programmer"<<endl;
        cout << "2. Project"<<endl;
        cout << "3. Penugasan"<<endl;
        cout << "+++++++++++++++++++++++++++++"<<endl;
        cout << "Silahkan ketikan nomor menu : ";
        cin >> W;
        while (W > 3 || W < 0){
            cout << "Ketikan nomor menu dengan benar : ";
            cin >> W;
        }

        if (W == 1){
            cout<<"Masukkan Username Programmer : ";
            cin>>user;

            Progr = FindProgList(L_Programmer,user,"Update");
            printRelasiP(L_relasi,Progr);

        } else if (W == 2){
            cout<<"Masukkan Nama Project : ";
            cin>>prj;

            Proj = findProjList(L_Project,prj,"Update");
            printRelasiJ(L_relasi,Proj);

        } else if ( W == 3){
            int F;

            cout<<endl;
            cout << "= Berdasarkan ="<<endl;
            cout << "1. Programmer"<<endl;
            cout << "2. Project"<<endl;
            cout << "==============="<<endl;
            cout << "Pilih menu (ketikan nomor menu) : ";
            cin >> F;
            while (F > 2 || F < 0){
                cout << "Ketikan nomor menu yang sesuai : ";
                cin >> F;
            }

            if (F == 1){
                printRelP(L_relasi, L_Programmer);
            }else if (F == 2){
                printRelC(L_relasi,L_Project);
            }
        }
    }else if (mark == 5){
        mainMen(L_Programmer,L_Project,L_relasi,L,Progr,Proj);
    }

    cout << endl;
    cout << "Ketik 'back' untuk kembali ke menu : ";
    string x;
    cin >> x;
    if (x == "back" ){
        menuManager(L_Programmer,L_Project,L_relasi,L,Progr,Proj);
    }
    cout << endl;
    cout << endl;

}


void menuProgrammer(ProgrammerList &L_Programmer, ProjectList &L_Project, relasiList &L_relasi, adrRel &L, adrProg &Progr, adrProj &Proj){
    int mark;
    ProjectList N;

    system("CLS");

    cout << "+++++MENU PROGRAMMER+++++" << endl;
    cout << "1. List Penugasan" << endl;
    cout << "2. List Project" << endl;
    cout << "3. Keluar"<<endl;
    cout << "+++++++++++++++++++++++++" << endl;
    cout << "Pilihan anda (ketikan nomor menu): ";
    cin >> mark;
     while (mark > 3 || mark < 0){
        cout << "Mohon ketikan nomor menu yang sesuai : ";
        cin >> mark;
    }
    cout << endl;

    if (mark == 1){// tampilan total penugasan
        int jml = TotalPenugasan(L_Project);
        cout << "Banyak Penugasan : "<<jml;

    }else if (mark == 2){// tampilan project sesuai deadline

        ShowDataProjectSorted(L_Project,Progr);

    }else if (mark == 3){
        mainMen(L_Programmer,L_Project,L_relasi,L,Progr,Proj);
    }

    cout <<endl;
    cout << "Ketik 'back' untuk kembali ke menu : ";
    string x;
    cin >> x;
    if (x == "back" ){
        menuProgrammer(L_Programmer,L_Project,L_relasi,L,Progr,Proj);
    }
    cout << endl;
    cout << endl;
}



