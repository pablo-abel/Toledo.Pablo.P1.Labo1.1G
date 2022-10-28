#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "notebook.h"

int cargarNombreTipo(eTipo tipos[], int tam, int idTipos, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(tipos != NULL && tam > 0)
    {
        todoOk = 1;
        for(int i = 0; i < tam; i ++)
        {
            if(tipos[i].id == idTipos)
            {
                strcpy(descripcion, tipos[i].descripcion);
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
int mostrarTipos(eTipo tipos[], int tam, int clear)
{
    int todoOk = 0;
    if(tipos != NULL && tam > 0)
    {
        if(clear)
        {
            system("cls");
        }
        printf("========================\n");
        printf(" *** lista de tipos *** \n");
        printf("========================\n");
        printf("    id      Descripcion \n");
        printf("========================\n");
        for (int i = 0; i < tam; i++)
        {
             printf("  %d       %10s \n", tipos[i].id, tipos[i].descripcion);
        }
        printf("========================\n");
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarTipo(int id, eTipo tipos[],int tam)
{
    int todoOk = 0;
    if(tipos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(tipos[i].id == id)
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
