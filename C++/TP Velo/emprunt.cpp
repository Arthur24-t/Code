#include <iostream>
using namespace std;
#include "emprunt.hpp"
#include "velo.hpp"

#include "client.hpp"



emprunt::emprunt(){

velos=NULL;
clients=NULL;
enCours= false;


}

    emprunt::emprunt(velo *veloo, client *clientt, bool encours_){

velos= veloo;
clients=clientt;
enCours= encours_;

    }
    
    void emprunt::setEnCours(bool enCours_){
enCours = enCours_;

    }
    bool emprunt::getEnCours(){
return enCours;
    }
    bool emprunt::estEnCours(){
return enCours;
    }
    void emprunt::terminer(){
enCours= false;
    }
    void emprunt::afficher(){
        if (enCours == true)
        {
            cout<< "il est emprunter"<<endl;
        }
        else if (enCours == false)
        {
            cout<< "il est libre"<<endl;
        }
    }




