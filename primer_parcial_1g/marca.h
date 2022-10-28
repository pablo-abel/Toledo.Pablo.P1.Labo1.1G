#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

#endif // MARCA_H_INCLUDED

/** \brief cargo por ID la descripcion de la estructura
 *
 * \param marcas[] eMarca estructura a recorrer
 * \param tam int tamaño de las filas
 * \param idMarca int Id que pedimos por parametro para comparar
 * \param descripcion[] char cadena que le asigno la descripcion de la estruc eMarca
 * \return int retorno 1 si esta todo Ok -1 si hubo un error 0 si hubo problema en la validacion
 *
 */
int cargarNombreMarca(eMarca marcas[], int tam, int idMarca, char descripcion[]);

/** \brief muestro la lista de las marcas
 *
 * \param marcas[] eMarca estructura a mostrar
 * \param tam int tamaño de las filas
 * \param clear int limpia pantalla
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarMarca(eMarca marcas[], int tam, int clear);

/** \brief  valida que el ID exista en la estructura
 *
 * \param id int  ID a validar
 * \param marcas[] eMarca  estructura a recorrer
 * \param tam int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int validarMarca(int id, eMarca marcas[],int tam);
