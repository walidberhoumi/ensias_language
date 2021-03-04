#include "lex.h"
#include "lex.c"
#include "parser.c"
#include "parser.h"
int main(int argc, char **argv)
{
//     FILE* file , *out;
//     char car_cour;
//     const char programme[100] = {"C:\\Users\\HP\\Desktop\\compila\\p.cc"};
// //  printf("Veuillez entrer le programme a analyser:\n");
// //  scanf("%s",programme);
// //  printf("\n");
//     out = fopen("C:\\Users\\HP\\Desktop\\compila\\tokens.txt","a");
//     file = fopen(programme,"r");
//     if(file == NULL || out == NULL)
//     {
//         printf("Fichier introuvable !");
//         exit(EXIT_FAILURE);
//     }
//     car_cour = Lire_car(file);
//     do
//     {
//         car_cour = ignorer_separateur(car_cour , file);
//         car_cour = ignorer_comentaire(car_cour , file);
//         if(car_cour == EOF)
//         {
//             fclose(out);
//             fclose(file);
//             break;
//         }
//         if(isalpha(car_cour))
//         {
//             car_cour = Lire_mots(car_cour,file);
//         }
//         else if(isdigit(car_cour))
//             car_cour = Lire_nombre(car_cour,file);
//         else
//             car_cour = Lire_special(car_cour,file);

//         fputs(token_cour.code,out);
//         fputs("_TOKEN",out);
//         fputs("\n",out);
//     }while(car_cour != EOF);

//     printf("\n\n");
//     printf("***********************************************\n");
//     printf("*************  FIN ANALYSEUR LEXICAL  *********\n");
//     printf("***********************************************\n");


    FILE* in = fopen("C:\\Users\\HP\\Desktop\\compila\\tokens.txt","r");
    analyzer(in);
    if(syntax==1)
       printf("****compilation syntax succeed********** !!!\n");
    else
       printf("******** Compilation syntax error !!!************\n ");
}
