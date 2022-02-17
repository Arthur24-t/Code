// Projet   : Affichage de bannières horizontales via un tableau 2D de
//          : caractères dans le cadre du TD3 de Méthodologie de programmation
//          : informatique en DEUST IOSI 1 - UPHF/INSA (c) 2021
// Auteur   : D. Duvivier
// Version  : 1.1.0
// Date     : 20/04/21
// Licence  : Exclusivement utilisable dans le cadre des TD/TP
//          : de Méthodologie de programmation informatique
//          : en DEUST IOSI 1 - UPHF/INSA (c) 2021
// Limites  : Ce programme est limité aux lettres majuscules C A S P L
//          : et peut afficher LETTRESMAXI (soit 6) lettres au maxi
//          : dans une bannière horizontale.
//          :
// BUT DU TP: Réutiliser autant que possible le code développé pour réaliser
//          : des bannières verticales, afin d'afficher des bannières
//          : horizontales (--> Réutilisation/adaptation de code)
//          :
// N.B.     : Par rapport à la bannière verticale, il est nécessaire de
//          : connaître la "position" de la lettre à tracer dans la bannière
//          : il s'agit de la colonne la plus à gauche de la lettre, elle est
//          : donnée par la formule suivante :
//          : NumeroColonne = position * (largeur + COLONNESEPARATION)
//          : où "position" est le numéro de la lettre à tracer
//          : (entre 0 (pour la première lettre, la plus à gauche)
//          : et 5 (pour la dernière lettre, la plus à droite)
//          : et "largeur" est la largeur actuelle des lettres (<= LARGEURMAXI).
//          : ATTENTION : L'indentation sera par conséquent calculée à partir
//          : de la colonne la plus à gauche de chaque lettre
//          : (elle-même calculée par la formule donnée ci-dessus).
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LARGEURMAXI 24      // Nombre de colonnes maxi par lettre
#define HAUTEURMAXI 24      // Nombre de lignes maxi par lettre
#define LETTRESMAXI 6       // 6 lettres au maxi
#define COLONNESEPARATION 2 // Nombre de colonnes pour séparer les lettres

// Nombre de lignes dans le tableau 2D de caractères
#define MAXLIGNES HAUTEURMAXI

// Nombre de colonnes dans le tableau 2D de caractères
#define MAXCOLONNES (LETTRESMAXI * (LARGEURMAXI + COLONNESEPARATION))

// Définition du type tableau destiné à accueillir la banniere
typedef char TBanniere[MAXLIGNES][MAXCOLONNES];

//////////////////////////////////////////////////////////////////////////////
// Calcule l/4 en corrigeant de manière :
// - à retourner 0 si l <= 0
// - à retourner 1 si l <= 4
//
// Remarque : ceci n'est pas utile avec "h" car la largeur des lettres est
//            forcément >= 5
//
// Note méthodologique : Fonction "auxiliaire" utilisée pour simplifier
//                       l'écriture du programme
//
int l4corrige(int l)
{
  if (l <= 0)
    return 0;
  else if (l <= 4)
    return 1;
  else
    return l/4;
}

void viderbuffer(void)
{
  scanf("%*[^\n]");
}
//////////////////////////////////////////////////////////////////////////////
// Calcule h/8 en corrigeant de manière :
// - à retourner 0 si h <= 0
// - à retourner 1 si h <= 8
//
// Remarque : ceci n'est pas utile avec "l" il n'y a qu'en largeur qu'il
//            peut y avoir 2 barres espacées de h/8 parmi 3 barres
//
// Note méthodologique : Fonction "auxiliaire" utilisée pour simplifier
//                       l'écriture du programme
//
int h8corrige(int h)
{
  if (h <= 0)
    return 0;
  else if (h <= 8)
    return 1;
  else
    return h/8;
}


