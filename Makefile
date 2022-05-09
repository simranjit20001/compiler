miniC: lex.yy.c main.c syntax.tab.c listaCodigo.c listaSimbolos.c
	gcc lex.yy.c main.c syntax.tab.c listaCodigo.c listaSimbolos.c -lfl -o miniC

syntax.tab.h syntax.tab.c: syntax.y
	bison -d syntax.y

lex.yy.c: lexico.l
	flex lexico.l
clean: 
	rm -rf lex.yy.c syntax.tab.c syntax.tab.h miniC Miprog.s
run:
	./miniC prueba_sintactico2.mc > Miprog.s