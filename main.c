#include "lex.c"
#include "parser.h"

void main()
{
    FILE* file , *out;
    char car_cour;
    const char programme[100] = {};
    printf("Veuillez entrer le programme a analyser:\n");
    scanf("%s",programme);
    printf("\n");
    if((file = fopen(programme,"r")) == NULL)
        printf("Fichier introuvable !");
    car_cour = Lire_car(file);
    do
    {
        car_cour = ignorer_separateur(car_cour , file);
        car_cour = ignorer_comentaire(car_cour , file);
        if(isalpha(car_cour))
        {
            car_cour = Lire_mots(car_cour,file);
        }
        else
        if(isdigit(car_cour))
            car_cour = Lire_nombre(car_cour,file);
        else
            car_cour = Lire_special(car_cour,file);

        if((out = fopen("C:\\Users\\HP\\Desktop\\analyseur_lexical\\tokens.txt","a")) == NULL)
        {
            printf("Fichier introuvable !");
            exit(EXIT_FAILURE);
        }
        else
        {
            fputs(token_cour.code,out);
            fputs("_TOKEN",out);
            fputs("\n",out);
            fclose(out);
        }
    }while(car_cour != EOF);
    fclose(file);
    printf("\n\n");
    printf("***********************************************\n");
    printf("*************  FIN ANALYSEUR LEXICAL  *********\n");
    printf("***********************************************");
    
}