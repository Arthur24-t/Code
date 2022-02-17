#include <stdio.h>
#define MAX 50
typedef int Tab[MAX];


void permuter(Tab T, int i, int j)
{

  int a = T[i];
  T[i] = T[j];
  T[j] = a;
}

void afficherTableau(Tab T, int nb)
{
  int i=0;
  for(i=0; i<nb; i++) printf("%d ", T[i]);
  printf("\n");
}

void triTournoi(Tab T, int nb)
{
  printf("Tri par Tournoi, initialement : ");
  afficherTableau(T, nb);
  int nbPermut=0;
  int nbCompt=0;
  int i,j;
  for( i=0; i<nb-1; i++)
  {
    for( j=i+1; j<nb; j++)
    {
        nbCompt++;
      if(T[i] < T[j])
      {
        nbPermut++;
        permuter(T, i, j);
      }
    }
  }
  printf("nb de permutation = %d et nb comparaison =%d\n", nbPermut, nbCompt);
  afficherTableau(T, nb);
}

void triBulle(Tab T, int nb)
{
  printf("Tri par Bulles, initialement :");
  afficherTableau(T, nb);
  int nbPermut=0;
  int nbCompt=0;
  int i,j;
  for( i=0; i<nb; i++)
  {
    for( j=0; j<nb-1; j++)
    {
        nbCompt++;
      if(T[j] < T[j+1])
      {
        nbPermut++;
          int a = T[i];
  T[i] = T[j];
  T[j] = a;
      }
    }
  }
   printf("nb de permutation = %d et nb comparaison =%d\n", nbPermut, nbCompt);
  afficherTableau(T, nb);
}

void triExtraction(Tab T, int nb)
{
  
  printf("Tri par Extraction, initialement : ");
  afficherTableau(T, nb);
  int nbPermut=0;
  int nbCompt=0;
  int i,j;
  for( i=nb-1; i>0; i--)
  {
    int k = i;         
    for( j=0; j<i; j++)
    {
      nbCompt++;
      if(T[j] < T[k])
      {
        k = j;
      }
    }
    nbCompt++;
    if(k!=i)
    {
      nbPermut++;
      permuter(T, i, k);
    }
  }
   printf("nb de permutation = %d et nb comparaison =%d\n", nbPermut, nbCompt);
  afficherTableau(T, nb);
}

void triInsertion(Tab T, int nb)
{

  printf("Tri par Insertion, initialement : ");
  afficherTableau(T, nb);
  int nbPermut=0;
  int nbCompt=0;
  int i;
  for( i=1; i<nb; i++)
  {
    int j = i-1;
    nbCompt++;
    while ( (j>=0) && (T[j] < T[j+1]))
    {
      nbPermut++;
      permuter(T, j, (j+1));
      
      j--;
    }
  }
   printf("nb de permutation = %d et nb comparaison =%d\n", nbPermut, nbCompt);
  afficherTableau(T, nb);
}

int main ( )
{
  printf("\n");
  Tab tab1 ={8, 9, 13, 6, 5, 14, 10};

  triTournoi(tab1, 7);
  printf("\n");

  triBulle(tab1, 7);
  printf("\n");

  triExtraction(tab1, 7);
  printf("\n");

  triInsertion(tab1, 7);
  printf("\n");
}