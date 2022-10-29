#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "cliente.h"

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
    printf("10 INFORMES:  \n");
    printf("11 - Salir  \n");
    printf("Ingrese opcion:   \n");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("    Menu de Informes   \n");
    printf("---------------------\n");
    printf("1 - Mostrar Notebook del tipo seleccionado por el usuario \n");
    printf("2 - Mostrar Notebook de una marca seleccionada \n");
    printf("3 - Informar la o las notebooks mas baratas\n");
    printf("4 - Mostrar un listado de las  Notebooks separadas por marca\n");
    printf("5 - Elegir un tipo y una marca y contar cuantas hay de ese tipo y marca\n");
    printf("6 - Mostrar la o las marcas mas elegidas por los clientes\n");
    printf("7 - Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma \n");
    printf("8 - \n");
    printf("9 - \n");
    printf("10 - \n");
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
    eNotebook lista[4] = {{1000, "Modelo uno", 1000, 5001, 2000, 80000.00, 0},
                         {1001, "Modelo dos", 1002, 5000, 2001, 70000.00, 0},
                         {1002, "Modelo tres", 1003, 5002, 2003, 75000.00, 0},
                         {1003, "Modelo cuatro", 1001, 5003, 2002, 100000.00, 0}};

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

void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tam,  eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    char descMarca[20];
    char descTipo[20];
    char nombreCliente[20];

    if(cargarNombreMarca(marcas, tam, unaNotebook.idMarca, descMarca) == 1 &&
       cargarNombreTipo(tipos, tamt, unaNotebook.idTipo, descTipo) == 1 &&
       cargarNombreCliente(clientes, tamc, unaNotebook.idCliente, nombreCliente) == 1)
    {

         printf(" %3d    %-15s %-8s  %-10s  %-8s  %10.2f  \n", unaNotebook.id,
                                                               unaNotebook.modelo,
                                                               descMarca,
                                                               descTipo,
                                                               nombreCliente,
                                                               unaNotebook.precio);
    }

}
int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc, int clear)
{
    int todoOk = 0;
    int flag = 1;
    if(notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamt > 0)
    {
        if(clear)
        {
            system("cls");
        }
        printf("==================================================================\n");
        printf("                    *** lista Notebooks ***                \n");
        printf("==================================================================\n");
        printf("  Id    Modelo           Marca     Tipo       nombre       Precio   \n");
        printf("==================================================================\n");
        for(int i = 0; i < tam; i ++)
        {
            if(!notebooks[i].isEmpty)
            {
                ordenarNotebook(notebooks, tam);
                mostrarNotebook(notebooks[i], marcas, tama, tipos, tamt, clientes, tamc);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("                No hay jugadores para mostrar !            \n");
        }
        printf("==================================================================\n");
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

int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc, int* pId)
{
    int todoOk = 0;
    int indice;
    eNotebook auxNotebook;

    if(notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamt > 0 && pId != NULL)
    {
        system("cls");
        printf("\n      Alta Notebook     \n");
        printf("     ===============     \n\n");
        indice = buscarLibre(notebooks, tam, &indice);
        if(indice == -1)
        {
            printf("No hay lugar!");
        }
        else
        {
            auxNotebook.id = *pId;
            (*pId) ++;

            mostrarNotebooks(notebooks, tam, marcas, tama, tipos, tamt, clientes, tamc, 0);
            printf("Ingrese modelo de la notebook: ");
            fflush(stdin);
            gets(auxNotebook.modelo);
            while(strlen(auxNotebook.modelo) >= 20 || atoi(auxNotebook.modelo))
            {
                printf("Error. Ingrese un modelo valido: ");
                fflush(stdin);
                gets(auxNotebook.modelo);
            }
            strlwr(auxNotebook.modelo);
            auxNotebook.modelo[0] = toupper(auxNotebook.modelo[0]);

            system("cls");
            mostrarMarca(marcas, tama, 0);
            printf("Ingrese ID de marca: ");
            scanf("%d", &auxNotebook.idMarca);
            while(!validarMarca(auxNotebook.idMarca, marcas, tama))
            {
                system("cls");
                mostrarMarca(marcas, tama, 0);
                printf("Error. Ingrese ID de marca valida: ");
                scanf("%d", &auxNotebook.idMarca);
            }

            system("cls");
            mostrarTipos(tipos, tamt, 0);
            printf("Ingrese ID del tipo: ");
            scanf("%d", &auxNotebook.idTipo);
            while(!validarTipo(auxNotebook.idTipo, tipos, tamt))
            {
                system("cls");
                mostrarTipos(tipos, tamt, 0);
                printf("Error. Ingrese ID de un tipo valida: ");
                scanf("%d", &auxNotebook.idTipo);
            }

            system("cls");
            mostrarClientes(clientes, tamc, 0);
            printf("Ingrese ID del cliente: ");
            scanf("%d", &auxNotebook.idCliente);
            while(!validarClientes(auxNotebook.idCliente, clientes, tamc))
            {
                system("cls");
                mostrarClientes(clientes, tamc, 0);
                printf("Error. Ingrese ID de un cliente valida: ");
                scanf("%d", &auxNotebook.idCliente);
            }

            printf("Ingrese el precio: ");
            scanf("%f", &auxNotebook.precio);

            auxNotebook.isEmpty = 0;
            notebooks[indice] = auxNotebook;
            todoOk = 1;
        }
    }
    return todoOk;
}

int bajaNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk = 0;
    int indice;
    char confirmar;
    int id;

    if(notebooks != NULL && tam > 0 && marcas != NULL && tama > 0 && tipos != NULL && tamt > 0)
    {
        system("cls");
        printf("\n      Baja Notebook     \n");
        printf("     ===============     \n\n");
        mostrarNotebooks(notebooks, tam, marcas, tama, tipos, tamt, clientes, tamc, 0);
        printf("Ingrese el ID de la Notebook: ");
        scanf("%d", &id);
        indice = buscarNotebook(notebooks, tam, &indice, id);
        if(indice == -1)
        {
            printf("ID no registrado en el sistema!");
        }
        else
        {
            mostrarNotebook(notebooks[indice], marcas, tama, tipos, tamt, clientes, tamc);
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
    printf("Seleccione lo que quiere modificar: \n");
    printf(" 1 - precio \n");
    printf(" 2 - tipo \n");
    printf("Ingrese opcion:  \n");
    scanf("%d", &opcion);

    return opcion;
}

int modificarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
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
        printf("\n      Modificar Notebook     \n");
        printf("     ====================     \n\n");
        mostrarNotebooks(notebooks, tam, marcas, tama, tipos, tamt, clientes, tamc, 0);
        printf("Ingrese el ID de la notebook: ");
        scanf("%d", &id);
        indice = buscarNotebook(notebooks, tam, &indice, id);
        if(indice == -1)
        {
            printf("ID no registrado en el sistema!");
        }
        else
        {
            mostrarNotebook(notebooks[indice], marcas, tama, tipos, tamt, clientes, tamc);
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
                    mostrarTipos(tipos, tamt, 0);
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

int validarNotebookId(eNotebook notebooks[], int tam, int id)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (notebooks[i].id == id && !notebooks[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarModeloNotebook(eNotebook notebooks[], int tam, int idNotebook, char modelo[])
{
    int todoOk = 0;
    int flag = 1;
    if(notebooks != NULL && tam > 0 && modelo != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if(notebooks[i].id == idNotebook)
            {
                strcpy(modelo, notebooks[i].modelo);
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

int mostrarNoteboksIdTipos(int idTipo, eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk = 0;
    char descTipo[20];
    int flag = 1;
    if (notebooks != NULL && tam > 0 && tipos != NULL && tamt > 0 && marcas != NULL && tama > 0 && clientes != NULL && tamc > 0)
    {
        printf("==================================================================\n");
        printf("                    *** lista Notebooks ***                \n");
        printf("==================================================================\n");
        printf("  Id    Modelo           Marca     Tipo       nombre       Precio   \n");
        printf("==================================================================\n");
        for (int i = 0; i < tam; i++)
        {
            if (!notebooks[i].isEmpty && notebooks[i].idTipo == idTipo)
            {
                mostrarNotebook(notebooks[i], marcas, tama, tipos, tamt, clientes, tamc);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarNombreTipo(tipos, tamt, idTipo, descTipo);
            printf("\n                    No hay notebooks en %s!           \n\n", descTipo);
        }
        printf("==================================================================\n");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarNotebooksTipos(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk = 0;
    int idTipo;

    if (notebooks != NULL && tam > 0 && tipos != NULL && tamt > 0 && marcas != NULL && tama > 0 && clientes != NULL && tamc > 0)
    {
        system("cls");
        mostrarTipos(tipos, tamt, 1);
        printf("Ingrese ID del tipo: ");
        scanf("%d", &idTipo);
        while(!validarTipo(idTipo, tipos, tamt))
        {
            system("cls");
            mostrarTipos(tipos, tamt, 1);
            printf("Error. Ingrese Id del tipo valido: ");
            scanf("%d", &idTipo);
        }

        mostrarNoteboksIdTipos(idTipo ,notebooks, tam, marcas, tama, tipos, tamt, clientes, tamc);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarNoteboksIdMarcas(int idMarca, eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk = 0;
    char descMarca[20];
    int flag = 1;
    if (notebooks != NULL && tam > 0 && tipos != NULL && tamt > 0 && marcas != NULL && tama > 0 && clientes != NULL && tamc > 0)
    {
        printf("==================================================================\n");
        printf("                    *** lista Notebooks ***                \n");
        printf("==================================================================\n");
        printf("  Id    Modelo           Marca     Tipo       nombre       Precio   \n");
        printf("==================================================================\n");
        for (int i = 0; i < tam; i++)
        {
            if (!notebooks[i].isEmpty && notebooks[i].idMarca == idMarca)
            {
                mostrarNotebook(notebooks[i], marcas, tama, tipos, tamt, clientes, tamc);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarNombreMarca(marcas, tama, idMarca, descMarca);
            printf("\n                    No hay notebooks en %s!           \n\n", descMarca);
        }
        printf("==================================================================\n");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarNotebooksMarcas(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk = 0;
    int idMarca;

    if (notebooks != NULL && tam > 0 && tipos != NULL && tamt > 0 && marcas != NULL && tama > 0 && clientes != NULL && tamc > 0)
    {
        system("cls");
        mostrarMarca(marcas, tama, 1);
        printf("Ingrese ID de la marca: ");
        scanf("%d", &idMarca);
        while(!validarMarca(idMarca, marcas, tama))
        {
            system("cls");
            mostrarMarca(marcas, tama, 1);
            printf("Error. Ingrese ID de la marca valido: ");
            scanf("%d", &idMarca);
        }

        mostrarNoteboksIdMarcas(idMarca ,notebooks, tam, marcas, tama, tipos, tamt, clientes, tamc);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarNotebooksMasBaratas(eNotebook notebooks[], int tam)
{
    int todoOk = 0;
    float menorPrecio;
    int flag = 1;

    if (notebooks != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (notebooks[i].isEmpty == 0)
            {
                if(flag || notebooks[i].precio < menorPrecio)
                {
                    menorPrecio = notebooks[i].precio;
                    flag = 0;
                }
            }
        }
        system("cls");
        printf("=====================================\n");
        printf("         Precios mas baratos         \n");
        printf("=====================================\n");
        for (int i = 0; i < tam; i++)
        {
            if (!notebooks[i].isEmpty && notebooks[i].precio == menorPrecio)
            {
                    printf("Modelo: %s \n", notebooks[i].modelo);
            }
        }
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarListaPorMarca(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk = 0;
    if (notebooks != NULL && tam > 0 && tipos != NULL && tamt > 0 && marcas != NULL && tama > 0 && clientes != NULL && tamc > 0)
    {
        system("cls");
        printf("\n================================================================\n");
        printf("                   *** lista Notebook por Marca ***               \n");
        printf("==================================================================\n");
        for (int i = 0; i < tama; i++)
        {
             printf("\nMarca:   %s \n", marcas[i].descripcion);

             mostrarNoteboksIdMarcas(marcas[i].id, notebooks, tam, marcas, tama, tipos, tamt, clientes, tamc);

             printf("==================================================================\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarCanNotebookTipoMarca(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int idTipo;
    int idMarca;
    int contadorTipo;
    int contadorMarca;

    if(notebooks != NULL && tam > 0 && tipos != NULL && tamt > 0 && marcas != NULL && tama > 0 )
    {
        system("cls");
        printf("\nCantidad de Notebook por Tipo y Marca:\n\n");
        system("cls");
        mostrarTipos(tipos, tamt, 1);
        printf("Ingrese ID del tipo: ");
        scanf("%d", &idTipo);
        while(!validarTipo(idTipo, tipos, tamt))
        {
            system("cls");
            mostrarTipos(tipos, tamt, 1);
            printf("Error! \nIngrese ID del tipo: ");
            scanf("%d", &idTipo);
        }

        system("cls");
        mostrarMarca(marcas, tama, 1);
        printf("Ingrese ID de la marca: ");
        scanf("%d", &idMarca);
        while(!validarMarca(idMarca, marcas, tama))
        {
            system("cls");
            mostrarMarca(marcas, tama, 1);
            printf("Error! \nIngrese ID de la marca valida: ");
            scanf("%d", &idMarca);
        }
        system("cls");
        for (int i = 0; i < tamt; i++)
        {
            if(idTipo == tipos[i].id)
            {
                printf("\nTipo: %s    ", tipos[i].descripcion);
            }
            contadorTipo = 0;
            for (int j = 0; j < tam; j++)
            {
                if (!notebooks[j].isEmpty && notebooks[j].idTipo == idTipo)
                {
                    contadorTipo ++;
                }
            }
        }
        for (int i = 0; i < tama; i++)
        {
            if(idMarca == marcas[i].id)
            {
               printf("Marca: %s \n", marcas[i].descripcion);
            }
            contadorMarca = 0;
            for (int j = 0; j < tam; j++)
            {
                if (!notebooks[j].isEmpty && notebooks[j].idMarca == idMarca)
                {
                    contadorMarca ++;
                }
            }
        }
        printf("\nCantidad del Tipo: %d \nCantidad de la Marca: %d\n\n", contadorTipo, contadorMarca);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMarcasMasElegidas(eNotebook notebooks[], int tam, eMarca marcas[], int tama)
{
    int todoOk = 0;
    int contadores[] = {0,0,0,0,0};
    int masElegida;


    if (notebooks != NULL && tam > 0 && marcas != NULL && tama > 0)
    {
       system("cls");
        printf(" Marcas mas elegidas: \n");
        for (int i = 0; i < tama; i++)
        {
             for (int j = 0; j < tam; j++)
             {
                 if (!notebooks[j].isEmpty && notebooks[j].idMarca == marcas[i].id)
                 {
                     contadores[i] ++;
                 }
             }
             for (int i = 0; i < tama; i++)
             {
                 if(i == 0 || contadores[i] > masElegida)
                 {
                     masElegida = contadores[i];
                 }
             }
        }
        for (int i = 0; i < tama; i++)
        {
            if(contadores[i] == masElegida)
            {
               printf("\nMarca: %s \n", marcas[i].descripcion);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
