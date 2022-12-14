#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "cliente.h"

#define TAM_N 10
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define TAM_C 4
#define TAM_TR 10

int main()
{
    char seguir = 's';
    int nextId = 1000;
    int nextIdTrabajo = 100;

    eNotebook notebooks[TAM_N];
    eTrabajo trabajos[TAM_TR];

    eMarca marcas[TAM_M] = {{1000, "Compaq"},
                            {1001, "Asus"},
                            {1002, "Acer"},
                            {1003, "HP"}};

    eTipo tipos[TAM_T] = {{5000, "Gamer"},
                          {5001, "Disenio"},
                          {5002, "Ultrabook"},
                          {5003, "Normalita"}};

    eServicio servicios[TAM_S] = {{20000, "Bateria",2250.00},
                                  {20001, "Display",10300.00},
                                  {20002, "Teclado",4400.00},
                                  {20003, "Fuente",5600.00}};

    eCliente clientes[TAM_C] = {{2000, "Juan",'m'},
                                {2001, "Pedro",'m'},
                                {2002, "Maria",'f'},
                                {2003, "Carla",'f'}};

    if(!inicializarNotebooks(notebooks, TAM_N))
    {
        printf("Problemas al inicializar!");
    }

    if(!inicializarTrabajo(trabajos, TAM_TR))
    {
        printf("Problemas al inicializar!");
    }

    harcodearNotebooks(notebooks, TAM_N, 4, &nextId);

    do
    {
        switch(menu())
        {
            case 1:
                if(!altaNotebook(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, clientes, TAM_C, &nextId))
                {
                    printf("NO se pudo realizar el alta! \n");
                }
                else
                {
                    printf("Alta exitosa! \n");
                }
            break;
            case 2:
                if(!modificarNotebooks(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, clientes, TAM_C))
                {
                    printf("NO se pudo realizar la modificacion! \n");
                }
                else
                {
                    printf("Modificacion exitosa! \n");
                }
            break;
            case 3:
                if(!bajaNotebooks(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, clientes, TAM_C))
                {
                    printf("NO se pudo realizar la baja! \n");
                }
                else
                {
                    printf("Baja exitosa! \n");
                }
            break;
           case 4:
                mostrarNotebooks(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, clientes, TAM_C, 1);
            break;
            case 5:
                mostrarMarca(marcas, TAM_M, 1);
            break;
            case 6:
                mostrarTipos(tipos, TAM_T, 1);
            break;
            case 7:
                mostrarServicios(servicios, TAM_S, 1);
            break;
            case 8:
                if(!altaTrabajo(trabajos, TAM_TR, notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, servicios, TAM_S, clientes, TAM_C, &nextIdTrabajo))
                {
                    printf("NO se pudo realizar el alta! \n");
                }
                else
                {
                    printf("Alta exitosa! \n");
                }
            break;
            case 9:
                mostrarTrabajos(trabajos, TAM_TR, notebooks, TAM_N, 1, servicios, TAM_S);
            break;
            case 10:
                switch(menuInformes())
                {
                    case 1:
                        mostrarNotebooksTipos(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, clientes, TAM_C);
                    break;
                    case 2:
                        mostrarNotebooksMarcas(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, clientes, TAM_C);
                    break;
                    case 3:
                        mostrarNotebooksMasBaratas(notebooks, TAM_N);
                    break;
                    case 4:
                        mostrarListaPorMarca(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T, clientes, TAM_C);
                    break;
                    case 5:
                        mostrarCanNotebookTipoMarca(notebooks, TAM_N, marcas, TAM_M, tipos, TAM_T);
                    break;
                    case 6:
                        mostrarMarcasMasElegidas(notebooks, TAM_N, marcas, TAM_M);
                    break;
                    case 7:
                        printf("La opcion 7");
                    break;
                    case 8:
                        printf("La opcion 8");
                    break;
                    case 9:
                        printf("La opcion 9");
                    break;
                    case 10:
                        printf("La opcion 10");
                    break;
                    default:
                        printf("La opcion no existe! Ingrese la opcion correcta");
                    break;
                }
            break;
            case 11:
                printf("Has seleccionado Salir  \n");
                seguir = 'n';
            break;
            default:
                printf("La opcion no existe! Ingrese la opcion correcta");
            break;
        }
        system("pause");
    }while(seguir == 's');

    return 0;
}
