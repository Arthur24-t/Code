// Projet   : Affichage de bannières verticales directement sur le terminal
//          : dans le cadre du TD3 de Méthodologie de programmation informatique
//          : en DEUST IOSI 1 - UPHF/INSA (c) 2021
// Auteur   : D. Duvivier
// Version  : 1.2.0
// Date     : 22/01/2021
// Licence  : Exclusivement utilisable dans le cadre des TD/TP
//          : de Méthodologie de programmation informatique
//          : en DEUST IOSI 1 - UPHF/INSA (c) 2021
// Limites  : Ce programme est limité aux lettres majuscules C A S P L
//          : et peut afficher LETTRESMAXI (soit 6) lettres au maxi
//          : dans une bannière.
//
//          : TODO: Ajoutez le contrôle des valeurs des paramètres
//          : et des codes de retour au niveau de chaque fonction
//          : TODO: Durcissez les saisies
//
// Exemple du caractère « S » :
//     ******
//     ******
// **  **  **  Ici largeur = 10 (nombre de colonnes)
// **  **  **
// **  **  **  et hauteur = 7 (nombre de lignes)
// ******
// ******
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LARGEURMAXI 24     // Nombre de colonnes maxi par lettre
#define HAUTEURMAXI 24     // Nombre de lignes maxi par lettre
#define LETTRESMAXI 6      // 6 lettres au maxi
#define LIGNESEPARATION 2 


 // Nombre de lignes pour séparer les lettres
			   // Ce n'est pas dans l'énoncé partiel
                           // mais ça a été vu en TD

//////////////////////////////////////////////////////////////////////////////
// Calcule h/4 en corrigeant de manière :
// - à retourner 0 si h <= 0
// - à retourner 1 si h <= 4
//
// Remarque : ceci n'est pas utile avec "l" car la largeur des lettres est
//            forcément >= 5
//
// Note méthodologique : Fonction "auxiliaire" utilisée pour simplifier
//                       l'écriture du programme
//
void viderbuffer(void)
{
  scanf("%*[^\n]");
}

int h4corrige(int h)
{
  if (h <= 0)
    return 0;
  else if (h <= 4)
    return 1;
  else
    return h/4;
}

//////////////////////////////////////////////////////////////////////////////
// Calcule l/8 en corrigeant de manière :
// - à retourner 0 si l <= 0
// - à retourner 1 si l <= 8
//
// Remarque : ceci n'est pas utile avec "h" il n'y a qu'en largeur qu'il
//            peut y avoir 2 barres espacées de l/8 parmi 3 barres
//
// Note méthodologique : Fonction "auxiliaire" utilisée pour simplifier
//                       l'écriture du programme
//
int l8corrige(int l)
{
  if (l <= 0)
    return 0;
  else if (l <= 8)
    return 1;
  else
    return l/8;
}

