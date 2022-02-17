#include <iostream>
#include <fstream>
#include <string>
#include "personnage.h"
using namespace std;

void Personnage::recevoirDegats(int nbDegats) // le nom de la classe avec :: et nom de la methode 
{
    m_vie -= nbDegats;
    //On enlève le nombre de dégâts reçus à la vie du personnage

    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
}
void Personnage::attaquer(Personnage& cible)
{
    cible.recevoirDegats(m_arme.getDegats());
    //On inflige à la cible les dégâts que cause notre arme
}

void Personnage::lancerSort(Personnage& cible, int manaenmoins)
{

    cible.recevoirDegats(m_Sort.getDegats());

    manaenmoins = m_mana - Magie.m_coutmana;


    if (m_mana > 100)
    {
        m_mana = 0;
    }

    }

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant()
{
    if (m_vie > 0) //Plus de 0 de vie ?
    {
        return true; //VRAI, il est vivant !
    }
    else
    {
        return false; //FAUX, il n'est plus vivant !
    }
}

bool Personnage::niveaumagie()
{
    if (m_mana > 0) //niveau de vie 
    {
        return true; //VRAI, il a assez de mana pour un sort 
    }
    else
    {
        return false; //FAUX, il n'en a plu il peux pas lancer de sort 
    }


}


Personnage::Personnage() : m_vie(100), m_mana(100)
{
    //vide
}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{

}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();

}