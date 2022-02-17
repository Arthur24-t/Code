#ifndef emprunt_hpp
#define emprunt_hpp

#include <iostream>
#include "velo.hpp"
#include "client.hpp"
#include "emprunt.cpp"
using namespace std;

class emprunt {

velo *velo;
client *client;
bool enCours;

public:
    emprunt();
    emprunt(string, int,string, int, bool);
    bool setEnCours(bool);
    bool getEnCours();
    void estEnCours(bool);
    void terminer();
    void afficher();
   
};

#endif 
