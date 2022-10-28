#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "servicio.h"
#include "notebook.h"

int inicializarTrabajo(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if (trabajos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(int* pIndice, eTrabajo trabajos[], int tamt)
{
    int indice = -1;

    if (pIndice != NULL && trabajos != NULL && tamt > 0)
    {
        for (int i = 0; i < tamt; i++)
        {
            if (trabajos[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
    }
    return indice;
}

int altaTrabajo(eTrabajo trabajos[], int tamt, eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamti,
                eServicio servicios[], int tams, int* pIdTrabajo)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if (trabajos != NULL && tamt > 0 && notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamti > 0 &&
        servicios != NULL && tams > 0 && pIdTrabajo != NULL)
    {
        system("cls");
        printf("\n       Alta Trabajo     \n");
        printf("-------------------------\n");
        indice = buscarLibreTrabajo(&indice, trabajos, tamt);
        if (indice == -1)
        {
            printf("NO hay lugar! \n");
        }
        else
        {
            auxTrabajo.id = *pIdTrabajo;
            (*pIdTrabajo)++;

            system("cls");
            mostrarServicios(servicios, tams, 0);
            printf("Ingrese ID del servicio: ");
            scanf("%d", &auxTrabajo.idServicio);
            while(!validarServicios(auxTrabajo.idServicio, servicios, tams))
            {
                system("cls");
                mostrarServicios(servicios, tams, 1);
                printf("Error! \nIngrese ID del servicio valido: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            mostrarNotebooks(notebooks, tam, marcas, tama, tipos, tamti, 0);
            printf("Ingrese ID de la notebook: ");
            scanf("%d", &auxTrabajo.idNotebook);
            while(validarNotebookId(notebooks, tam, auxTrabajo.idNotebook) == -1)
            {
                printf("Error, Ingrese ID de la notebook: ");
                scanf("%d", &auxTrabajo.idNotebook);
            }

            printf("ingrese fecha: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

            auxTrabajo.isEmpty = 0;
            trabajos[indice] = auxTrabajo;
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarTrabajo(eTrabajo trabajos, eServicio servicios[], int tams, eNotebook notebooks[], int tam)
{
    char descServicio[20];
    char modelo[20];

    if(cargarNombreServicios(servicios, tams, trabajos.idServicio, descServicio) == 1 &&
       cargarModeloNotebook(notebooks, tam, trabajos.idNotebook, modelo) == 1)
    {
        printf("  %d    %-13s   %-10s  %02d/%02d/%4d \n", trabajos.id,
                                                           modelo,
                                                           descServicio,
                                                           trabajos.fecha.dia,
                                                           trabajos.fecha.mes,
                                                           trabajos.fecha.anio);
    }

}

int mostrarTrabajos(eTrabajo trabajos[], int tamt, eNotebook notebooks[], int tam, int clear, eServicio servicios[], int tams)
{
    int todoOk = 0;
    int flag = 1;
    if (trabajos != NULL && tamt > 0 && notebooks != NULL && tam > 0 && servicios != NULL && tams > 0 && clear >= 0 && clear <= 1)
    {
        if(clear)
        {
            system("cls");
        }
        printf("===============================================\n");
        printf("            *** lista Trabajo ***              \n");
        printf("===============================================\n");
        printf("  Id     Modelo          Servicio    Fecha     \n");
        printf("===============================================\n");
        for (int i = 0; i < tamt; i++)
        {
            if (trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i], servicios, tams, notebooks, tam);
                flag = 0;

            }
        }
        if (flag)
        {
            printf("\n          No hay Trabajo para mostrar!        \n\n");
        }
        printf("===============================================\n");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}
