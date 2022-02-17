#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int* memoireAllouee = NULL;

    memoireAllouee = malloc(sizeof(int)); // Allocation de la mémoire
    if (memoireAllouee == NULL)
    {
        exit(0); //arret du programme si pas d'allocation possible
    }

    // Utilisation de la mémoire
    printf("Quel age avez-vous ? ");
    scanf("%d", memoireAllouee); // le scanf stocke dans la memoire alloué
    printf("Vous avez %d ans\n", *memoireAllouee); // et la il la retrouve

    free(memoireAllouee); // Libération de mémoire

    return 0;
}