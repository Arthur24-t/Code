#include <iostream>
using namespace std;
#include "gestion_velo.hpp"
#include <fstream>
#include <string>



GestionVelo::GestionVelo(){

}


    void GestionVelo::afficherVelosEmpruntables(){

int id;
int etat;
velo Lesvelos(id, etat);

ifstream f2("dataVelos.txt");
string uneChaine;
if (! f2.is_open())
cerr<<"impossible d'ouvrir le fichier "<<endl;
else
{
while (f2 >> uneChaine)
cout<<"lu : "<< uneChaine << endl;
f2.close();


}}


void GestionVelo::afficherEmprunt(emprunt e1){

e1.afficher();


    }
    
    void GestionVelo::ajouterClient(){

vector<client> *tempClient;
    tempClient = &lesClients;
    ifstream f1("Clients.txt");
    if(! f1.is_open())
        {cerr<<"\nImpossible d'ouvrir le fichier"<<endl;}
    else
    {
        client cli;
        string chaine;
        int nb;
        while(f1 >> chaine)
        {
            for(int x=0;x<2;x++){
                if(x%2==0)
                {
                    string nvNom = chaine;
                    cli.setNom(nvNom);
                }
                else if(x%2==1)
                {
                    int nvNb = stoi(chaine);
                    cli.setNbEmprunt(nvNb);
                }
            }
            tempClient->push_back(cli);
        }
        int x=0;
        for(auto i: *tempClient)
        {
            if(x%2==0)
            {cout<<"\nId = "<<i.getNom();}
            else
            {cout<<", etat = "<<i.getNbEmprunt()<<endl;}
            x++;
        }

        f1.close();

    }
    }
    void GestionVelo::emprunter(emprunt &e1){

    e1.setEnCours(true);
    }

    void GestionVelo::restituer(emprunt &e1){
     e1.setEnCours(false);

    }
    void GestionVelo::quiAEmprunte(client &cli1){
        
    cout<<cli1.getNom()<< " a emprunté le velo"<<endl;
    }
   

    void GestionVelo::ajouterVelo(vector<velo> lesVelos){

    vector<velo> *tempVelos;
    tempVelos = &lesVelos;
    ifstream f1("Velos.txt");
    if(! f1.is_open())
        {cerr<<"\nImpossible d'ouvrir le fichier"<<endl;}
    else
    {
        velo vel;
        string chaine;
        int nb;
        while(f1 >> chaine)
        {
            for(int x=0;x<2;x++){
                if(x%2==0)
                {
                    int nvID = stoi(chaine);
                    vel.setId(nvID);
                }
                else if(x%2==1)
                {
                    int nvEtat = stoi(chaine);
                    vel.setEtat(nvEtat);
                }
            }
            tempVelos->push_back(vel);
        }
        int x=0;
        for(auto i: *tempVelos)
        {
            if(x%2==0)
            {cout<<"\nId = "<<i.getId();}
            else
            {cout<<", etat = "<<i.getEtat()<<endl;}
            x++;
        }

        f1.close();
    }
}
