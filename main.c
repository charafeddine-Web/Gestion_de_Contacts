#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nom[50];
    char tel[50];
    char email[50];
} Contact;
Contact c1[500];

int size = 0;
char Nnom[50];
char Ntell[50];
char Nemail[50];

void Ajouter()
{
    char ts[100];
    int t = 0;
    printf("entre le Nom :");
    scanf("%s", ts);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(c1[i].nom, ts) == 0)
        {
            printf("le nom exsits !! \n");
            t = 1;
            break;
        }
    }
    if (t == 0)
    {
        strcpy(c1[size].nom, ts);
        printf("entre le  Numero de telephone :");
        scanf("%s", c1[size].tel);
        printf("entre le Email :");
        scanf("%s", c1[size].email);
        printf("ajoute Contact avec Success \n");
        size++;
    }
}

void Afficher()
{
    if (size == 0)
    {
        printf("contact vide\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("le nom est :%s\n", c1[i].nom);
        printf("le tel est :%s\n", c1[i].tel);
        printf("le email est :%s\n", c1[i].email);
    }
}

void Modifier()
{

    printf("entrer une nom :");
    scanf("%s", Nnom);
    for (int i = 0; i < size; i++)
    {

        if (strcmp(c1[i].nom, Nnom) == 0)
        {
            int cofirmation = 0;
            printf("si vous avez Modifie le contact tapez 1 sinon tapez 2 :");
            scanf("%d", &cofirmation);
            if (cofirmation == 1)
            {
                printf("entrer nouveu NOM :");
                scanf("%s", Nnom);
                printf("entrer nouveu TELL :");
                scanf("%s", Ntell);
                printf("entrer nouveu EMAIL :");
                scanf("%s", Nemail);
                strcpy(c1[i].tel, Ntell);
                strcpy(c1[i].email, Nemail);
            }else{
                printf("le contact n'est pas modifie\n");
            }
        }
    }
}
void Rechercher()
{
    int nbrchoix = 0;
    printf("tapez 1 si vous avez effectuer une recherche par nom ,sinon tapez 2 par email ?\n");
    scanf("%d", &nbrchoix);
    if (nbrchoix == 1)
    {
        printf("pleas entrer une nom :");
        scanf("%s", Nnom);
    }
    else
    {
        printf("pleas entrer une email :");
        scanf("%s", Nemail);
    }

    if (size == 0)
    {
        printf("aucun contact !!");
    }
    for (int j = 0; j < size; j++)
    {
        if (strcmp(c1[j].nom, Nnom) == 0 || strcmp(c1[j].email, Nemail) == 0)
        {
            printf("le nom est :%s\n", c1[j].nom);
            printf("le tel est :%s\n", c1[j].tel);
            printf("le email est :%s\n", c1[j].email);
        }
    }
}
void Supprimer()
{
    printf("pleas entrer une nom :");
    scanf("%s", Nnom);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(c1[i].nom, Nnom) == 0)
        {
            for (int j = i; j < size; j++)
            {
                c1[i] = c1[i + 1];
            }
            size--;
        }
    }
}

int main()
{
    int choix = 0;
    // int testAjoute=0;
    do
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
        int choix2 = 0;
        int testSupprime = 0;

        switch (choix)
        {
        case 1:
            printf("si vous avez un seul contact tapez 1 sinon tapez 2 :");
            scanf("%d", &choix2);
            if (choix2 == 1)
            {
                Ajouter();
            }
            else
            {
                int number;
                printf("entre le number de contact a ajouter :");
                scanf("%d", &number);
                for (int i = 0; i < number; i++)
                {
                    Ajouter();
                }
            }
            break;

        case 2:
            Modifier();
            break;
        case 3:
            int nbrsupprime;
            printf("si vous avez supprime un contact tapez 0 sinon tapez 1 :");
            scanf("%d", &testSupprime);
            if (testSupprime == 0)
            {
                int confirme;
                printf("Etes-vous sur , si oui tapez 1 sinon tapez 2 :");
                scanf("%d", &confirme);
                if (confirme == 1)
                {
                    Supprimer();
                }
                else
                {
                    printf("vous avez annule la suppression");
                }
            }
            else
            {
                printf("entre le number de contact a supprimer :");
                scanf("%d", &nbrsupprime);
                for (int i = 0; i < nbrsupprime; i++)
                {
                    Supprimer();
                }
            }
            break;
        case 4:
            Afficher();
            break;

        case 5:
            Rechercher();
            break;
        case 6:
            return 0;
            break;

        default:
            printf("choix invalide \n");
            break;
        }
        system("pause");
        system("cls");
    } while (choix = !0);

    return 0;
}