//////////////////////////////////////////////////////////////////////////////
/* affiche une barre
 * - de "hauteur" lignes
 * - et de "largeur" caractères astérisques ‘*’
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int TracerBarreHorizontale(int hauteur, int largeur)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres par rapport à
  // LARGEURMAXI et HAUTEURMAXI pour les valeurs maximales
  // et par rapport à 1 et 1 pour les valeurs minimales.
  // Retourner une valeur négative en cas d'erreur.

  for (h=0; h<hauteur; h++)
  {
    for (l=0; l<largeur; l++)
      printf("*");
    puts(""); // "Affiche un retour à la ligne"
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
/* affiche une barre
 * - de "hauteur" lignes
 * - et de "largeur" caractères astérisques ‘*’
 * - chaque ligne est précédée de indentation blancs (i.e. espaces)
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int TracerBarreIndentee(int hauteur, int largeur, int indentation)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres par rapport à
  // LARGEURMAXI et HAUTEURMAXI,
  // et par rapport à 1 et 1 pour les valeurs minimales.
  // de plus indentation doit être >= 0 et
  // indentation + largeur doit être <= LARGEURMAXI
  for (h=0; h<hauteur; h++)
  {
    for (l=0; l<indentation; l++)
      printf(" ");
    for (l=0; l<largeur; l++)
      printf("*");
    puts(""); // "Affiche un retour à la ligne"
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
/* affiche une barre de largeur lignes de hauteur caractères astérisques ‘*’
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int Tracer1BarreVerticale(int hauteur, int largeur)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres...
  // TODO: Largeur et hauteur sont inversés, est-ce judicieux ?
  for (l=0; l<largeur; l++)
  {
    for (h=0; h<hauteur; h++)
      printf("*");
    puts(""); // "Affiche un retour à la ligne"
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
/* affiche 2 barres séparées par distance blancs
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int Tracer2BarresVerticales(int hauteur, int largeur, int indentation, int distance)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres...
  // Attention: indentation + 2*distance + 2*hauteur doit être <= LARGEURMAXI
  // TODO: Largeur et hauteur sont inversés, est-ce judicieux ?
  for (l=0; l<largeur; l++)
  {
    for (h=0; h<indentation; h++)
      printf(" ");
    for (h=0; h<hauteur; h++)
      printf("*");
    for (h=0; h<distance; h++)
      printf(" ");
    for (h=0; h<hauteur; h++)
      printf("*");
    puts(""); // "Affiche un retour à la ligne"
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
/* affiche 3 barres séparées par distance12 ou distance23 blancs
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int Tracer3BarresVerticales(int hauteur, int largeur, int indentation,
			    int distance12, int distance23)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres...
  // Attention: indentation + 3*distance + 3*hauteur doit être <= LARGEURMAXI
  // TODO: Largeur et hauteur sont inversés, est-ce judicieux ?
  for (l=0; l<largeur; l++)
  {
    for (h=0; h<indentation; h++)
      printf(" ");
    for (h=0; h<hauteur; h++)
      printf("*");
    for (h=0; h<distance12; h++)
      printf(" ");
    for (h=0; h<hauteur; h++)
      printf("*");
    for (h=0; h<distance23; h++)
      printf(" ");
    for (h=0; h<hauteur; h++)
      printf("*");
    puts(""); // "Affiche un retour à la ligne"
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
int TracerA(int hauteur, int largeur)
{
  int h4 = h4corrige(hauteur);     // h/4 hauteur ou épaisseur des barres horizontales
  int l4 = largeur / 4;            // l/4 largeur ou épaisseur des barres verticales
  int x  = largeur - l4 - l4 - l4; // Indentation 2 barres verticales
  int y  = hauteur - h4 - h4;      // Hauteur des 2 barres verticales

  TracerBarreHorizontale(h4, largeur);
  Tracer2BarresVerticales(l4, y, x, l4);
  TracerBarreHorizontale(h4, largeur);
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
int TracerC(int hauteur, int largeur)
{
  int h4 = h4corrige(hauteur); // h/4 hauteur ou épaisseur des barres horizontales
  int l4 = largeur / 4;        // l/4 largeur ou épaisseur des barres verticales
  int x  = largeur - l4 - l4;  // Distance entre 2 barres verticales
  int y  = hauteur - h4;       // Hauteur des 2 barres verticales

  TracerBarreHorizontale(h4, largeur);
  Tracer2BarresVerticales(l4, y,  0, x);
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
int TracerL(int hauteur, int largeur)
{
  int h4 = h4corrige(hauteur); // h/4 hauteur ou épaisseur des barres horizontales
  int l4 = largeur / 4;        // l/4 largeur ou épaisseur des barres verticales
  int y  = hauteur - h4;       // Hauteur de la barre verticale

  TracerBarreHorizontale(h4, largeur);
  Tracer1BarreVerticale(l4, y);
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
int TracerP(int hauteur, int largeur)
{
  int h4 = h4corrige(hauteur);     // h/4 hauteur ou épaisseur des barres horizontales
  int l4 = largeur / 4;            // l/4 largeur ou épaisseur des barres verticales
  int x  = largeur - l4 - l4 - l4; // Indentation 2 barres verticales
  int y  = hauteur - h4 - h4;      // Hauteur des 2 barres verticales

  TracerBarreHorizontale(h4, largeur);
  Tracer2BarresVerticales(l4, y, x, l4);
  TracerBarreIndentee(h4, largeur - x, x);
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
int TracerS(int hauteur, int largeur)
{
  int h4 = h4corrige(hauteur);          // h/4 hauteur ou épaisseur des barres horizontales
  int l4 = largeur / 4;                 // l/4 largeur ou épaisseur des barres verticales
  int l8 = l8corrige(largeur);          // l/8 distance entre barres verticales 2 et 3
  int x  = largeur - l4 - l4 - l4 - l8; // Distances entre barres verticales 1 et 2
  int y  = hauteur - h4 - h4;           // Hauteur des 3 barres verticales

  TracerBarreIndentee(h4, l4 + l8 + l4, l4 + x);
  Tracer3BarresVerticales(l4, y,  0, x, l8);
  TracerBarreHorizontale(h4, l4 + x + l4);
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
/* Trace/dessine une lettre.
 * Retourne 0 si pas d'erreur, une valeur négative sinon
 *
 * Remarque : Les codes de retour lors du tracé des lettres
 * sont intégralement gérés dans cette fonction.
 * 
 * TODO : Vérifier la validé des paramètres
 */
