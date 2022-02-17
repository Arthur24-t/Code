#ifndef client_hpp
#define client_hpp

#include <iostream>

using namespace std;

class client {
string nom;
int nbEmpruntEnCours;
public:
    client();
    client(string, int);
    string getNom();
    int getNbEmprunt();
    void setNom(string);
    void setNbEmprunt(int);
    client& operator++();
    client& operator--();
};

#endif 
