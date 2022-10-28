#include "notebook.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;
typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief incializo isEmpty en 1
 *
 * \param trabajos[] eTrabajo estructura a recorrer
 * \param tam int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int inicializarTrabajo(eTrabajo trabajos[], int tam);

/** \brief busca si hay un espacio libre en la estruc. eTrabajo
 *
 * \param pIndice int* puntero indice a ser evaluado para la busqueda
 * \param trabajos[] eTrabajo estructura que recorre
 * \param tamt int tamaño de las filas
 * \return int indice -1 si no encontro lugar
 *
 */
int buscarLibreTrabajo(int* pIndice, eTrabajo trabajos[], int tamt);

/** \brief genera el alta del trabajo
 *
 * \param trabajos[] eTrabajo estructura que le genero el alta
 * \param tamt int tamaño de las filas de eTrabajo
 * \param notebooks[] eNotebook estructura que pido por parametro
 * \param tam int tamaño de las filas de eNotebook
 * \param marcas[] eMarca estructura que pido por parametro
 * \param tama int tamaño de las filas de eMarca
 * \param tipos[] eTipo estructura que pido por parametro
 * \param tamti int tamaño de las filas de eTipo
 * \param servicios[] eServicio estructura que pido por parametro
 * \param tams int tamaño de las filas de eServicio
 * \param pIdTrabajo int* puntero del ID de trabajo
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamt, eNotebook notebooks[], int tam, eMarca marcas[], int tama, eTipo tipos[], int tamti,
                eServicio servicios[], int tams, int* pIdTrabajo);

/** \brief muestro trabajo
 *
 * \param trabajos eTrabajo variable de estructura a recorrer
 * \param servicios[] eServicio estructura que le pido la descripcion
 * \param tams int tamaño de las filas de eServicio
 * \param notebooks[] eNotebook estructura que le pido la descripcion
 * \param tam int tamaño de las filas de eNotebook
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajos, eServicio servicios[], int tams, eNotebook notebooks[], int tam);

/** \brief muestro la lista de trabajo
 *
 * \param trabajos[] eTrabajo estructura a recorrer
 * \param tamt int tamaño de las filas de eTrabajo
 * \param notebooks[] eNotebook estructura que le pido la descripcion
 * \param tam int tamaño de las filas de eNotebook
 * \param clear int limpia pantalla
 * \param servicios[] eServicio estructura que le pido la descripcion
 * \param tams int tamaño de las filas de eServicio
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamt, eNotebook notebooks[], int tam, int clear, eServicio servicios[], int tams);