/* imprime une barre
 * - de "hauteur" lignes
 * - et de "largeur" caractères astérisques ‘*’
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int TracerBarreHorizontale(int hauteur, int largeur,
			   int numerocolonne, TBanniere banniere)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres par rapport à
  // LARGEURMAXI et HAUTEURMAXI pour les valeurs maximales
  // et par rapport à 1 et 1 pour les valeurs minimales.
  // Retourner une valeur négative en cas d'erreur.

  for (h=0; h<hauteur; h++)
    for (l=0; l<largeur; l++)
      banniere[l][numerocolonne + h] = '*';

  return 0;
}

/* imprime une barre
 * - de "hauteur" lignes
 * - et de "largeur" caractères astérisques ‘*’
 * - chaque ligne est précédée de indentation blancs (i.e. espaces)
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int TracerBarreIndente(int hauteur, int largeur, int indentation,
		       int numerocolonne, TBanniere banniere)
{
  int h, l; // variables de boucle

  for (h=0; h<hauteur; h++)
  {
    for (l=0; l<indentation; l++)
      printf(" ");
    for (l=0; l<largeur; l++)
      banniere[h][numerocolonne + l] = '*';
  }
  return 0;
}

/* imprime une barre de largeur lignes de hauteur caractères astérisques ‘*’
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int Tracer1BarreVerticale(int hauteur, int largeur,
			  int numerocolonne, TBanniere banniere)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres...
  // TODO: Largeur et hauteur sont inversés, est-ce judicieux ?
  for (l=0; l<largeur; l++)
    for (h=0; h<hauteur; h++)
      banniere[largeur-h][numerocolonne + l] = '*';

  return 0;
}

/* imprime idem 2 barres séparées par distance blancs
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int Tracer2BarresVerticales(int hauteur, int largeur, int indentation,
			    int distance, int numerocolonne, TBanniere banniere)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres...
  // TODO: Largeur et hauteur sont inversés, est-ce judicieux ?
  for (h=0; h<hauteur; h++)
    for (l=0; l<largeur; l++)
    {
      banniere[distance-h][numerocolonne + l] = '*';
      banniere[h][numerocolonne + l] = '*';
    }

  return 0;
}

/* imprime idem 3 barres séparées par distance blancs
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int Tracer3BarresVerticales(int hauteur, int largeur, int indentation,
			    int distance, int numerocolonne, TBanniere banniere)
{
  int h, l; // variables de boucle

  // TODO: Vérifier la validité des paramètres...
  // TODO: Largeur et hauteur sont inversés, est-ce judicieux ?
  for (l=0; l<largeur; l++)
    for (h=0; h<hauteur; h++)
    {
      banniere[largeur-h][numerocolonne + l] = '*';
      banniere[distance+h][numerocolonne + l] = '*';
      banniere[h][numerocolonne + l] = '*';
    }

  return 0;
}

/* Dessine une lettre
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 */
int TracerA(int hauteur, int largeur,
	    int numerocolonne, TBanniere banniere)
{
  int l4 = l4corrige(largeur);     // l/4 hauteur ou épaisseur des barres horizontales
  int h4 = hauteur / 4;            // h/4 largeur ou épaisseur des barres verticales
  int x  = hauteur - h4 - h4 - h4; // Indentation 2 barres verticales
  int y  = largeur - l4 - l4;      // Hauteur des 2 barres verticales

  TracerBarreHorizontale(h4, largeur, numerocolonne, banniere);
  Tracer2BarresVerticales(l4, y, x, h4, numerocolonne, banniere);
  TracerBarreHorizontale(h4, largeur, numerocolonne+y, banniere);

  return 0;
}

/* Dessine une lettre
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 */
int TracerC(int hauteur, int largeur,
	    int numerocolonne, TBanniere banniere)
{
  int h4 = l4corrige(hauteur); // l/4 hauteur ou épaisseur des barres horizontales
  int l4 = largeur / 4;        // l/4 largeur ou épaisseur des barres verticales
  int x  = largeur;  // Distance entre 2 barres verticales
  int y  = hauteur - x;       // Hauteur des 2 barres verticales

  TracerBarreHorizontale(l4, x, numerocolonne, banniere);
  Tracer2BarresVerticales(h4, largeur,0,x, numerocolonne, banniere);

    return 0;
}

/* Dessine une lettre
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 */
int TracerL(int hauteur, int largeur,
	    int numerocolonne, TBanniere banniere)
{
  int h4 = l4corrige(hauteur); // l/4 hauteur ou épaisseur des barres horizontales
  int l4 = largeur / 4;        // h/4 largeur ou épaisseur des barres verticales
  int y  = hauteur - l4;       // Hauteur de la barre verticale

  Tracer1BarreVerticale(h4, largeur, numerocolonne, banniere);
  TracerBarreHorizontale(l4, y, numerocolonne, banniere);
  

  return 0;
}


/* Dessine une lettre
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 */
int TracerP(int hauteur, int largeur,
	    int numerocolonne, TBanniere banniere)
{
  // TODO : A VOUS D'IMPLEMENTER CETTE FONCTION

  return 0;
}


/* Dessine une lettre
 * à partir du numéro de colonne "numerocolonne"
 * dans le tableau 2D de caractères (bord gauche des lettres)
 */
int TracerS(int hauteur, int largeur,
	    int numerocolonne, TBanniere banniere)
{
  // TODO : A VOUS D'IMPLEMENTER CETTE FONCTION

  return 0;
}


/* Imprime une lettre
 * Retourne 0 si pas d'erreur, une valeur négative sinon
 *
 * Effectue la conversion entre la position de la lettre dans le message
 * (entre 0 et 5)
 * et le numéro de colonne dans le tableau 2D de caractères
 * (entre 0 et MAXCOLONNES-1)
 *
 * TODO: Les codes de retour lors du tracé des lettres
 * ne sont pas gérés --> A JOUTER !
  */
int TracerLettre(int hauteur, int largeur, char lettre,
		 int position, TBanniere banniere)
{
  int numerocolonne = position*(largeur + COLONNESEPARATION);

  switch(lettre)
  {
    case 'P': TracerP(hauteur, largeur, numerocolonne, banniere); break;
    case 'A': TracerA(hauteur, largeur, numerocolonne, banniere); break;
    case 'S': TracerS(hauteur, largeur, numerocolonne, banniere); break;
    case 'C': TracerC(hauteur, largeur, numerocolonne, banniere); break;
    case 'L': TracerL(hauteur, largeur, numerocolonne, banniere); break;
    default:  puts("lettre inconnue"); return -1;
  } // Fin du switch

  return 0;
}

