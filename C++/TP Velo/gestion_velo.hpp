#ifndef gestion_velo_hpp
#define gestion_velo_hpp
#include "client.hpp"
#include "velo.hpp"
#include "emprunt.hpp"

#include <vector>

class GestionVelo {

vector<velo> lesVelos;
vector<client> lesClients;
vector<emprunt> lesEmprunts;


public:
    GestionVelo();
    
    void afficherVelosEmpruntables();
    void afficherEmprunt(emprunt);
    void ajouterClient();
    void emprunter(emprunt&);
    void restituer(emprunt&);
    void quiAEmprunte(client&);
    void ajouterVelo(vector<velo>);
   
 
};

#endif 