#include <iostream>
#include "personnage.h" //Ne pas oublier

using namespace std;

int main()
{
    Personnage david, goliath("epée trop forte", 20);
    //Création de 2 objets de type Personnage : david et goliath

    goliath.attaquer(david); //goliath attaque david
    david.boirePotionDeVie(20); //david récupère 20 de vie en buvant une potion
    goliath.attaquer(david); //goliath réattaque david
    david.attaquer(goliath); //david contre-attaque... c'est assez clair non ? 
    goliath.changerArme("un gros bout de bois", 40);
    goliath.attaquer(david);
    david.lancerSort(goliath);

    cout << "david" <<endl;

    david.afficherEtat();
    cout << endl << "goliath" << endl;
    goliath.afficherEtat();

    return 0;
}