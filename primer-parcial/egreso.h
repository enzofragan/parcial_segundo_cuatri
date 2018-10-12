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

/** \brief inicializa la lista de los autos egresados
 *
 * \param [] eEgresado lista de egresados
 * \param int cantidad de egresados
 * \return int retorna 1 si se logro iniciar la lista
 *
 */
int inicializarEgresado(eEgresado [],int );

/** \brief muestra la lista de todos los autos egresados
 *
 * \param [] eEgresado lista de egresados
 * \param int cantidad de egresados
 * \return int no retorna nada
 *
 */
int mostrarListaDeEgresado(eEgresado [], int);

/** \brief muestra un solo egresado
 *
 * \param eEgresado lista de egresados
 * \return intno retorna nada
 *
 */
int mostrarEgresado(eEgresado );

/** \brief busca un lugar libre en la lista de egresados
 *
 * \param [] eEgresado lista de egresados
 * \param intcantidad de egresados
 * \return int retorna la posicion libre en la lista
 *
 */
int buscarLibreEgresado(eEgresado [],int );

/** \brief id auto incremental de los egresados
 *
 * \param [] eEgresado lista de egresados
 * \param int cantidad de egresados
 * \return int retorna la id auto incrementada
 *
 */
int autoIdEgresado(eEgresado [],int );

/** \brief egreso del automovil si esta en la lista de autos y es el propietario de ese auto quien lo egresa
 *
 * \param [] eAuto lista de autos
 * \param [] ePropietario lista de propietarios
 * \param [] eEgresado lista de egresados
 * \param int cantidad de autos
 * \param int cantidad de propietarios
 * \param int cantidad de egresados
 * \return int retorna 1 si se logro egresar el auto
 *
 */
int egresarAutomovil(eAuto [],ePropietario [],eEgresado [],int,int,int );

/** \brief funcion pre definida por el profe
 *
 * \return int retornas horas
 *
 */
int devolverHorasEstadia();
