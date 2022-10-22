
#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

#endif // TIPO_H_INCLUDED

int cargarNombreTipo(eTipo tipos[], int tam, int idTipos, char descripcion[]);

int mostrarTipos(eTipo tipos[], int tam);

int validarTipo(int id, eTipo tipos[],int tam);
