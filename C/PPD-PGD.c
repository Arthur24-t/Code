#include <stdio.h>

int PPD(int nb) // focntion de calcul du PPD
{

    int reste = -1;
    int div = 0;
    int i = 1;

    while (reste != 0) // cherche le plus petit diviseur
    {
        i++;
        reste = nb % i;
    }
    printf("le plus petit diviseur est %d\n", i);
    return i;
}
int PGD(int nb) // focntion de calcul du PGD
{

    int reste = -1;
    int div = 0;
    int i = nb;

    while (reste != 0) // il cherche le plus grand diviseur
    {
        i--;
        reste = nb % i;
    }
    printf("le plus grand diviseur est %d\n", i);
    return i;
}

int NPREM(int nb, int ppd, int pgd) // recherche si c'est un nombre premier
{

    if (nb == ppd) // si le PPD est egale au nombre choisi alors il est premier
    {
        printf("c'est un nombre premier !");
    }
}

int main(void) // fonction principal
{
    int nb = 0;
    int ppd = 0, pgd = 0;
    printf("saisie d'un nombre\n");
    scanf("%d", &nb);
    ppd = PPD(nb);
    pgd = PGD(nb);
    NPREM(nb, ppd, pgd);
}