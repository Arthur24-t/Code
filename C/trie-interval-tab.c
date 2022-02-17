#include <stdio.h>
#define MAX 50
typedef int Tab[MAX];  //inisialisation du tableau

int posmin ( int i , int j, Tab t);

void afficherTableau(Tab T, int nb) // affichage
{
  int i=0;
  for(i=0; i<nb; i++) printf("%d ", T[i]);
  printf("\n");
}

void permuter(Tab T, int i, int j) //fonction permuter pour tri
{

  int a = T[i];
  T[i] = T[j];
  T[j] = a;
}

int posmax ( int i, int n, Tab t) // recherche de la position max
{
int max=0, posi=0;

for (;i < n-1 ; i++)
{
    if (t[i] > max)// selection du Min ou max
    {
        max = t[i];
        posi= i+1;
        
    }
}
 return posi;
}

void tri_extract ( int n, Tab t ) // tri par extration decroissant
{
    int i,j;
    for( i = n-1; i>0; i--)
    {
        int k = i;
        for( j=0; j<i; j++)
        {
            if(t[j] < t[k]) // selection croissant decroissant
            {
                k = j;
            }
        }
        if(k!=i)
        {
            permuter(t, i, k);
        }
    } 
    //posmax et mosmin dans le tri 
    int positionMin=0, positionMax=0; // initialisation de la valeur min et max 
    int v, w; // inisialisation de l'intervalle 

     printf("entre un invertal\n");
    scanf("%d%d", &v, &w);
    positionMax = posmax(v,w, t);
positionMin = posmin(v,w, t);
printf("\nla position de la valeur la plus grande est : %d\net la plus petite : %d\n", positionMax, positionMin);
printf("-------------------------\n");
afficherTableau(t,n);
}

int posmin ( int i , int j, Tab t) // recherche de la position min 
{
int min=100, posi=0;

for (;i < j-1 ; i++)
{
    if (t[i] < min)// selection du Min ou max
    {
        min = t[i];
        posi= i+1;
        
    }
}
 return posi;
}


int main(void) // fonction principal
{
int positionMin=0, positionMax=0; //variable qui va prendre la valeur de la position min max
int N=7;
Tab x ={15, 9, 13, 6, 5, 14, 10}; //valeur mise dans le tableau 
tri_extract(N, x);
}   