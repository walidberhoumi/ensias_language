#include "lex.h"

char Lire_car(FILE* fichier)
{
    return fgetc(fichier);
}

/*--------ignorer separateurs------------*/
char ignorer_separateur(char car, FILE* target)
{
    while(car == ' ' || car == '\n' || car == '\t'|| car == '\r')
    {
        car = Lire_car(target);
    }
    return car;
}

/*------------ignorer commentaire----------*/
char ignorer_comentaire(char car,FILE* target)
{
    if(car == '$')
    {
        while(car != '?' && car != EOF)
        {
            car = Lire_car(target);
            if(car == '?')
            {
                car = Lire_car(target);
                break;
            }
            if(car == EOF)
            {
                messageErreur("ERREUR COMMENTAIRE");
            }
        }
    }
    return car;
}

/*-------------message d'erreur------------*/
void messageErreur(char* msg)
{
    printf("\n\n%s\n",msg);
    printf("***********************************************\n");
    printf("*************  FIN COMPILATION  ***************\n");
    printf("***********************************************");
    exit(0);
}

/*---------------identifier les mots-----------------*/
char Lire_mots(char car_cour,FILE* target)
{
    char word[MAXCHAR];
    int i=0, j=0, cmp=0;
    word[0] = toupper(car_cour);
    while( ++i < MAXCHAR && (isalnum( word[i] = car_cour = toupper((unsigned char)Lire_car(target) )) || word[i] == '_' ));
    if( i == MAXCHAR )
        messageErreur("ERREUR IDENTIFICATEUR");
    word[i] = '\0';
    while( (cmp=strcmp(word , keyword[j++])) != 0 && j < NBRKEYWORDS);
    //mots_clés
    if(cmp == 0)
    {
        strcpy(token_cour.name, word);
        strcpy(token_cour.code, keyword[j-1]);
    }
        //Identificateur
    else
    {
        strcpy(token_cour.name, word);
        strcpy(token_cour.code, "ID");
    }
    return car_cour;
}

/*---------------identifier ,les nombres-----------------*/
char Lire_nombre(char car_cour,FILE* target)
{
    char num[MAXDIGIT];
    int i = 0;
    num[0] = car_cour;
    while( ++i < MAXDIGIT && isdigit(num[i] = car_cour = Lire_car(target)));
    if(i >= MAXDIGIT)
        messageErreur("ERREUR NOMBRE");
    num[i] = '\0';
    strcpy(token_cour.name, num);
    strcpy(token_cour.code, "NUM");
    return car_cour;
}

/*---------------identifier les caractères spéciaux-----------------*/
char Lire_special(char car_cour,FILE* target)
{
    int i=0,cmp=0;
    char sym[3];
    memset(sym,'\0',sizeof(sym));
    sym[0] = car_cour;
    if(sym[0] == '\"')
    {
        car_cour = Lire_text(car_cour,target);
    }
    else
    {
            sym[1] = car_cour = Lire_car(target);
            if((sym[1] != '=') && (sym[1] != '<')  && (sym[1] != '>')  && (sym[1] != '&')  && (sym[1] != '|')  && (sym[1] != '+')  && (sym[1] != '-'))
            sym[1] = '\0';
            else
            car_cour = Lire_car(target);
        while( (cmp = strcmp(sym, spec_sym[i++]) != 0) && i < NBRSPECIALTOKENS);
        if(cmp !=0)
        {
            printf("%s",sym);
            messageErreur("ERREUR TOKEN");
        }
        else
        {
            strcpy(token_cour.name,sym);
            strcpy(token_cour.code, spec_list[i-1]);
        }
    }

   
    return car_cour;
}

/*------------text Writeln----------*/
char Lire_text(char car,FILE* target) 
{
        car = Lire_car(target);
        while (car != '\"' && car != EOF)
         {
            car = Lire_car(target);
            if (car == '\"') {
                strcpy(token_cour.code,"String");
                car = Lire_car(target);
                break;
            }
            if (car == EOF) {
                messageErreur("ERREUR TEXT : Function Write");
            }
        }
}