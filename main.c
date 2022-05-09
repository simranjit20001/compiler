#include <stdio.h>
#include <stdlib.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"

extern int nErrorLex;
extern int nErrorSem;
extern int nErrorSint;
extern Lista tablaSimb;
extern ListaC listaCodigo;
extern char *yytext;
extern FILE *yyin;
extern int yyparse();
FILE *fich;


int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Uso correcto: %s fichero\n",argv[0]);
		exit(1);
	}
	FILE *fich = fopen(argv[1],"r");
	if (fich == 0) {
		printf("No se puede abrir %s\n",argv[1]);
		exit(1);
	}
	yyin = fich;
	yyparse();
	
	if(nErrorLex+nErrorSem+nErrorSint == 0){
		imprimeTabla(tablaSimb);
		imprimirCodigo(listaCodigo);
	}else{
		printf("\n----------------------------------------\n");
		if(nErrorLex)
			printf("Errores lexicos: %d\n", nErrorLex);
		if(nErrorSint)
			printf("Errores sintacticos: %d\n", nErrorSint);
		if(nErrorSem)
			printf("Errores semánticos: %d\n", nErrorSem);
	}
	fclose(fich);
}