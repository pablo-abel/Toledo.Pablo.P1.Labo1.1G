#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief cargo por ID la descripcion de la estructura
 *
 * \param servicios[] eServicio estructura a recorrer
 * \param tam int tamaño de las filas
 * \param idServicios int Id que pedimos por parametro para comparar
 * \param descripcion[] char cadena que le asigno la descripcion de la estruc eServicio
 * \return int retorno 1 si esta todo Ok -1 si hubo un error 0 si hubo problema en la validacion
 *
 */
int cargarNombreServicios(eServicio servicios[], int tam, int idServicios, char descripcion[]);

/** \brief muestro la lista del servicio
 *
 * \param servicios[] eServicio estructura a mostrar
 * \param tam int tamaño de las filas
 * \param clear int limpia pantalla
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarServicios(eServicio servicios[], int tam, int clear);

/** \brief valida que el ID exista en la estructura
 *
 * \param id int ID a validar
 * \param servicios[] eServicio estructura a recorrer
 * \param tam int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int validarServicios(int id, eServicio servicios[], int tam);
