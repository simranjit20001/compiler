%{
#include "syntax.tab.h"
#include "listaSimbolos.h"
Lista tablaSimbolos;
int nErrorLex = 0;
int inicioCom = 0;
%}
%option yylineno
%x comment 

digito              		[0-9]
letra               		[a-zA-Z]
entero              		{digito}+
panico 	     				[^a-zA-Z0-9 \r\n\t/_(){},;="+*-]+
%%
[ \r\n\t]+                  				;
"//"(.*)[\n]                				;
\"(\\\"|[^\"\n])*\"							{	
												yylval.str = strdup(yytext);
												return STRLITERAL;
											}
\"(\\\"|[^\"\n])*							{
												nErrorLex++;
												printf("ERROR lexico. Linea %d: Texto entrecomillado sin cerrar: %s \n", yylineno, yytext);
											}

"/*"										{
												inicioCom = yylineno;
												BEGIN(comment);
											}

<comment>[*]+"/"							BEGIN(INITIAL);
<comment>([^*]|[*]+[^*/])*					;
<comment><<EOF>>							{
												nErrorLex++;
												printf("ERROR lexico. Comentario sin cerrar, iniciado en linea: %d\n", inicioCom);
												return 0;
											}
void					    				return VOID;
var					    					return VAR;
const					    				return CONST;
if					    					return IF;
else					    				return ELSE;
do 											return DO;
while					    				return WHILE;
for											return FOR;
print					    				return PRINT;
read					    				return READ;
";"											return SEMICOLON;
","											return COMMA;
"+"											return PLUSOP;
"*"											return MULOP;
"/"											return DIVOP;
"-"											return MINUSOP;
"++"										return BPLUS;
"="                         				return ASSIGNOP;
"("                         				return LPAREN;		
")"			                				return RPAREN;
"{"					    					return OPENBRA;
"}"					    					return CLOSEBRA;
({letra}|_)({letra}|{digito}|_)*            {	if(yyleng > 16){ 
													nErrorLex++;
													printf("ERROR lexico. Linea %d: Se ha excedido la longitud del identificador < %s >\n", yylineno, yytext);
												}else {
													yylval.str = strdup(yytext);
													return ID;
												}
											}
{entero}                                    {	
												long int tmp = atol(yytext);
												if(tmp < 2147483648){
													yylval.str = strdup(yytext);
													return INTLITERAL;
												}else{ 
													nErrorLex++;
													printf("ERROR lexico. Linea %d: Excedido tamaño maximo de entero: %s\n", yylineno, yytext);
													//TODO ver si hay que devolver algo o abortar el programa
												}
											}
{panico}                             		{
												nErrorLex++;
												printf("ERROR lexico. Linea %d: Caracteres no validos: %s \n", yylineno, yytext);
											}
%%
