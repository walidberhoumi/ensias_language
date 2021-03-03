#ifndef COMPILA_LEX_H
#define COMPILA_LEX_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAXDIGIT 11
#define MAXCHAR 20
#define MAXID 20
#define NBRKEYWORDS 47
#define NBRSPECIALTOKENS 42
#define len 20
#define TRUE 1
#define FALSE 0

const char* keyword[] = {"CHAR","SHORT","INT","LONG","FLOAT","DOUBLE","UNSIGNED","VOID","TRUE","FALSE","ENUM","UNION","STRING","STATIC","MALLOC","REALLOC","CALLOC","IF","ELSE","FOR","FOREACH","LOOP","BREAK","CONTINUE","GOTO","WHILE","DO","SWITCH","CASE","BOOL","FILE","CONST","VOLATILE","REGISTER","ARRAY","BYTE","RECORD","RETURN","START","END","EOF","READ","WRITE","WRITELN","OPEN","CLOSE","ECHO"};
const char* spec_list[] = {"PV","PT","PLUS","MOINS","MULT","DIV","VIR","MOD","INC","DEC","ETBIT","OUBIT","TOGGLE","NOTBIT","DECG","DECD","INF","INFEG","EG","DIFF","SUPEG","SUP","ETLOG","OULOG","DIFF","ACCESTRU","AFF","AFFMOINS","AFFPLUS","AFFMULT","AFFDIV","AFFMOD","AFFET","AFFTOG","FINCOM","DEBCOM","ACO","ACF","PO","PF","GUI"};
const char* spec_sym[] = {";", ".", "+", "-", "*", "/", ",", "%", "++", "--", "&", "|", "^", "~", "<<", ">>", "<", "<=", "==", "!", ">=", ">", "&&", "||", "!", "->", "<-", "-=", "+=", "*=", "/=", "%=", "&=", "^=", "?", "$", "{", "}", "(", ")","\""};

typedef struct Token{

    char name[len];
    char code[len];

}Token;

Token token_cour;

char Lire_car();

char ignorer_separateur(char , FILE* );

char ignorer_comentaire(char, FILE*);

void messageErreur();

char Lire_mots( char , FILE* );

char Lire_nombre( char , FILE* );

char Lire_special( char , FILE* );

char Lire_text(char,FILE* );

#endif //COMPILA_LEX_H
