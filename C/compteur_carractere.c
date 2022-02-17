#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char chaine[] = "Salut"; // initialisation tableau 
    int longueurChaine = 0; 

    // On récupère la longueur de la chaîne dans longueurChaine
    longueurChaine = strlen(chaine); //strlen est le compteur et on met dans la valeur chaine

    // On affiche la longueur de la chaîne
    printf("La chaine %s fait %d caracteres de long", chaine, longueurChaine);

    return 0;
}

//size_t strlen(const char* chaine); le prototype