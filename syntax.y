%{
#include <stdio.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"
#include <string.h>
#include <stdlib.h>

int nErrorSem = 0;
int nErrorSint =0;
Lista tablaSimb;
ListaC listaCodigo;
Tipo tipoActual;            /* Variable global para el tipo actual del simbolo */ 
int contCadenas=0;
int nEtiqueta = 0;
int registrosLibres[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
void yyerror();
extern int yylex();
extern int yylineno;
extern char * yytext;
int contieneTabla(char *str);
void insertaEntrada(char *str, Tipo t);
int esConstante(char *str);
Operacion creaInst(char *op, char *res, char *arg1, char *arg2);
char *registroLibre();
void liberaReg(char *reg);
char *concatenaStr(char *a, char *b);
char *enteroACaracter(int numero);
%}

%code requires{
#include "listaCodigo.h"
}

/* definicion de tipo de dato */
%union{
    ListaC codigo; 
    char *str;
}


/* Declaracion de simbolos terminales y no terminales */
%type <codigo>  program declarations identifier_list asig statements_list statement print_list print_item read_list expression for_statement
%token <str> STRLITERAL ID INTLITERAL
%token VOID VAR CONST IF ELSE WHILE READ PRINT CLOSEBRA OPENBRA DO FOR BPLUS BMINUS
%token LPAREN RPAREN SEMICOLON COMMA ASSIGNOP PLUSOP MINUSOP MULOP DIVOP

/* Correcion de ambiguedad y precedencia de operadores */
%left MINUSOP PLUSOP
%left MULOP DIVOP
%left UMINUS
%expect 1           /* Elimina el warning del conflicto -> preguntar al profesor */
%%
program :                       {tablaSimb = creaLS();} VOID ID LPAREN RPAREN OPENBRA declarations statements_list CLOSEBRA {   
                                    
                                    $$ = $7;
                                    concatenaLC($7, $8);
                                    liberaLC($8);

                                    //inserta inst fin de programa
                                    Operacion inst = creaInst("li", "$v0", "10", NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC($$, finalLC($$), inst);

                                    //Guarda la lista para que la gestione main
                                    listaCodigo = $$;
                                }
                                ;

declarations :                  declarations VAR {tipoActual = VARIABLE;} identifier_list SEMICOLON  {
                                    $$ = $1;
                                    concatenaLC($1, $4);
                                    liberaLC($4);
                                }
                                | declarations CONST {tipoActual = CONSTANTE;} identifier_list SEMICOLON {
                                    $$ = $1;
                                    concatenaLC($1, $4);
                                    liberaLC($4);
                                }
                                | declarations VAR error SEMICOLON {$$ = creaLC();}                        /* Errores sintacticos del tipo: var "vacio" ; */
                                | declarations CONST error SEMICOLON {$$ = creaLC();}          
                                | /* lambda */ {$$ = creaLC();}
                                ;

identifier_list :                asig {$$ = $1;}
                                | identifier_list COMMA asig {
                                    $$ = $1;
                                    concatenaLC($$, $3);
                                    liberaLC($3);
                                }
                                ;

asig :                          ID {
                                    if(!contieneTabla($1))
                                        insertaEntrada($1, tipoActual);
                                    else{
                                        printf("Error linea %d: Variable <%s> ya declarada.\n", yylineno, $1);
                                        nErrorSem++;
                                    }

                                    $$ = creaLC();
                                }
                                | ID  ASSIGNOP expression {
                                    if(!contieneTabla($1))
                                        insertaEntrada($1, tipoActual);
                                    else{
                                        printf("Error linea %d: Variable <%s> ya declarada.\n", yylineno, $1);
                                        nErrorSem++;
                                    }

                                    $$ = $3;
                                    Operacion inst = creaInst("sw", recuperaResLC($3), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    liberaReg(inst.res);
                                    //imprimirCodigo($$);
                                }
                                ;

statements_list :               statements_list statement {
                                    $$ = creaLC(); 
                                    concatenaLC($$, $1); 
                                    concatenaLC($$, $2);
                                    liberaLC($1);
                                    liberaLC($2);
                                }
                                | /* lambda */ { $$ = creaLC();}
                                ;

statement :                     ID ASSIGNOP expression SEMICOLON {
                                    if(!contieneTabla($1)){
                                        printf("Error linea %d: Error semantico <%s> no declarado.\n", yylineno, $1);
                                        nErrorSem++;
                                    }else if(esConstante($1)){
                                        printf("Error linea %d: Error semantico, asignacion a constante <%s>\n", yylineno, $1);
                                        nErrorSem++;
                                    }
                                    $$ = $3;
                                    Operacion inst = creaInst("sw", recuperaResLC($3), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    liberaReg(inst.res);
                                    //imprimirCodigo($$);
                                }
                                | OPENBRA statements_list CLOSEBRA { 
                                    $$ = $2;
                                }
                                | IF LPAREN expression RPAREN statement ELSE statement {
                                    
                                    $$ = $3;
                                    nEtiqueta++;    //else
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));
                                    nEtiqueta++;    //finif
                                    char *etiq2 = concatenaStr("$l", enteroACaracter(nEtiqueta));
                                    
                                    Operacion inst = creaInst("beqz", recuperaResLC($3), etiq1, NULL); //no cumple if y salta a else
                                    liberaReg(recuperaResLC($3));
                                    insertaLC($$, finalLC($$), inst);
                                    concatenaLC($$, $5);                        

                                    inst = creaInst("b", etiq2, NULL, NULL);    //Cumple if y salta a fin-if
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst(etiq1, NULL, NULL, NULL); //etiq: else
                                    insertaLC($$, finalLC($$), inst);
                                    concatenaLC($$, $7);

                                    inst = creaInst(etiq2, NULL, NULL, NULL); //etiq: finif
                                    insertaLC($$, finalLC($$), inst);
                                    liberaLC($5);
                                    liberaLC($7);
                                }
                                | IF LPAREN expression RPAREN statement {
                                    $$ = $3;
                                    nEtiqueta++;
                                    char *etiq = concatenaStr("$l", enteroACaracter(nEtiqueta));
                                    Operacion inst = creaInst("beqz", recuperaResLC($3), etiq, NULL); //No cumple if y salta finif
                                    insertaLC($$, finalLC($$), inst);
                                    concatenaLC($$, $5);
                                    inst = creaInst(etiq, NULL, NULL, NULL);                          //finif
                                    insertaLC($$, finalLC($$), inst);

                                    liberaReg(recuperaResLC($3));
                                    liberaLC($5);
                                }
                                | WHILE LPAREN expression RPAREN statement {
                                    nEtiqueta++;
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq1: inicio while
                                    nEtiqueta++;    
                                    char *etiq2 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq2: fin While

                                    Operacion inst = creaInst(etiq1, NULL, NULL, NULL);                 //etiq: inicio while
                                    // printf("weona\n");
                                    insertaLC($3, inicioLC($3), inst);                                  
                                    $$ = $3;                                                            //expression
                                    
                                    inst = creaInst("beqz", recuperaResLC($3), etiq2, NULL);            // Expresion == 0, finwhile
                                    insertaLC($$, finalLC($$), inst);                                   //statement
                                    concatenaLC($$, $5);                                                
                                    inst = creaInst("b", etiq1, NULL, NULL);                            //salta a inicio
                                    insertaLC($$, finalLC($$), inst);

                                    inst = creaInst(etiq2, NULL, NULL, NULL);                           //etiq: fin-while
                                    insertaLC($$, finalLC($$), inst);
                                                                                                        //otros statement
                                    liberaReg(recuperaResLC($3));
                                    liberaLC($5);
                                }
                                | DO  statement  WHILE LPAREN expression RPAREN SEMICOLON{
                                    nEtiqueta++;
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq1: do

                                    Operacion inst = creaInst(etiq1, NULL, NULL, NULL);                 //do
                                    insertaLC($2, inicioLC($2), inst);                                  
                                    $$ = $2;                                                            //statement

                                    concatenaLC($$, $5);                                                //expression
                                    inst = creaInst("bnez", recuperaResLC($5), etiq1, NULL);            //Expresion != 0, vuelve al do
                                    insertaLC($$, finalLC($$), inst);

                                    liberaReg(recuperaResLC($5));
                                    liberaLC($5);
                                }
                                | FOR LPAREN for_statement SEMICOLON expression SEMICOLON for_statement RPAREN 
                                    statement // ver si agregamos que en forstatement acepte sentencias del tipo: "a++"
                                {
                                    nEtiqueta++;
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq1: inicio for
                                    nEtiqueta++;    
                                    char *etiq2 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq2: fin for
                                    

                                    Operacion inst = creaInst(etiq1, NULL, NULL, NULL);                 //etiq: inicio FOR
                                    insertaLC($5, inicioLC($5), inst);                                  
                                    concatenaLC($3, $5);
                                    $$ = $3;                                                            //expression

                                    inst = creaInst("beqz", recuperaResLC($5), etiq2, NULL);            // Expresion == 0, finfor
                                    insertaLC($$, finalLC($$), inst);                                   //statement
                                    concatenaLC($$, $9); 
                                    concatenaLC($$, $7);
                                    inst = creaInst("b", etiq1, NULL, NULL);                            //salta a inicio
                                    insertaLC($$, finalLC($$), inst);

                                    inst = creaInst(etiq2, NULL, NULL, NULL);                           //etiq: fin-for
                                    insertaLC($$, finalLC($$), inst);
                                                                                                        //otros statement
                                    liberaReg(recuperaResLC($3));
                                    liberaLC($5);
                                    liberaLC($7);
                                    liberaLC($9);
                                }
                                | PRINT print_list SEMICOLON {
                                    $$ = $2;
                                }
                                | READ read_list SEMICOLON {
                                    $$ = $2;
                                }
                                | ID BMINUS %prec BMINUS SEMICOLON{
                                    $$ = creaLC();
                                    Operacion inst = creaInst("lw", registroLibre(), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("addiu", inst.res, inst.res, "-1");
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("sw", inst.res, concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    liberaReg(inst.res);
                                }
                                | ID BPLUS %prec BPLUS SEMICOLON{
                                    $$ = creaLC();
                                    Operacion inst = creaInst("lw", registroLibre(), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("addiu", inst.res, inst.res, "1");
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("sw", inst.res, concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);

                                    liberaReg(inst.res);
                                }
                                | error SEMICOLON  { $$ = creaLC();}                     /* Punto de recuperacion: error en herederos print, read o expression*/
                                ; 
for_statement :                 ID ASSIGNOP expression{
                                    $$ = $3;
                                    Operacion inst = creaInst("sw", recuperaResLC($3), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    liberaReg(inst.res);
                                }
                                ;

print_list :                    print_item { 
                                    $$ = $1;
                                }
                                | print_list COMMA print_item {
                                    $$ = $1;
                                    concatenaLC($$, $3);
                                    liberaLC($3);
                                }
                                ;

print_item :                    expression {
                                    $$ = $1;
                                    Operacion inst = creaInst("move", "$a0", recuperaResLC($1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("li", "$v0", "1", NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC($$, finalLC($$), inst);

                                    liberaReg(recuperaResLC($1));
                                }
                                | STRLITERAL {      /* Es necesario comprobar si una cadena esta ya en la seccion de datos? */
                                    if(!contieneTabla($1)){ 
                                        insertaEntrada($1, CADENA);
                                        contCadenas++;
                                    }

                                    PosicionLista pos = buscaLS(tablaSimb, $1);    //Buscar idCadena, no todas las veces se introduce nueva cadena. contCadenas no actualizado 
                                    Simbolo tmp = recuperaLS(tablaSimb, pos);
                                    int id = tmp.valor;
                                    char *idStr = concatenaStr("$str", enteroACaracter(id));

                                    $$ = creaLC();
                                    Operacion inst = creaInst("la", "$a0", idStr, NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("li", "$v0", "4", NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC($$, finalLC($$), inst);
                                }
                                ;

read_list :                     ID{
                                    if(!contieneTabla($1)){
                                        printf("Error linea %d: Error semantico <%s> no declarado.\n", yylineno, $1);
                                        nErrorSem++;
                                    }else if(esConstante($1)){
                                        printf("Error linea %d: Error semantico, asignacion a constante <%s>\n", yylineno, $1);
                                        nErrorSem++;
                                    }
                                    $$ = creaLC();
                                    char *id = concatenaStr("_", $1);

                                    Operacion inst = creaInst("li", "$v0", "5", NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("sw", "$v0", id, NULL);
                                    insertaLC($$, finalLC($$), inst);

                                }
                                | read_list COMMA ID {
                                    if(!contieneTabla($3)){
                                        printf("Error linea %d: Error semantico <%s> no declarado.\n", yylineno, $3);
                                    }else if(esConstante($3)){
                                        printf("Error linea %d: Error semantico, asignacion a constante <%s>\n", yylineno, $3);
                                    }
                                    $$ = $1;
                                    char *id = concatenaStr("_", $3);

                                    Operacion inst = creaInst("li", "$v0", "5", NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("sw", "$v0", id, NULL);
                                    insertaLC($$, finalLC($$), inst);
                                }
                                ;

expression :                    expression PLUSOP expression            { /*$$=$1+$3*/ 
                                    $$ = $1;
                                    concatenaLC($$, $3);
                                    Operacion inst = creaInst("add", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3));
                                    insertaLC($$, finalLC($$), inst);
                                    liberaLC($3);
                                    liberaReg(inst.arg2);
                                }
                                | expression MINUSOP expression         { /*$$=$1-$3*/
                                    $$ = $1;
                                    concatenaLC($$, $3);
                                    Operacion inst = creaInst("sub", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3));
                                    insertaLC($$, finalLC($$), inst);
                                    liberaLC($3);
                                    liberaReg(inst.arg2);
                                }
                                | expression MULOP expression           { /*$$=$1*$3*/ 
                                    $$ = $1;
                                    concatenaLC($$, $3);
                                    Operacion inst = creaInst("mul", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3));
                                    insertaLC($$, finalLC($$), inst);
                                    liberaLC($3);
                                    liberaReg(inst.arg2);
                                }
                                | expression DIVOP expression           { /*$$=$1/$3*/
                                    $$ = $1;
                                    concatenaLC($$, $3);
                                    Operacion inst = creaInst("div", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3));
                                    insertaLC($$, finalLC($$), inst);
                                    liberaLC($3);
                                    liberaReg(inst.arg2);
                                }
                                | MINUSOP expression %prec UMINUS       { /*$$=-$2*/ 
                                    $$ = $2;
                                    char *res = recuperaResLC($2);
                                    Operacion inst = creaInst("neg", res, res, NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    guardaResLC($$, inst.res);
                                }
                                | LPAREN expression RPAREN              { $$=$2; }
                                | ID {
                                    if(!contieneTabla($1)){
                                        printf("Error linea %d: Error semantico, <%s> no declarado.\n", yylineno, $1);
                                        nErrorSem++;
                                    }
                                    $$ = creaLC();
                                    Operacion inst = creaInst("lw", registroLibre(), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    guardaResLC($$, inst.res);
                                    
                                }
                                | ID BPLUS %prec BPLUS{
                                    $$ = creaLC();
                                    Operacion inst = creaInst("lw", registroLibre(), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("addiu", inst.res, inst.res, "1");
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("sw", inst.res, concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);

                                    guardaResLC($$, inst.res);
                                }
                                | ID BMINUS %prec BMINUS{
                                    $$ = creaLC();
                                    Operacion inst = creaInst("lw", registroLibre(), concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("addiu", inst.res, inst.res, "-1");
                                    insertaLC($$, finalLC($$), inst);
                                    inst = creaInst("sw", inst.res, concatenaStr("_", $1), NULL);
                                    insertaLC($$, finalLC($$), inst);

                                    guardaResLC($$, inst.res);
                                }
                                | INTLITERAL {
                                    $$ = creaLC();
                                    Operacion inst = creaInst("li", registroLibre(), $1, NULL);
                                    insertaLC($$, finalLC($$), inst);
                                    guardaResLC($$, inst.res);
                                }
                                ;
%%
void yyerror(){
    nErrorSint++;
    printf("Error sintactico en linea %d \n", yylineno);
}

int contieneTabla(char *str){
    /* printf("Buscando %s\n", str); */
    if(buscaLS(tablaSimb, str) != NULL)
        return 1;
    else 
        return 0;
}

void insertaEntrada(char *str, Tipo t){
    Simbolo s;
    s.nombre = str;
    s.tipo = t;
    if(t == CADENA)
        s.valor = contCadenas;                      /* Identificador de cadena */
    insertaFinalLS(tablaSimb, s);
}

int esConstante(char *str){
    PosicionLista pos = buscaLS(tablaSimb, str);
    if(pos != NULL){
        Simbolo aux = recuperaLS(tablaSimb, pos);
        if(aux.tipo == CONSTANTE)
            return 1;
    }
    return 0;
}

Operacion creaInst(char *op, char *res, char *arg1, char *arg2){
    Operacion inst;
    inst.op = op;
    inst.res = res;
    inst.arg1 = arg1;
    inst.arg2 = arg2;
    return inst;
}

char *registroLibre(){
    for(int i = 0; i<10; i++){
        if(registrosLibres[i] == 1){
            registrosLibres[i] = 0;            /*Marcamos como no libre */
            char *tmp = malloc(4 * sizeof(char));
            sprintf(tmp, "$t%d", i);
            return tmp;
        }
    }
    printf("ERROR. No hay registros disponibles.\n");
    exit(1);    //No se ha podido realizar la operacion
}

char *concatenaStr(char *a, char *b){
    int tam = strlen(a) + strlen(b);
    char * tmp = malloc( (tam + 1) * sizeof(char));
    strcat(strcpy(tmp, a), b);
    return tmp;
}

void liberaReg(char *reg){ /* $tx */
    int i = ((int) reg[2]) - ((int)'0');            /* conversion mediante  codigo ascii */ 
    registrosLibres[i] = 1;
}

char *enteroACaracter(int numero){
    char *aux = malloc(sizeof(char));
    sprintf(aux, "%d", numero);
    return aux;
}