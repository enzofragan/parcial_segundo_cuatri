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

/** \brief inicializa la lista de autos
 *
 * \param [] eAuto lista de autos
 * \param int cantidad de autos
 * \return int retorna 1 si se logro iniciar la lista
 *
 */
int inicializarAutomovil(eAuto [],int );

/** \brief inicializa la lista de autos con datos pre cargados
 *
 * \param [] eAuto lista de autos
 * \return int retorna 1 si se logro cargar los datos
 *
 */
int inicializarAutomovilHardcode(eAuto []);

/** \brief muestra la lista de autos
 *
 * \param [] eAuto lista de autos
 * \param int cantidad de auntos
 * \return int no retorna nada
 *
 */
int mostrarListaDeAutomovil(eAuto [], int);

/** \brief muestra un solo auto
 *
 * \param eAuto lista de autos
 * \return int no retorna nada
 *
 */
int mostrarAutomovil(eAuto );

/** \brief busca un lugar libre en la lista de autos
 *
 * \param [] eAuto lista de autos
 * \param int cantidad de autos
 * \return int retorna la posicion libre de la lista
 *
 */
int buscarLibreAutomovil(eAuto [],int );

/** \brief id auto incremental de los autos
 *
 * \param [] eAuto lista de autos
 * \param int cantidad de autos
 * \return int retorna la id auto incrementada
 *
 */
int autoIdAutomovil(eAuto [],int );

/** \brief alta de un auto con la id de su propietario
 *
 * \param [] eAuto lista de autos
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \param int cantidad de autos
 * \return int retorna 1 si se logro dar de alta
 *
 */
int altaAutomovil(eAuto [],ePropietario [],int ,int );

/** \brief busca por id el automovil,el id se pide dentro de la funcion
 *
 * \param [] eAuto lista de autos
 * \param int cantidad de autos
 * \return int retorna la posicion de la id del auto a buscar
 *
 */
int buscarIdAutomovil(eAuto [],int );

/** \brief validacion para la patente de un auto con letras, un gion y numeros
 *
 * \param [] char cadena a validar
 * \return int retorna -1 si la validacion falla
 *
 */
int esPatente(char []);
