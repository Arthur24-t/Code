#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "melange.h"


using namespace std;

int main()
{
srand(time(0));
	string Motecrit(""), motmelange("");
	string MotJ2("");
	string Choix("oui");
	string Oui("oui");
	int NbVie(5);


	while (Choix == Oui)
	{


		cout << "ecrit un mot a melanger" << endl; // choix du premier mot 
		cin >> Motecrit;
		cin.ignore();
		motmelange = melange(Motecrit);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

		cout << "c'est parti essaye de le retrouver :" << motmelange << endl;

		do
		{


			cin >> MotJ2;

			if (MotJ2 == Motecrit)
			{
				cout << "bravo c'est bien " << Motecrit << endl;



			}
			else
			{
				NbVie--;
				cout << "c'est faux reessaye il vous reste " << NbVie << endl;

				cout << "ecrit un mot" << endl;



			}
		} while (MotJ2 != Motecrit && NbVie > 0);

		if (MotJ2 == Motecrit)
		{
			cout << "une autre partie ? oui ou non " << endl;
			cin >> Choix;
		}
		else if (NbVie == 0)
		{
			cout << "Vous avez perdu vous n'avez plu de vie !!" << endl << "une autre partie ? oui ou non " << endl;
			cin >> Choix;
		}

	}



return 0;


}
