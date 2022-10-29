#include "marca.h"
#include "tipo.h"
#include "cliente.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int idCliente;
    float precio;
    int isEmpty;
} eNotebook;

#endif // NOTEBOOK_H_INCLUDED


/** \brief menu de opciones
 *
 * \return int retorna la opcion ingresada
 *
 */
int menu();

/** \brief menu de informe
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuInformes();

/** \brief incializo isEmpty en 1
 *
 * \param notebooks[] eNotebook estructura a recorrer
 * \param tam int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int inicializarNotebooks(eNotebook notebooks[], int tam);

/** \brief harcodea una lista de 4 notebooks
 *
 * \param notebooks[] eNotebook estructura de notebook
 * \param tam int tamaño de las filas
 * \param cant int cantidad de notebooks que quiero harcodear
 * \param pId int* puntero ID
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int harcodearNotebooks(eNotebook notebooks[], int tam, int cant, int* pId);

/** \brief busca si hay un espacio libre
 *
 * \param notebooks[] eNotebook estructura que recorre
 * \param tam int tamaño de las filas
 * \param pIndice int* puntero indice a ser evaluado para la busqueda
 * \return int indice -1 si no encontro lugar
 *
 */
int buscarLibre(eNotebook notebooks[], int tam, int* pIndice);

/** \brief busca el ID de las notebooks
 *
 * \param notebooks[] eNotebook estructura a recorrer
 * \param tam int tamaño de las filas
 * \param pIndice int* puntero indice
 * \param id int ID a buscar
 * \return int indice -1 si el ID no esta registrado
 *
 */
int buscarNotebook(eNotebook notebooks[], int tam, int* pIndice, int id);

/** \brief muestro trabajo
 *
 * \param unaNotebook eNotebook variable de estructura a recorrer
 * \param marcas[] eMarca estructura que le pido la descripcion
 * \param tam int tamaño de las filas de eMarca
 * \param tipos[] eTipo estructura que le pido la descripcion
 * \param tamt int tamaño de las filas de eTipo
 * \return void
 *
 */
void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tam,  eTipo tipos[], int tamt, eCliente clientes[], int tamc);

/** \brief muestro la lista de Notebooks
 *
 * \param notebooks[] eNotebook estructura a recorrer
 * \param tam int tamaño de las filas de eNotebooks
 * \param marcas[] eMarca estructura que le pido la descripcion
 * \param tama int tamaño de las filas de eMarca
 * \param tipos[] eTipo estructura que le pido la descripcion
 * \param tamt int tamaño de las filas de eTipo
 * \param clear int limpia pantalla
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc, int clear);

/** \brief ordena la lista de notebooks
 *
 * \param notebooks[] eNotebook estructura a ordenar
 * \param tam int tamaño de las filas de eNotebooks
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int ordenarNotebook(eNotebook notebooks[], int tam);

/** \brief genera el alta de una notebook
 *
 * \param notebooks[] eNotebook estructura que le genero el alta
 * \param tam int tamaño de las filas de eNotebooks
 * \param marcas[] eMarca estructura que pido por parametro
 * \param tama int tamaño de las filas de eMarca
 * \param tipos[] eTipo estructura que pido por parametro
 * \param tamt int tamaño de las filas de eTipo
 * \param pId int* puntero del ID de notebook
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc, int* pId);

/** \brief genera la baja de una notebook
 *
 * \param notebooks[] eNotebook estructura que le genero la baja
 * \param tam int tamaño de las filas de eNotebooks
 * \param marcas[] eMarca estructura que pido por parametro
 * \param tama int tamaño de las filas de eMarca
 * \param tipos[] eTipo estructura que pido por parametro
 * \param tamt int tamaño de las filas de eTipo
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int bajaNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

/** \brief  menu de opciones modificar
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuModificacion();

/** \brief modifica datos de la estructura
 *
 * \param notebooks[] eNotebook estructura a modificar
 * \param tam int tamaño de las filas de eNotebooks
 * \param marcas[] eMarca estructura que pido por parametro
 * \param tama int tamaño de las filas de eMarca
 * \param tipos[] eTipo estructura que pido por parametro
 * \param tamt int tamaño de las filas de eTipo
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int modificarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

/** \brief valida que el ID exista en la estructura
 *
 * \param notebooks[] eNotebook estructura a recorrer
 * \param tam int tamaño de las filas de eNotebooks
 * \param id int ID a validar
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int validarNotebookId(eNotebook notebooks[], int tam, int id);

/** \brief cargo por ID el modelo de la estructura
 *
 * \param notebooks[] eNotebook estructura a recorrer
 * \param tam int tamaño de las filas de eNotebooks
 * \param idNotebook int Id que pedimos por parametro para comparar
 * \param modelo[] char cadena que le asigno el modelo de la estruc eNotebook
 * \return int retorno 1 si esta todo Ok -1 si hubo un error 0 si hubo problema en la validacion
 *
 */
int cargarModeloNotebook(eNotebook notebooks[], int tam, int idNotebook, char modelo[]);

int mostrarNoteboksIdTipos(int idTipo, eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

int mostrarNotebooksTipos(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

int mostrarNoteboksIdMarcas(int idMarca, eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

int mostrarNotebooksMarcas(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

int mostrarNotebooksMasBaratas(eNotebook notebooks[], int tam);

int mostrarListaPorMarca(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

int mostrarCanNotebookTipoMarca(eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamt);

int mostrarMarcasMasElegidas(eNotebook notebooks[], int tam, eMarca marcas[], int tama);
