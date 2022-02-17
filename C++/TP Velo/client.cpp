#include <iostream>
using namespace std;
#include "client.hpp"


client::client(){
nom = "inconnue";
nbEmpruntEnCours = 0;
}
    client::client(string _nom, int _nb){
nom= _nom;
nbEmpruntEnCours=_nb;
    }
    string client::getNom(){
        return nom;

    }
    int client::getNbEmprunt(){
        return nbEmpruntEnCours;

    }
    void client::setNom(string _nom){
nom =_nom;

    }
    void client::setNbEmprunt(int _nb){
nbEmpruntEnCours =_nb;

    }
    client& client::operator++(){
nbEmpruntEnCours++;
return(*this);

    }
    client& client::operator--(){
nbEmpruntEnCours--;
return(*this);
    }