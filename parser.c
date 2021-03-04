#include "parser.h"
void error(enum ERROR error)
{
    switch( error )
    {
        case 0: printf("ERROR------>CHAR\n"); break;
        case 1: printf("ERROR------>SHORT\n"); break;
        case 2: printf("ERROR------>INT\n"); break;
        case 3: printf("ERROR------>LONG\n"); break;
        case 4: printf("ERROR------>FLOAT\n"); break;
        case 5: printf("ERROR------>DOUBLE\n"); break;
        case 6: printf("ERROR------>UNSIGNED\n"); break;
        case 7: printf("ERROR------>VOID\n"); break;
        case 8: printf("ERROR------>TRUE\n"); break;
        case 9: printf("ERROR------>FALSE\n"); break;
        case 10: printf("ERROR------>ENUM\n"); break;
        case 11: printf("ERROR------>UNION\n"); break;
        case 12: printf("ERROR------>STRING\n"); break;
        case 13: printf("ERROR------>STATIC\n"); break;
        case 14: printf("ERROR------>MALLOC\n"); break;
        case 15: printf("ERROR------>REALLOC\n"); break;
        case 16: printf("ERROR------>CALLOC\n"); break;
        case 17: printf("ERROR------>IF\n"); break;
        case 18: printf("ERROR------>ELSE\n"); break;
        case 19: printf("ERROR------>FOR\n"); break;
        case 20: printf("ERROR------>FOREACH\n"); break;
        case 21: printf("ERROR------>LOOP\n"); break;
        case 22: printf("ERROR------>BREAK\n"); break;
        case 23: printf("ERROR------>CONTINUE\n"); break;
        case 24: printf("ERROR------>GOTO\n"); break;
        case 25: printf("ERROR------>WHILE\n"); break;
        case 26: printf("ERROR------>DO\n"); break;
        case 27: printf("ERROR------>SWITCH\n"); break;
        case 28: printf("ERROR------>CASE\n"); break;
        case 29: printf("ERROR------>BOOL\n"); break;
        case 30: printf("ERROR------>FILE\n"); break;
        case 31: printf("ERROR------>CONST\n"); break;
        case 32: printf("ERROR------>VOLATILE\n"); break;
        case 33: printf("ERROR------>REGISTER\n"); break;
        case 34: printf("ERROR------>ARRAY\n"); break;
        case 35: printf("ERROR------>BYTE\n"); break;
        case 36: printf("ERROR------>RECORD\n"); break;
        case 37: printf("ERROR------>RETURN\n"); break;
        case 38: printf("ERROR------>START\n"); break;
        case 39: printf("ERROR------>END\n"); break;
        case 40: printf("ERROR------>EOF\n"); break;
        case 41: printf("ERROR------>READ\n"); break;
        case 42: printf("ERROR------>WRITE\n"); break;
        case 43: printf("ERROR------>WRITELN\n"); break;
        case 44: printf("ERROR------>OPEN\n"); break;
        case 45: printf("ERROR------>CLOSE\n"); break;
        case 46: printf("ERROR------>ECHO\n"); break;
        case 47: printf("ERROR------>PV\n"); break;
        case 48: printf("ERROR------>PT\n"); break;
        case 49: printf("ERROR------>PLUS\n"); break;
        case 50: printf("ERROR------>MOINS\n"); break;
        case 51: printf("ERROR------>MULT\n"); break;
        case 52: printf("ERROR------>DIV\n"); break;
        case 53: printf("ERROR------>VIR\n"); break;
        case 54: printf("ERROR------>MOD\n"); break;
        case 55: printf("ERROR------>INC\n"); break;
        case 56: printf("ERROR------>DEC\n"); break;
        case 57: printf("ERROR------>ETBIT\n"); break;
        case 58: printf("ERROR------>OUBIT\n"); break;
        case 59: printf("ERROR------>TOGGLE\n"); break;
        case 60: printf("ERROR------>NOTBIT\n"); break;
        case 61: printf("ERROR------>DECG\n"); break;
        case 62: printf("ERROR------>DECD\n"); break;
        case 63: printf("ERROR------>INF\n"); break;
        case 64: printf("ERROR------>INFEG\n"); break;
        case 65: printf("ERROR------>EG\n"); break;
        case 66: printf("ERROR------>DIFF\n"); break;
        case 67: printf("ERROR------>SUPEG\n"); break;
        case 68: printf("ERROR------>SUP\n"); break;
        case 69: printf("ERROR------>ETLOG\n"); break;
        case 70: printf("ERROR------>OULOG\n"); break;
        case 71: printf("ERROR------>DIFF\n"); break;
        case 72: printf("ERROR------>ACCESTRU\n"); break;
        case 73: printf("ERROR------>AFF\n"); break;
        case 74: printf("ERROR------>AFFMOINS\n"); break;
        case 75: printf("ERROR------>AFFPLUS\n"); break;
        case 76: printf("ERROR------>AFFMULT\n"); break;
        case 77: printf("ERROR------>AFFDIV\n"); break;
        case 78: printf("ERROR------>AFFMOD\n"); break;
        case 79: printf("ERROR------>AFFET\n"); break;
        case 80: printf("ERROR------>AFFTOG\n"); break;
        case 81: printf("ERROR------>FINCOM\n"); break;
        case 82: printf("ERROR------>DEBCOM\n"); break;
        case 83: printf("ERROR------>ACO\n"); break;
        case 84: printf("ERROR------>ACF\n"); break;
        case 85: printf("ERROR------>PO\n"); break;
        case 86: printf("ERROR------>PF\n"); break;
        case 87: printf("ERROR------>GUI\n"); break;

    }
}


char* nextSymbol(FILE* file)
{
    if(file != NULL)
    {
        char* token = (char*) malloc(sizeof(char)*30);

        fgets(token,30,file);
        token[strlen(token)-1] = '\0';
        return token;
    }
    else
    {
        printf("opening file error\n");
        exit(0);
    }
}

void testSymbol( char* token , enum ERROR erro , FILE* file )
{
    char* tok = nextSymbol(file);
    if(!strcmp(tok,token))
    {
        syntax = 1;
    }
    else
    {
        syntax = 0;
        error(erro);
    }
}
void analyzer(FILE* file)
{
    testSymbol("START_TOKEN",ERROR_START,file);
}


