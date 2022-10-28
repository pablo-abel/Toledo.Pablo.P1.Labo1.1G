#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int cargarNombreServicios(eServicio servicios[], int tam, int idServicios, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(servicios != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i = 0; i < tam; i ++)
        {
            if(servicios[i].id == idServicios)
            {
                strcpy(descripcion, servicios[i].descripcion);
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

int mostrarServicios(eServicio servicios[], int tam, int clear)
{
    int todoOk = 0;
    if(servicios != NULL && tam > 0)
    {
        if(clear)
        {
            system("cls");
        }
        printf("===================================\n");
        printf("     *** lista de servicios ***   \n");
        printf("===================================\n");
        printf("   id      Descripcion      precio\n");
        printf("===================================\n");
        for (int i = 0; i < tam; i++)
        {
             printf("  %d     %-7s     %10.2f  \n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("===================================\n");
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarServicios(int id, eServicio servicios[], int tam)
{
    int todoOk = 0;
    if(servicios != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(servicios[i].id == id)
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
