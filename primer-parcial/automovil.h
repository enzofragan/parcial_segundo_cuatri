#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

typedef struct
{
    int IdPropietario;
    char patente[20];
    int marca;
    int estado;
}eAuto;

#endif // AUTOMOVIL_H_INCLUDED

int inicializarAutomovil(eAuto [],int );
int inicializarAutomovilHardcode(eAuto []);
int mostrarListaDeAutomovil(eAuto [], int);
int mostrarAutomovil(eAuto );
int buscarLibreAutomovil(eAuto [],int );
int altaAutomovil(eAuto [],int );
