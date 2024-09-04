#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choix = 0;
    struct Contact
    {
        char nom[50];
        int tel;
        char email[50];
    };
    struct Contact c1;
    int size = 0;

    while (choix != 7)
    {
        printf("------------------- Systeme de Gestion de Contacts--------------------- \n \
        1: Ajouter un Contact \n \
        2: Modifier un Contact \n  \
        3: Supprimer un Contact \n \
        4: Afficher Tous les Contacts \n \
        5: Rechercher un Contact \n  \
        6: Quitter \n ");

        printf("pleas entrer votre choix :\t\n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("entre le Nom :");
            scanf("%s", c1.nom);
            printf("entre le  Numéro de téléphone :");
            scanf("%d", &c1.tel);
            printf("entre le Email :");
            scanf("%s", c1.email);

            printf("ajoute Contact avec Success \n");
            size++;
            break;
        default:
            printf("choix invalide \n");
            break;
        }
    }

    return 0;
}