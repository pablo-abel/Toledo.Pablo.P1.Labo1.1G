#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

#endif // TIPO_H_INCLUDED

/** \brief cargo por ID la descripcion de la estructura
 *
 * \param tipos[] eTipo estructura a recorrer
 * \param tam int tamaño de las filas
 * \param idTipos int Id que pedimos por parametro para comparar
 * \param descripcion[] char cadena que le asigno la descripcion de la estruc eTipo
 * \return int retorno 1 si esta todo Ok -1 si hubo un error 0 si hubo problema en la validacion
 *
 */
int cargarNombreTipo(eTipo tipos[], int tam, int idTipos, char descripcion[]);

/** \brief muestro la lista del tipo
 *
 * \param tipos[] eTipo estructura a mostrar
 * \param tam int tamaño de las filas
 * \param clear int limpia pantalla
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarTipos(eTipo tipos[], int tam, int clear);

/** \brief valida que el ID exista en la estructura
 *
 * \param id int  ID a validar
 * \param tipos[] eTipo estructura a recorrer
 * \param tam int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int validarTipo(int id, eTipo tipos[],int tam);