/* Saisie de la taille des lettres
 * Retourne 0 si pas d'erreur, une valeur négative sinon */
int SaisirTailleDeLettre(int *hauteurDeLettre, int *largeurDeLettre)
{
  printf("Veuillez saisir la hauteur (<= %d) puis la largeur des lettres (<= %d) :\n",
	 HAUTEURMAXI, LARGEURMAXI);
   int retour;
  // TODO : Ci-dessous le code de retour
  // n'est pas pris en compte + redemander les valeurs en boucle si incorrectes
  // ATTENTION : Pas de "," ici entre les deux "%d" !!!!!!!!!!!!!!!!!!!!!!!!!!!
  do
  {
  
  
  retour = scanf("%d %d", hauteurDeLettre, largeurDeLettre);
  if (retour < 2 || *hauteurDeLettre > HAUTEURMAXI || *largeurDeLettre > LARGEURMAXI 
|| *hauteurDeLettre < 0 || *largeurDeLettre < 0)
{
  viderbuffer();
  *hauteurDeLettre = HAUTEURMAXI +1;
}
else if (retour < 1)
{
  viderbuffer();
  return -1;
  
}
else
{
  return 0;
}
  }while (*hauteurDeLettre > HAUTEURMAXI || *largeurDeLettre > LARGEURMAXI);

}

// Efface le contenu du tableau 2D contenant la bannière 2D
void EffacerBanniere(TBanniere banniere)
{
  int l, c; // Variables de boucles (lignes, colonnes);

  for (l=0; l<MAXLIGNES; l++)
    for (c=0; c<MAXCOLONNES; c++)
      banniere[l][c] = '.';
}

// Efface le contenu du tableau 2D contenant la bannière 2D.
// Le paramètres longueurmessage est exprimé en nombre de caractères...

// Les numéros de lignes et de colonnes sont affichés pour faciliter la mise au
// point de votre code.
void AfficherBanniere(int hauteur, int largeur, TBanniere banniere, int longueurmessage)
{
  int l, c; // Variables de boucles (lignes, colonnes);

  printf("    ");
  for (c=0; c<longueurmessage*(largeur + COLONNESEPARATION); c++)
    printf("%1d", c/100);
  printf("\n    ");
  for (c=0; c<longueurmessage*(largeur + COLONNESEPARATION); c++)
    printf("%1d", (c/10)%10);
  printf("\n    ");
  for (c=0; c<longueurmessage*(largeur + COLONNESEPARATION); c++)
    printf("%1d", c%10);
  puts("");
  for (l=0; l<hauteur; l++)
  {
    printf("%02d: ", l);
    for (c=0; c<longueurmessage*(largeur + COLONNESEPARATION); c++)
      printf("%c", banniere[l][c]);
    puts("");
  }
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////// PROGRAMME PRINCIPAL /////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int main(void)
{
  TBanniere banniere; // Bannière horizontale de 6 lettres maxi.
  int position; // Variable de boucle (énumère les lettres à afficher)
  int hauteurDeLettre, largeurDeLettre;
  char message[LETTRESMAXI+1]; // 6 lettres maxi + '\0'
  char lettre; // Lettre courante dans le message
  int longueurmessage; // Longueur du message en nombre de lettres
  int coderetour; // Code de retour de scanf

  EffacerBanniere(banniere);

  puts("\n* Programme d'affichage de bannières verticales *\n") ;

  // TODO : Ci-dessous le code de retour de SaisirTailleDeLettre
  // n'est pas pris en compte + ajouter boucle pour redemander à l'utilisateur
  SaisirTailleDeLettre(&hauteurDeLettre, &largeurDeLettre);

  puts("\nVeuillez entrer votre message, constitué de 6 lettres (maxi.) choisies parmi C, S, P, A, L\n");
  // TODO : Ci-dessous le code de retour
  // n'est pas totalement pris en compte
  // + ajouter boucle & message clair pour redemander à l'utilisateur
  do
  {
    coderetour = scanf("%6s", message);

    if (coderetour < 1)
{
  viderbuffer();
  return -1;
  
}

  } while (coderetour < 1 ||  !isalpha(message[0]) || !isupper(message[0]));

  // "Calcul" de la longueur du message à afficher sur la bannière horizontale:
  longueurmessage = strlen(message);

  printf("\nAffichage d'une bannière horizontale comportant %d caractères de hauteur %d et largeur %d :\n",
	 longueurmessage, hauteurDeLettre, largeurDeLettre);

  for (position=0; position<longueurmessage; position++)
  {
    // TODO : Ci-dessous le code de retour
    // n'est pas pris en compte
    lettre = message[position]; // Récupère la lettre en position "position"
    TracerLettre(hauteurDeLettre, largeurDeLettre, lettre,
		 position, banniere);
  } // Fin du for

  AfficherBanniere(hauteurDeLettre, largeurDeLettre, banniere, longueurmessage);

  return 0;
}