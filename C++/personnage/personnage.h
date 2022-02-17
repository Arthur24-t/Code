#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE
#include "Armes.h"
#include "Magie.h"
#include <string>

class Personnage
{
public:
    Personnage();
    Personnage(std::string nomArme, int degatsArme);
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage& cible);
    void lancerSort(Personnage& cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
    bool niveaumagie();
    void afficherEtat() const;

private:

    int m_vie;
    int m_mana;
    Arme m_arme;
    Magie m_Sort;
};

#endif