int TracerLettre(int hauteur, int largeur, char lettre)
{
  int coderetour; // Code de retour de TracerLettre
  
  switch(lettre)
  {
    case 'P': coderetour = TracerP(hauteur, largeur); break;
    case 'A': coderetour = TracerA(hauteur, largeur); break;
    case 'S': coderetour = TracerS(hauteur, largeur); break;
    case 'C': coderetour = TracerC(hauteur, largeur); break;
    case 'L': coderetour = TracerL(hauteur, largeur); break;
    default:  puts("lettre inconnue"); coderetour = -1;
  } // Fin du switch

  return coderetour; // Retourne le code de retour à "l'appelant"
}

//////////////////////////////////////////////////////////////////////////////
// Passe une ou plusieurs lignes pour séparer deux lettres successives
void SeparerLettres(void)
{
  int l; // Variable de boucle sur les lignes

  for (l=0; l <LIGNESEPARATION; l++)
    puts("");
}

//////////////////////////////////////////////////////////////////////////////
/* Saisie de la taille des lettres
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int SaisirTailleDeLettre(int *hauteurDeLettre, int *largeurDeLettre)
{
  int retour=0;
  do
  {
  
  printf("Veuillez saisir la hauteur (<= %d) puis la largeur des lettres (<= %d) :\n",
	 HAUTEURMAXI, LARGEURMAXI);
  
  // TODO : Ci-dessous le code de retour
  // n'est pas pris en compte + redemander les valeurs en boucle si incorrectes
  retour= scanf("%u %u", hauteurDeLettre, largeurDeLettre);
if (retour < 2 || *hauteurDeLettre > HAUTEURMAXI || *largeurDeLettre > LARGEURMAXI 
|| *hauteurDeLettre < 0 || *largeurDeLettre < 0)
{
  viderbuffer();
  *hauteurDeLettre = HAUTEURMAXI +1;
}
else
{
  return 0;
}
  }while (*hauteurDeLettre > HAUTEURMAXI || *largeurDeLettre > LARGEURMAXI);


}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////// PROGRAMME PRINCIPAL /////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int main(void)
{
  unsigned int i; // Variable de boucle (énumère les lettres à afficher)
  int hauteurDeLettre, largeurDeLettre;
  int coderetour; // Code de retour de scanf et TracerLettre
  char message[LETTRESMAXI+1]; // Message saisi + \0
  char lettre; // Lettre à dessiner

  
  puts("\n* Programme d'affichage de bannières verticales *\n") ;

  // TODO : Ci-dessous le code de retour de SaisirTailleDeLettre
  // n'est pas pris en compte + ajouter boucle pour redemander à l'utilisateur
  SaisirTailleDeLettre(&hauteurDeLettre, &largeurDeLettre);

  puts("\nVeuillez entrer le message de 6 caractères maxi\n");
  // TODO : Ci-dessous le code de retour
  // n'est pas pris en compte
  // + ajouter boucle pour redemander à l'utilisateur
  coderetour= scanf("%6s", message);

if (coderetour < 1)
{
  viderbuffer();
  return -1;
  
}


  for (i=0; i<strlen(message); i++)
  {
    lettre = message[i];
    int retour;
    // TODO : Ci-dessous le code de retour
    // n'est pas pris en compte
    retour= TracerLettre(hauteurDeLettre, largeurDeLettre, lettre);
   if (retour < 0)
   {
     puts("erreur arret du programme");
     return -1;
   }
   
    SeparerLettres();
  } // Fin du for

  return 0;
}
