#include "listaSimbolos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct PosicionListaRep {
  Simbolo dato;
  struct PosicionListaRep *sig;
};

struct ListaRep {
  PosicionLista cabecera;
  PosicionLista ultimo;
  int n;
};

typedef struct PosicionListaRep *NodoPtr;

Lista creaLS() {
  Lista nueva = malloc(sizeof(struct ListaRep));
  nueva->cabecera = malloc(sizeof(struct PosicionListaRep));
  nueva->cabecera->sig = NULL;
  nueva->ultimo = nueva->cabecera;
  nueva->n = 0;
  return nueva;
}

void liberaLS(Lista lista) {
  while (lista->cabecera != NULL) {
    NodoPtr borrar = lista->cabecera;
    lista->cabecera = borrar->sig;
    free(borrar);
  }
  free(lista);
}

void insertaLS(Lista lista, PosicionLista p, Simbolo s) {
  NodoPtr nuevo = malloc(sizeof(struct PosicionListaRep));
  nuevo->dato = s;
  nuevo->sig = p->sig;
  p->sig = nuevo;
  if (lista->ultimo == p) {
    lista->ultimo = nuevo;
  }
  (lista->n)++;
}

void insertaFinalLS(Lista lista, Simbolo s){
  NodoPtr nuevo = malloc(sizeof(struct PosicionListaRep));
  nuevo->dato = s;
  lista->ultimo->sig = nuevo;
  lista->ultimo = nuevo;
  (lista->n)++;
}


void suprimeLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  NodoPtr borrar = p->sig;
  p->sig = borrar->sig;
  if (lista->ultimo == borrar) {
    lista->ultimo = p;
  }
  free(borrar);
  (lista->n)--;
}

Simbolo recuperaLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig->dato;
}

PosicionLista buscaLS(Lista lista, char *nombre) {
  NodoPtr aux = lista->cabecera;
  while (aux->sig != NULL && strcmp(aux->sig->dato.nombre,nombre) != 0) {
    aux = aux->sig;
  }
  if(aux->sig != NULL && strcmp(aux->sig->dato.nombre,nombre) == 0)
    return aux;
  else return NULL;                                                   //retorna nulo, para busqueda facilmente
}

void asignaLS(Lista lista, PosicionLista p, Simbolo s) {
  assert(p != lista->ultimo);
  p->sig->dato = s;
}

int longitudLS(Lista lista) {
  return lista->n;
}

PosicionLista inicioLS(Lista lista) {
  return lista->cabecera;
}

PosicionLista finalLS(Lista lista) {
  return lista->ultimo;
}

PosicionLista siguienteLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig;
}

/*Usa las funciones abstractas/genericas, se podria definir en listaSimbolos.c para realizar directamente un recorrido con punteros, 
pero creo que así queda mas entendible y en el mismo archivo que el analizador lexico*/
void imprimeTabla(Lista tablaSimb){
    printf("\t.data\n");
    /* Imprime las cadenas */
    PosicionLista aux = inicioLS(tablaSimb);    /* Cabecera */
    while(aux != finalLS(tablaSimb)) {
        Simbolo simb = recuperaLS(tablaSimb, aux);
        if(simb.tipo == CADENA){
            printf("$str%d:\n", simb.valor);
            printf("\t.asciiz %s\n", simb.nombre);
        }
        aux = siguienteLS(tablaSimb, aux);
    }

    /* Imprime las variables */
    aux = inicioLS(tablaSimb);                  /* Cabecera */
    while(aux != finalLS(tablaSimb)) {
        Simbolo simb = recuperaLS(tablaSimb, aux);
        if(simb.tipo != CADENA){
            printf("_%s:\n", simb.nombre);
            printf("\t.word 0\n");
        }
        aux = siguienteLS(tablaSimb, aux);
    }
}