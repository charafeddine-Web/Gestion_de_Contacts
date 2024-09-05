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



char Ajouter()
{
    char ts[50];
    printf("entre le Nom :");
    scanf("%s",ts);
    for(int i=0; i <size; i++){
        if(strcmp(ts,c1[i].nom)==0){
            printf("le nom exsits !! \n entrer autre nom \t");
            scanf("%s",ts);
            i=0;
        }
    }
    strcpy(c1[size].nom,ts);
    printf("entre le  Numéro de téléphone :");
    scanf("%s", c1[size].tel);
    printf("entre le Email :");
    scanf("%s", c1[size].email);
    printf("ajoute Contact avec Success \n");
    size++;


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

void Modifier(){

printf("entrer une nom :");
    scanf("%s",Nnom);
for(int i=0 ;i<size;i++){

    if(strcmp(c1[i].nom,Nnom)==0){
         printf("entrer nouveu TELL :");
         scanf("%s",Ntell);
         printf("entrer nouveu EMAIL :" );
         scanf("%s",Nemail);

         strcpy(c1[i].tel,Ntell);
         strcpy(c1[i].email,Nemail);
    }
}

}
 void Rechercher(){
     printf("pleas entrer une nom :");
     scanf("%s",Nnom);
     if(size==0){
        printf("aucun contact !!");
     }
     for(int j=0;j<size;j++){
            if(strcmp(c1[j].nom,Nnom)==0){
                printf("le nom est :%s\n", c1[j].nom);
                printf("le tel est :%s\n", c1[j].tel);
                printf("le email est :%s\n", c1[j].email);
            }
     }
}
void Supprimer(){
     printf("pleas entrer une nom :");
     scanf("%s",Nnom);
     for(int i=0 ;i<size;i++){
        if(strcmp(c1[i].nom,Nnom)==0){
             strcpy(c1[i].nom,c1[i+1].nom);
             strcpy(c1[i].tel,c1[i+1].tel);
             strcpy(c1[i].email,c1[i+1].email);
        }
        size--;
}
 }

int main()
{
    int choix =0;
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




        switch (choix)
        {
        case 1:
           Ajouter();
            break;

        case 2:
            Modifier();
            break;
        case 3:
             Supprimer();
            break;
        case 4:
            Afficher();
            break;

        case 5:
             Rechercher();
            break;


        default:
            printf("choix invalide \n");
             break;
        }
        system("pause");
        system("cls");
    }while(choix =! 0);

    return 0;
}
