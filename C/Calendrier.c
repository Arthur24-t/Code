// Projet   : Affichage de calendriers dans le cadre du TD5/6
//          : de Méthodologie de programmation informatique
//          : en DEUST IOSI 1 - UPHF/INSA (c) 2015-2021
// Auteur   : D. Duvivier
// Version  : 1.0.0
// Date     : 06/02/2021
// Licence  : Exclusivement utilisable dans le cadre des TD/TP
//          : de Méthodologie de programmation informatique
//          : en DEUST IOSI 1 - UPHF/INSA (c) 2015-2021
// Limites  : Cette version ne teste aucun code de retour (de scanf & ...).
//          : Elle ne teste pas non plus la validité des paramètres
//          : (au minimum: jour du mois entre 1 et 31, jour de semaine entre 0
//          : et 6, année supérieure ou égale à 1582...)
//          : TODO: A vous de le faire !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//          : TODO: Améliorez l'affichage conformément aux exemples fournis
//          : sur Moodle : Chaque mois est affiché dans une zone rectangulaire
//          : en forme de grille/matrice.
//          : Attention : il faut un traitement particulier pour les mois dont
//          : la dernière semaine se termine un samedi en ce cas...
//
///////////////////////////////////////////////////////////////////////////////
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //
// ! VERSION COMPLETE, SANS TEST SUR LES PARAMETRES ET LES CODES DE RETOUR ! //
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //
///////////////////////////////////////////////////////////////////////////////
//
#include <stdio.h>

// Constantes pour définir le numéro du mois
// (INC est un mois invalide, dont le numéro est "0") :
#define INC 0
#define JAN 1
#define FEV 2
#define MAR 3
#define AVR 4
#define MAI 5
#define JUN 6
#define JUI 7
#define AOU 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

// Constantes pour définir le numéro du jour de la semaine courante :
#define DIMANCHE 0
#define LUNDI    1
#define MARDI    2
#define MERCREDI 3
#define JEUDI    4
#define VENDREDI 5
#define SAMEDI   6


void viderbuffer(void)
{
  scanf("%*[^\n]");
}

// Tableau de caractères "statique" contenant la première lettre de chaque jour
// de la semaine :
char PremLettreJour[] = {'D', 'L', 'M', 'M', 'J', 'V', 'S'};

// Tableau de chaînes de caractères "statique" contenant une chaîne de
// caractères pour "afficher" chaque mois en fonction de son numéro
// (i.e. en fonction de l'indice de ce tableau).
// Ci-dessous, l'indice du premier mois valide est "1" et non "0"
// --> Nous indroduisons un mois "Incorrect" à l'indice 0 car les tableaux
// commencent forcément à l'indice "0" en langage C.
char *NomMois[] = {"Incorrect", "Janvier", "Fevrier", "Mars", "Avril", "Mai",
		   "Juin", "Juillet", "Aout", "Septembre", "Octobre",
		   "Novembre", "Decembre"};

// Retourne 1 si l'année est bisextile,
// 0 sinon
// -1 si l'année est incorrecte (i.e. < 1582)
// TODO : Contrôler/tester les valeurs des paramètres
// et retourner -1 si nécessaire.
//
// Principe : sont bissextiles les années
// - soit divisibles par 4 mais non divisibles par 100 ;
// - soit divisibles par 400.
int JourIntercalaire(int annee)
{
  if ((annee % 400 == 0) || ((annee % 4 == 0) && (annee % 100 != 0)))
    return 1;
  else
    return 0;
}

