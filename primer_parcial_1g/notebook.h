#include "marca.h"
#include "tipo.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
} eNotebook;

#endif // NOTEBOOK_H_INCLUDED


int menu();

int inicializarNotebooks(eNotebook notebooks[], int tam);

int harcodearNotebooks(eNotebook notebooks[], int tam, int cant, int* pId);

int buscarLibre(eNotebook notebooks[], int tam, int* pIndice);

int buscarNotebook(eNotebook notebooks[], int tam, int* pIndice, int id);

void mostrarNotabook(eNotebook unaNotebook, eMarca marcas[], int tam,  eTipo tipos[], int tamt);

int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt);

int ordenarNotebook(eNotebook notebooks[], int tam);

int validarEnteroRango(int valor, int minimo, int maximo);

int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, int* pId);

int bajaNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt);

int menuModificacion();

int modificarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt);
