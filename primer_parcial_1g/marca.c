#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
#include "notebook.h"

int cargarNombreMarca(eMarca marcas[], int tam, int idMarca, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(marcas != NULL && tam > 0)
    {
        todoOk = 1;
        for(int i = 0; i < tam; i ++)
        {
            if(marcas[i].id == idMarca)
            {
                strcpy(descripcion, marcas[i].descripcion);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
int mostrarMarca(eMarca marcas[], int tam, int clear)
{
    int todoOk = 0;
    if(marcas != NULL && tam > 0)
    {
        if(clear)
        {
            system("cls");
        }
        printf("========================\n");
        printf("   *** lista Marca ***  \n");
        printf("========================\n");
        printf("   id       Descripcion \n");
        printf("========================\n");
        for (int i = 0; i < tam; i++)
        {
             printf("  %d       %10s \n", marcas[i].id, marcas[i].descripcion);
        }
        printf("========================\n");
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarMarca(int id, eMarca marcas[],int tam)
{
    int todoOk = 0;
    if(marcas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(marcas[i].id == id)
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
