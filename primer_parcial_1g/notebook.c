#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"

int menu()
{
    int opcion;

    system("cls");
    printf("    Menu de opciones   \n");
    printf("---------------------\n");
    printf("1 - Alta Notebook \n");
    printf("2 - Modificar jugador \n");
    printf("3 - Baja Notebook \n");
    printf("4 - Lista de notebooks \n");
    printf("5 - Lista de marcas \n");
    printf("6 - Lista de tipos \n");
    printf("7 - Lista de servicios  \n");
    printf("8 - Alta trabajos  \n");
    printf("9 - Lista de trabajos  \n");
    printf("10 - Salir  \n");
    printf("Ingrese opcion:   \n");
    scanf("%d", &opcion);

    return opcion;
}


int inicializarNotebooks(eNotebook notebooks[], int tam)
{
    int todoOk = 0;

    if(notebooks != NULL && tam > 0)
    {
        for(int i = 0; i > tam; i ++)
        {
            notebooks[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}

int harcodearNotebooks(eNotebook notebooks[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eNotebook lista[4] = {{1, "Modelo uno", 1000, 5001, 80000.00, 0},
                         {2, "Modelo dos", 1002, 5000, 70000.00, 0},
                         {3, "Modelo tres", 1003, 5002, 75000.00, 0},
                         {4, "Modelo cuatro", 1001, 5003, 100000.00, 0}};

    if(notebooks != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        for(int i = 0; i < cant; i ++)
        {
            notebooks[i] = lista[i];
            (*pId) ++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eNotebook notebooks[], int tam, int* pIndice)
{
    int indice = -1;
    if(notebooks != NULL && tam > 0 && pIndice != NULL)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(notebooks[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
    }
    return indice;
}

int buscarNotebook(eNotebook notebooks[], int tam, int* pIndice, int id)
{
    int indice = -1;
    if(notebooks != NULL && tam > 0 && pIndice != NULL)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].id == id)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
    }
    return indice;
}

void mostrarNotabook(eNotebook unaNotebook, eMarca marcas[], int tam,  eTipo tipos[], int tamt)
{
    char descMarca[20];
    char descTipo[20];

    if(cargarNombreMarca(marcas, tam, unaNotebook.idMarca, descMarca) == 1 &&
       cargarNombreTipo(tipos, tamt, unaNotebook.idTipo, descTipo) == 1)
    {

         printf("| %3d  |  %-15s| %-8s | %-10s | %10.2f  |\n", unaNotebook.id,
                                                                            unaNotebook.modelo,
                                                                            descMarca,
                                                                            descTipo,
                                                                            unaNotebook.precio);
    }

}
int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int flag = 1;
    if(notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamt > 0)
    {
        system("cls");
        printf("================================================================\n");
        printf("|                    *** lista Notebooks ***                   |\n");
        printf("================================================================\n");
        printf("|  Id  |  Modelo         | Marca    | Tipo       |   Precio    |\n");
        printf("================================================================\n");
        for(int i = 0; i < tam; i ++)
        {
            if(notebooks[i].isEmpty == 0)
            {
                ordenarNotebook(notebooks, tam);
                mostrarNotabook(notebooks[i], marcas, tama, tipos, tamt);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("|                No hay jugadores para mostrar !               |\n");
        }
        printf("================================================================\n");
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}
int ordenarNotebook(eNotebook notebooks[], int tam)
{
    int todoOk = 0;
    eNotebook auxOrden;

    if(notebooks != NULL && tam > 0)
    {
        for(int i = 0; i < tam-1; i ++)
        {
            for(int j = i + 1; j < tam; j ++)
            {

                if((notebooks[i].idMarca >  notebooks[j].idMarca) ||
                  ((notebooks[i].idMarca ==  notebooks[j].idMarca) &&
                  notebooks[i].precio >  notebooks[j].precio))
                {
                    auxOrden = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = auxOrden;
                }

            }
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarEnteroRango(int valor, int minimo, int maximo)
{
    int todoOk = 0;

    if(valor >= minimo && valor <= maximo)
    {
        todoOk = 1;
    }
    return todoOk;
}

int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, int* pId)
{
    int todoOk = 0;
    int indice;
    eNotebook auxNotebook;

    if(notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamt > 0 && pId != NULL)
    {
        system("cls");
        printf("\n      Alta Alumno     \n");
        printf("     =============     \n\n");
        indice = buscarLibre(notebooks, tam, &indice);
        if(indice == -1)
        {
            printf("No hay lugar!");
        }
        else
        {
            auxNotebook.id = *pId;
            (*pId) ++;

            printf("Ingrese modelo de la notebook: ");
            fflush(stdin);
            gets(auxNotebook.modelo);
            while(strlen(auxNotebook.modelo) >= 20 || atoi(auxNotebook.modelo))// validacion
            {
                printf("Error! \nIngrese un modelo valido: ");
                fflush(stdin);
                gets(auxNotebook.modelo);
            }
            strlwr(auxNotebook.modelo);
            auxNotebook.modelo[0] = toupper(auxNotebook.modelo[0]);

            system("cls");
            mostrarMarca(marcas, tama);
            printf("Ingrese ID de marca: ");
            scanf("%d", &auxNotebook.idMarca);
            while(!validarMarca(auxNotebook.idMarca, marcas, tama))
            {
                system("cls");
                mostrarMarca(marcas, tama);
                printf("Error! \nIngrese ID de marca valida: ");
                scanf("%d", &auxNotebook.idMarca);
            }

            system("cls");
            mostrarTipos(tipos, tamt);
            printf("Ingrese ID del tipo: ");
            scanf("%d", &auxNotebook.idTipo);
            while(!validarTipo(auxNotebook.idTipo, tipos, tamt))
            {
                system("cls");
                mostrarTipos(tipos, tamt);
                printf("Error! \nIngrese ID de un tipo valida: ");
                scanf("%d", &auxNotebook.idTipo);
            }

            printf("Ingrese el precio: ");
            scanf("%f", &auxNotebook.precio);
           /* while(!validarEnteroRango(auxNotebook.precio, 30000, 500000))
            {
                printf("Error! \nIgrese el precio maximo 500000: ");
                scanf("%f", &auxNotebook.precio);
            }*/

            auxNotebook.isEmpty = 0;
            notebooks[indice] = auxNotebook;
            todoOk = 1;
        }
    }
    return todoOk;
}

int bajaNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    char confirmar;
    int id;

    if(notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamt > 0)
    {
        system("cls");
        printf("\n      Baja Alumno     \n");
        printf("     =============     \n\n");
        mostrarNotebooks(notebooks, tam, marcas, tama, tipos, tamt);
        printf("Ingrese el ID de la Notebook: ");
        scanf("%d", &id);
        indice = buscarNotebook(notebooks, tam, &indice, id);
        if(indice == -1)
        {
            printf("ID no registrado en el sistema!");
        }
        else
        {
            mostrarNotabook(notebooks[indice], marcas, tama, tipos, tamt);
            printf("Confirma baja?:  ");
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar == 's')
            {
                notebooks[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja Cancelada! \n");
            }
        }
    }
    return todoOk;
}

int menuModificacion()
{
    int opcion;
    system("cls");
    printf("Seleccione lo que quiere modificar:    \n \n");
    printf("1- precio \n");
    printf("2- tipo \n");
    printf("Ingrese opcion:  \n");
    scanf("%d", &opcion);

    return opcion;
}

int modificarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    char confirmar;
    int id;
    int auxTipo;
    float auxPrecio;

    if(notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamt > 0)
    {
        system("cls");
        printf("\n      Modificar Alumno     \n");
        printf("     ==================     \n\n");
        mostrarNotebooks(notebooks, tam, marcas, tama, tipos, tamt);
        printf("Ingrese el ID del jugador: ");
        scanf("%d", &id);
        indice = buscarNotebook(notebooks, tam, &indice, id);
        if(indice == -1)
        {
            printf("ID no registrado en el sistema!");
        }
        else
        {
            mostrarNotabook(notebooks[indice], marcas, tama, tipos, tamt);
            printf("Confirma modificacion?:  ");
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar == 's')
            {
                switch ( menuModificacion())
                {
                case 1:
                    printf("ingrese un nuevo precio:");
                    scanf("%f", &auxPrecio);
                    notebooks[indice].precio = auxPrecio;
                    break;
                case 2:
                    mostrarTipos(tipos, tamt);
                    printf("ingrese ID del nuevo tipo:");
                    scanf("%d", &auxTipo);
                    notebooks[indice].idTipo = auxTipo;
                    break;
                default:
                    printf("Opcion invalida!");
                    break;
                }
                todoOk = 1;
            }
            else
            {
                printf("Modificacion Cancelada! \n");
            }
        }
    }
    return todoOk;
}

