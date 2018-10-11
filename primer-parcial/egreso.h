#ifndef EGRESO_H_INCLUDED
#define EGRESO_H_INCLUDED
#include "propietario.h"
#include "automovil.h"


typedef struct
{
    int idEgreso;
    int idAutomovil;
    int horas;
    int marca;
    int estado;
} eEgresado;

#endif // EGRESO_H_INCLUDED

int inicializarEgresado(eEgresado [],int );
int mostrarListaDeEgresado(eEgresado [], int);
int mostrarEgresado(eEgresado );
int buscarLibreEgresado(eEgresado [],int );
int autoIdEgresado(eEgresado [],int );
int egresarAutomovil(eAuto [],ePropietario [],eEgresado [],int,int,int );
int devolverHorasEstadia();
