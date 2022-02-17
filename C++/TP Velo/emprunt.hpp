#ifndef emprunt_hpp
#define emprunt_hpp

#include <iostream>
#include "velo.hpp"
#include "client.hpp"

using namespace std;

class emprunt {

velo *velos;
client *clients;
bool enCours;

public:
    emprunt();
    emprunt(velo*, client*, bool);
    void setEnCours(bool);
    bool getEnCours();
    bool estEnCours();
    void terminer();
    void afficher();
   
};

#endif 
