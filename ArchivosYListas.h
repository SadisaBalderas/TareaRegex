# indef ARCHIVOSYLISTAS_H
#define ARCHIVOSYLISTAS_H

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
  struct nodo *sig;
  struct nodo *ant;
  char dato[50];
} TNodo;

typedef struct {
  TNodo *inicio;
  TNodo *fin;
} TLista;

#endif
