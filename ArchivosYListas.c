#include "ArchivosYListas.h"
TNodo *CrearNodo(char *nombre)
{
    TNodo *ptr = (TNodo *)malloc(sizeof(TNodo));

    if (ptr == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(1);
    }

    ptr->nombre = (char *)malloc(strlen(nombre) + 1);

    if (ptr->nombre == NULL)
    {
        printf("Error al reservar memoria para el nombre.\n");
        exit(1);
    }

    strcpy(ptr->nombre, nombre);
    ptr->ant = ptr->sig = NULL;

    return ptr;
}

void InsertaFinal(TListaD *lista, char *nombre)
{
    TNodo *nodo = CrearNodo(nombre);

    if (lista->fin == NULL)
    {
        lista->inicio = lista->fin = nodo;
    }
    else
    {
        nodo->ant = lista->fin;
        lista->fin->sig = nodo;
        lista->fin = nodo;
    }
}

void LeerArchivo(TListaD *lista, char *nArchivo)
{
    FILE *archivo = fopen(nArchivo, "r");
    char nombre[100];

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fgets(nombre, sizeof(nombre), archivo))
    {
        nombre[strcspn(nombre, "\n")] = 0;
        InsertaFinal(lista, nombre);
    }

    fclose(archivo);
}

void Imprime(TListaD *lista)
{
    TNodo *aux = lista->inicio;

    while (aux != NULL)
    {
        printf("%s\n", aux->nombre);
        aux = aux->sig;
    }
    printf("\n");
}

int main()
{
    TListaD lista;
    lista.inicio = lista.fin = NULL;

    LeerArchivo(&lista, "gramatica2.txt");

    printf("Lista:\n");
    Imprime(&lista);
}
