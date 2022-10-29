#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "notebook.h"

int cargarNombreCliente(eCliente clientes[], int tam, int idCliente, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if(clientes != NULL && tam > 0)
    {
        todoOk = 1;
        for(int i = 0; i < tam; i ++)
        {
            if(clientes[i].id == idCliente)
            {
                strcpy(nombre, clientes[i].nombre);
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
int mostrarClientes(eCliente clientes[], int tam, int clear)
{
    int todoOk = 0;
    if(clientes != NULL && tam > 0)
    {
        if(clear)
        {
            system("cls");
        }
        printf("=============================\n");
        printf("   *** lista de clientes *** \n");
        printf("=============================\n");
        printf("   id      nombre       sexo\n");
        printf("=============================\n");
        for (int i = 0; i < tam; i++)
        {
             printf("  %d   %10s     %c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
        }
        printf("=============================\n");
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarClientes(int id, eCliente clientes[], int tam)
{
    int todoOk = 0;
    if(clientes != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(clientes[i].id == id)
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
