#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "emprunt.hpp"
#include "emprunt.cpp"
#include "client.hpp"
#include "client.cpp"
#include "velo.hpp"
#include "velo.cpp"
#include "gestion_velo.hpp"
#include "gestion_velo.cpp"
#include "vtt.hpp"
#include "vtt.cpp"
#include "velo_route.hpp"
#include "velo_route.cpp"


int main(int argc, char const *argv[])
{
    
velo velo1(34,8);
client cli1("Albert", 4);

cout<<velo1.getId()<<endl;

emprunt e1( &velo1, &cli1, false);

GestionVelo g1;

g1.afficherEmprunt(e1);
g1.emprunter(e1);
g1.afficherEmprunt(e1);
g1.restituer(e1);
g1.afficherEmprunt(e1);
g1.quiAEmprunte(cli1);
return 0;
}