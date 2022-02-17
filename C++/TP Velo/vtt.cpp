#include <iostream>
using namespace std;
#include "vtt.hpp"


  vtt::vtt():velo(){
nbvitesse=0;

  }
    vtt::vtt(int _id, int _etat, int _nbvitesse):velo(id,etat){
id=_id;
etat=_etat;
nbvitesse=_nbvitesse;
    }
    
   int vtt::getNbVitesse(){
return nbvitesse;

   }
   void vtt::setNbVitesse(int _nbvitesse){
nbvitesse=_nbvitesse;

   }