// Calcule le premier jour du mois.
// Retourne le jour (entre 0 et 6) de la première semaine du mois.
// Retourne une valeur négative en cas de problème
//
// D'après l'Algorithme de Mike Keith :
// Dans un article publié en 1990 dans le Journal of Recrational Mathematics,
// Vol. 22, No. 4, 1990, p. 280, Mike Keith propose un algorithme pour la
// détermination du jour de la semaine correspondant à une date quelconque.
// Sa formule est inspirée de la congruence de Zeller.
// Source :
// http://fr.wikibooks.org/wiki/Curiosit%C3%A9s_math%C3%A9matiques/Trouver_le_jour_de_la_semaine_avec_une_date_donn%C3%A9e
//
// Jour de semaine (en supposant que la division soit entière/Euclidienne) :
// si m >= 3,
//   D = ( (23*m)/9 + d + 4 + y + y/4 - y/100 + y/400 - 2 ) mod 7
// sinon
//   D = ( (23*m)/9 + d + 4 + y + z/4 - z/100 + z/400 ) mod 7
//
// Comme Mike Keith est un Mathématicien Américain,
// D = Day pour Jour ; M = Month pour Mois et Y = Year pour Année
//
// Pour l'explication de la Division par 100 et par 400,
// c'est pour savoir si l'année est Bissextile  :
// Si Y n'est pas divisible par 4, l'année n'est pas Bissextile.
// Si Y est divisible par 4, l'année est Bissextile
// sauf si A est divisible par 100 et pas par 400.
//
// D = Jour de semaine (D = 0 à 6; 0 = Dimanche, 1 = Lundi, ... , 6 = Samedi)
// m = Mois (m = 1 à 12; 1 = Janvier, 2 = Février, 3 = Mars, ... , 12 = Décembre)
// d = Jour dans le mois (i.e. quantième) (d = 1 à 31)
// y = année
// z = y - 1
// mod 7 = reste de la division par 7 (i.e. calcul de modulo)
//
// Exemples :
// 1er cas : m < 3
// ===============
// Le 18 janvier 1953 tombait quel jour de la semaine ?
// d = 18, m = 1, y = 1953 et z = y-1 = 1952; d'où :
// D = { [(23x1)/9] + 18 + 4 + 1953 + [1952/4] - [1952/100] + [1952/400] } mod 7
// D = (2 + 18 + 4 + 1953 + 488 - 19 + 4) mod 7
// D = 2450 mod 7 = 0 car 2450 = 7 x 350 + 0
// 18 janvier 1953 = un Dimanche
//
// 2eme cas : m > 3
// ================
// Le 2 août 1953 tombait quel jour de la semaine ?
// d = 2, m = 8, y = 1953 et z = y = 1953; d'où :
// D = { [(23x8)/9] + 2 + 4 + 1953 + [1953/4] - [1953/100] + [1953/400] - 2 } mod 7
// D = (20 + 2 + 4 + 1953 + 488 - 19 + 4 - 2) mod 7
// D = 2450 mod 7 = 0 car 2450 = 7 x 350 + 0
// 2 août 1953 = un Dimanche
//
// 3eme cas : m = 3
// ================
// Le 13 mars 1998 tombait quel jour de la semaine ?
// d = 13, m = 3, y = 1998 et z = y = 1998; d'où :
// D = { [(23x3)/9] + 13 + 4 + 1998 + [1998/4] - [1998/100] + [1998/400] - 2 } mod 7
// D = (7 + 13 + 4 + 1998 + 499 - 19 + 4 - 2) mod 7
// D = 2504 mod 7 = 5 car 2504 = 7 x 357 + 5
// 13 mars 1998 = un Vendredi 13 !
//
// TODO : Contrôler/tester les valeurs des paramètres
// TODO : Vérifiez si "mon implémentation" est correcte ou si j'ai laissé
//        des erreurs...
int PremierJourDuMois(int mois, int annee)
{
  int z = annee - 1;

  if (mois >= 3)
    return (((23 * mois) / 9) + 5 + annee + annee/4 - annee/100 + annee/400 - 2 ) % 7;
  else
    return (((23 * mois) / 9) + 5 + annee + z/4 - z/100 + z/400 ) % 7;
}

// Retourne le nombre de jour du mois
// (i.e. 31, 30, 29 ou 28).
// Retourne une valeur négative en cas de problème

int NbJoursDuMois(int mois, int annee)
{

int nbJours;
switch(mois)
   {
   case JAN : nbJours= 31; break;
   case FEV : 
   if (JourIntercalaire(annee))
   {
     nbJours= 29;
   }
   else
   {nbJours=28;
   }
   ; break;
   case MAR : nbJours= 31;; break;
   case AVR : nbJours= 30;; break;
   case MAI : nbJours= 31;; break;
   case JUN : nbJours= 30;; break;
   case JUI : nbJours= 31;; break;
   case AOU : nbJours= 31;; break;
   case SEP : nbJours= 30;; break;
   case OCT : nbJours= 31;; break;
   case NOV : nbJours= 30;; break;
   case DEC : nbJours= 31;; break;
   default : nbJours=-1;
   }

return nbJours;


}

// Affiche l'entête pour chaque mois dans le calendrier,
// i.e. le mois (chaîne de caractères), l'année et les
// première lettres des jours de la semaine, en colonnes...
// TODO : Contrôler/tester les valeurs des paramètres
void AfficherEnTete(int mois, int annee)
{
  int j; // Boucle pour parcourir les jours
  printf("\n%22s %d\n", NomMois[mois], annee);
  puts("*******************************************");
  printf("*");
  for (j=0; j<=6; j++)
    printf("  %c  *", PremLettreJour[j]);
  puts("");
  puts("*-----+-----+-----+-----+-----+-----+-----*");
}

// Complête la première ligne de la grille du calendrier d'un mois en le
// remplissant à l'aide de cases vides pour obtenir un "bel aspect"
// sous forme de "grille complètes".
//
// Le paramètre "premierjour" est le numéro du jour
// (entre 0 et 6, i.e. DIM à SAMEDI)
// dans la première semaine du mois.
//
// TODO : Contrôler/tester les valeurs des paramètres
void AfficherCasesDebut(int mois, int annee, int premierjour)
{
  int vide; // Nombre de jours "vides" en fin de mois

  for (int i =0; i < premierjour; i++)
  {
    printf("|--*--");
  }
  
}

