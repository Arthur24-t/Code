#ifndef velo_hpp
#define velo_hpp

#include <iostream>
using namespace std;

class velo {
    protected:
int id;
int etat; // 0 cassée 1 empruntable 2 empruntée 
public:
    velo();
    velo(int, int);
   int getId();
   int getEtat();
    void setId(int);
   void setEtat(int);
    void emprunter(int);
    void restituer(int);
    bool estEmpruntable();
    bool estEmprunte();

};

#endif 