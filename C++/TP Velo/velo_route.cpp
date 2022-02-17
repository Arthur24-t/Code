#include <iostream>
using namespace std;
#include "velo_route.hpp"
#include"velo.hpp"


 veloRoute::veloRoute():velo(){
panier= true;

    }

veloRoute::veloRoute(int _id, int _etat, bool _panier):velo(id, etat){
id= _id;
etat=_etat;
panier=_panier;


}
   
   void veloRoute::setPanier(bool _panier){
panier= _panier;

   }
   bool veloRoute::getPanier(){
return panier;

   }