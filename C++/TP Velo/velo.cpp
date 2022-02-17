#include <iostream>
using namespace std;
#include "velo.hpp"


velo::velo(){
id=0000;
etat=0000;

}
    velo::velo(int _id, int _etat){
id=_id;
etat=_etat;

    }
   int velo::getId(){
return id;

   }
   int velo::getEtat(){
return etat;

   }
    void velo::setId(int _id){
id = _id;

    }
   void velo::setEtat(int _etat){
etat=_etat;

   }
    void velo::emprunter(int){
etat=2;

    }
    void velo::restituer(int){
etat=1;

    }

bool velo::estEmpruntable(){
if (etat == 1)
{
    return true;
}
else
cout<< "pas empruntable"<< endl;
}

    bool velo::estEmprunte(){
if (etat ==2)
{
    return 2;
}
else
cout<< "pas emprunté"<< endl;
}
