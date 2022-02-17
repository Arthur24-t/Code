#include <stdio.h>
#define MAX 50
typedef int Tab[MAX];  

int pmax ( int nb, Tab z );
void pmax2 (int nb, Tab z, int * ppos);
void affichage (int k, Tab U);
void tri ( int n, Tab z );

void saisie ( int k, Tab t )
{
int nb;
for (int i = 0; i < k; i++)
{
    printf("choisi un nombre\n");
scanf("%d", &t[i]);
}

}


int main(void)
{
int nb, aff, position;
Tab x;
int * ppos;
printf("donner le nombre de valeur a mettre\n");
scanf("%d", &nb);
saisie(nb, x);
printf("combien de chiffre voulez vous afficher ?\n");
scanf("%d", &aff);
tri(nb, x);
affichage(aff, x);
position = pmax(nb, x);
//pmax2(nb, x, ppos);
printf("\nla position de la valeur la plus grande est : %d", position);
}

void affichage (int k, Tab U)
{
for ( int i = 0; i < k; i++)
{
    printf(" x[%d]=%2d",i,U[i]);

}

}

int pmax ( int nb, Tab z )
{
int max=0, posi=0;

for (int i = 0; i < nb; i++)
{
    if (z[i] > max)
    {
        max = z[i];
        posi= i+1;
        
    }
}
 return posi;
}

/*void pmax2 (int nb, Tab z, int * ppos)
{
int max=0;

for (int i = 0; i < nb; i++)
{
    if (z[i] > max)
    {
        max = z[i];
        *ppos= i+1;
        
    }
}
}
*/

void tri ( int n, Tab z )
{
int i,j,c;
for(i=0;i<n-1;i++)

    for(j=i+1;j<n;j++)

        if ( z[i] > z[j] ) {
            c = z[i];
            z[i] = z[j];
            z[j] = c;
        }
}