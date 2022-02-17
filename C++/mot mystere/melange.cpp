#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "melange.h"


using namespace std;


string melange(string mot)
{


    string motMystere(mot);
    string melange;
while (motMystere.size() != 0)
{
	
    

    int position = rand() % motMystere.size();

melange += motMystere[position];


motMystere.erase(position, 1);  // Retire une lettre

}

    return melange;

}

 