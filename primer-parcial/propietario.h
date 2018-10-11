#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

typedef struct
{
    int Id;
    char nombre[20];
    char tarjeta[20];
    char direccion[20];
    char apellido[20];
    int estado;
} ePropietario;

#endif // PROPIETARIO_H_INCLUDED

int inicializarPropietario(ePropietario [],int );
int inicializarPropietarioHardcode(ePropietario []);
int menu();
int getInt(char []);
char getString(char [],char [],char []);
float getDec(char [],char []);
char getChar(char [],char []);
int esNumerica(char* );
int esLetra(char* );
int esDecimal(char* );
int esDomicilio(char* );
int esTarjeta(char* );
int mostrarListaDePropietario(ePropietario[], int);
int mostrarPropietario(ePropietario );
int buscarLibrePropietario(ePropietario [],int );
int autoIdPropietario(ePropietario [],int );
int altaPropietario(ePropietario [],int );
int buscarIdPropietario(ePropietario [],int );
int modificacionPropietario(ePropietario [],int );
int bajaPropietario(ePropietario [],int );
int mostrarOrdenPropietario(ePropietario [],int );
