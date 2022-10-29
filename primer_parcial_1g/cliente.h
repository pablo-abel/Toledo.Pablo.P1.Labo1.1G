#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[25];
    char sexo;

} eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief cargo por ID la descripcion de la estructura
 *
 * \param tipos[] eTipo estructura a recorrer
 * \param tam int tamaño de las filas
 * \param idTipos int Id que pedimos por parametro para comparar
 * \param descripcion[] char cadena que le asigno la descripcion de la estruc eTipo
 * \return int retorno 1 si esta todo Ok -1 si hubo un error 0 si hubo problema en la validacion
 *
 */
int cargarNombreCliente(eCliente clientes[], int tam, int idCliente, char descripcion[]);

/** \brief muestro la lista de clientes
 *
 * \param clientes[] eCliente estructura a mostrar
 * \param tam int tamaño de las filas
 * \param clear int limpia pantalla
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarClientes(eCliente clientes[], int tam, int clear);

/** \brief valida que el ID exista en la estructura
 *
 * \param id int  ID a validar
 * \param clientes[] eCliente estructura a recorrer
 * \param tam int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int validarClientes(int id, eCliente clientes[], int tam);
