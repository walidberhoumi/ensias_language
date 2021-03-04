#ifndef COMPILA_LEX_H
#define COMPILA_LEX_H 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>


#define MAXDIGIT 11
#define MAXCHAR 20
#define NBRKEYWORDS 47
#define NBRSPECIALTOKENS 42
#define len 20




typedef struct Token{

    char name[len];
    char code[len];

}Token;

Token token_cour ;



char Lire_car();

char ignorer_separateur(char , FILE* );

char ignorer_comentaire(char , FILE* );

void messageErreur();

char Lire_mots( char , FILE* );

char Lire_nombre( char , FILE* );

char Lire_special( char , FILE*);

char Lire_text(char ,FILE* );

#endif
