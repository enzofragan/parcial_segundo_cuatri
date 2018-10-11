#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED
#include "propietario.h"

typedef struct
{
    int IdAuto;
    int IdPropietario;
    char patente[8];
    char marcaNombre[10];
    int marca;
    int estado;
}eAuto;

#endif // AUTOMOVIL_H_INCLUDED

int inicializarAutomovil(eAuto [],int );
int inicializarAutomovilHardcode(eAuto []);
int mostrarListaDeAutomovil(eAuto [], int);
int mostrarAutomovil(eAuto );
int buscarLibreAutomovil(eAuto [],int );
int autoIdAutomovil(eAuto [],int );
int altaAutomovil(eAuto [],ePropietario [],int ,int );
int buscarIdAutomovil(eAuto [],int );
int esPatente(char []);
