// Projet      : Saisir un code à 4 chiffres pour photocopieur
// Fichier     : saisieG2_20192020.c
// Auteur      : moi
// Date        : 03/03/2020
// Version     : 0.0
// Licence     : GPL
// Limitations : Ligne saisie limitée à 255 caractères
// Description : ...
//
#include <stdio.h>

void viderbuffer(void)
{
  char chaine[256];

  scanf("%255s", chaine); // Chaîne de 255 caractères + \0 pour vider buffer clavier
}


//////////////////////////////////////////////////////////////////////////////
void saisircode(unsigned int *millier, unsigned *centaine, unsigned *dizaine, unsigned *unite)
{
  unsigned int valeursaisie; // Valeur saisie par l'utilisateur
  int coderetour; // Code de retour fourni par scanf

  do {
    puts("Saisissez un code à 4 chiffres :");
    coderetour = scanf("%1u%1u%1u%1u",millier, centaine, dizaine, unite);
    valeursaisie = 1000 * *millier + 100 * *centaine + 10 * *dizaine + *unite;
    // printf("La valeur saisie vaut : %u\n", valeursaisie);
    // printf("La valeur saisie vaut : %1u %1u %1u %1u\n", *millier, *centaine, *dizaine, *unite);
    // printf("La valeur du code de retour vaut : %d\n", coderetour);
    if (coderetour != 4) {
      puts("code incorrect");
      valeursaisie = 2147483647;
      viderbuffer();
    }
  } while (valeursaisie > 9999);
}

//////////////////////////////////////////////////////////////////////////////
//
// Retourne 1 si le code est valide
// 0 sinon
int codevalide(unsigned int d1, unsigned int d2, unsigned int d3, unsigned int d4)
{
  unsigned int somme = d1 + d2 + d3;
  unsigned int reste = somme % 7;

  if (reste == d4)
    return 1;
  else
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////// PROGRAMME PRINCIPAL ///////////////////////////
//////////////////////////////////////////////////////////////////////////////
/*
   commentaire multiligne

   Descriptif du programme principal
 */
int main (void)
{
  unsigned int d1, d2, d3, d4; // 4 digits/chiffres du code saisi
  
  saisircode(&d1, &d2, &d3, &d4);

  printf("Le code saisi = %u%u%u%u\n", d1, d2, d3, d4);

  if (codevalide(d1, d2, d3, d4) == 1)
    puts("code correct");
  else
    puts("code incorrect");

  return 0;
}