// Complête la dernière ligne de la grille du calendrier d'un mois en le
// remplissant à l'aide de cases vides pour obtenir un "bel aspect"
// sous forme de "grille complètes".
//
// Le paramètre "premierjour" est le numéro du jour
// (entre 0 et 6, i.e. DIM à SAMEDI)
// dans la première semaine du mois.
//
// TODO : Contrôler/tester les valeurs des paramètres
void AfficherCasesFin(int mois, int annee, int premierjour)
{
  int nombrejours; // Nombre de jours dans le mois
  int restejour; // Jours de la dernière semaine du mois
  int vide; // Nombre de jours "vides" en fin de mois

  nombrejours = NbJoursDuMois(mois, annee);

restejour= 35-(premierjour + nombrejours);
if (restejour > 0)
{
  
  for (int i = 0; i < restejour; i++)
  {
    printf("|--*--");
  }
  
}
else if (restejour < 0)
{
  restejour= 42-(premierjour + nombrejours);

  for (int i = 0; i < restejour; i++)
  {
    printf("|--*--");
  }
}






}

// Complête le calendrier d'un mois en le remplissant à
// l'aide des quantièmes (i.e. numéros successifs des jours
// du mois courant (1..31 ou 1..30 ou 1..29 ou 1..28)).
//
// Le paramètre "premierjour" est le numéro du jour
// (entre 0 et 6, i.e. DIM à SAMEDI)
// dans la première semaine du mois.
//
// LE CODE N'EST PAS FOURNI EN CE POINT !!!
// ------------------------------------
// TODO : Contrôler/tester les valeurs des paramètres
// TODO : Complétez ce code
void AfficherDates(int mois, int annee, int premierjour)
{
  int nombrejours; // Nombre de jours dans le mois
  int jour=1; // Valeur entre 1 et  nombrejours
 int test=0;
 nombrejours = NbJoursDuMois(mois, annee);

for (;jour <= nombrejours; jour++)
{
  
test= jour + premierjour;

printf("|%3d  ", jour);
if (test == 7 || test == 14 || test == 21 || test == 28 || test== 35)
{
  printf("\n");
}

}



  // Indice : Une boucle "pour" utilisant la variable "jour"
  // et un modulo sur (jour + premierjour) peut vous aider à
  // afficher correctement les numéros des jours en utilisant
  // printf("|%3d  ", jour);
}

// Affiche l'entête puis les quantièmes dans un "tableau"
// (calendrier du mois) pour le mois courant passé en paramètre.
// "premjourdumois" doit contenir le jour (entre 0 et 6)
// de la première semaine du mois. Il est calculé par la fonction
// PremierJourDuMois().
//
// LE CODE N'EST PAS FOURNI EN CE POINT !!!
// ------------------------------------
// TODO : Contrôler/tester les valeurs des paramètres
// TODO : Complétez ce code si nécessaire
void AfficherMois(int mois, int annee, int premjourdumois)
{
  AfficherEnTete(mois, annee);
  AfficherCasesDebut(mois, annee, premjourdumois);
  AfficherDates(mois, annee, premjourdumois);
  AfficherCasesFin(mois, annee, premjourdumois);

  puts("");
  puts("*******************************************");

}

// Lit et retourne l'année saisie par l'utilisateur
// TODO : Utilisez une saisie durcie
// et vérifiez si l'année est supérieure à 1582
// et inférieure à 3000
//
int LireAnnee(void)
{
  int annee;
  int coderetour;
  puts("Entrez l'annee :");
  coderetour = scanf("%4d", &annee);
  if (coderetour < 1)
  {
    viderbuffer();
    return -10000;
  }
  
  return annee;
}

// Calcule le premier jour du mois
// Retourne une valeur négative en cas de problème
int PremierJanvier(int annee)
{
  return PremierJourDuMois(1, annee);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////// PROGRAMME PRINCIPAL /////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int main(void)
{
  int mois, annee;

  // Les 6 lignes suivantes sont utilisées en mode débuggage pour tester le
  // (bon?) fonctionnement du programme :
  printf("1800 bissextile ? %d\n", JourIntercalaire(1800));
  printf("1990 bissextile ? %d\n", JourIntercalaire(1990));
  printf("1991 bissextile ? %d\n", JourIntercalaire(1991));
  printf("1992 bissextile ? %d\n", JourIntercalaire(1992));
  printf("2000 bissextile ? %d\n", JourIntercalaire(2000));
  printf("2021 bissextile ? %d\n", JourIntercalaire(2021));

  annee = LireAnnee();
if (annee == -10000 || annee <= 1582)
{
  viderbuffer();
  return 0;
}

  // Les 6 lignes suivantes sont utilisées en mode débuggage pour tester le
  // (bon?) fonctionnement du programme :
  for (mois=JAN; mois<=DEC; mois++)
    printf("Premier jour du mois %10s ? %c\n", NomMois[mois],
	   PremLettreJour[PremierJourDuMois(mois, annee)]);

  for (mois=JAN; mois<=DEC; mois++)
    AfficherMois(mois, annee, PremierJourDuMois(mois, annee));

  return 0;
  
}
