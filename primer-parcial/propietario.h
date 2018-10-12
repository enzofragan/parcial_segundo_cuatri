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

/** \brief inicialixa la lista de propietarios
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int retorna 1 si logro inicializarla
 *
 */
int inicializarPropietario(ePropietario [],int );

/** \brief inicialixa la lista de propietarios con datos pre cargados
 *
 * \param [] ePropietario lista de propietarios
 * \return int retorna 1 si logro cargarlos
 *
 */
int inicializarPropietarioHardcode(ePropietario []);

/** \brief menu principal del programa, con 7 opciones
 *
 * \return int retorna la opcion elejida
 *
 */
int menu();

/** \brief el get para los numeros enteros, el proceso es el mismo que en de decimal y si es un numero pasa el buffer a int
 *
 * \param error[] char se le pasa el mensaje de error en caso de que la validacion falle
 * \return int si es un numero primero pasa la cadena a int y luego lo retorna
 *
 */
int getInt(char []);

/** \brief get para cadena de caracteres, el proceso es el mismo que los demas, con la diferencia de que se le pasa la variable por parametro
 *
 * \param mensaje[] char mensaje a imprimir
 * \param error[] char mensaje de error
 * \param caracter[] char varible que guarda lo que se quiera ingrasar y luego se valida
 * \return char retorna lo ingresado
 *
 */
char getString(char [],char [],char []);

/** \brief obtiene el decimal a ingresar y lo pasa a string y lo valida
 *
 * \param mensaje[] char se le pasa el mensaje a utilizar
 * \param error[] char y el mensaje de error en caso de que la validacion falle
 * \return float retorna el numero pasado de string a float
 *
 */
float getDec(char [],char []);

/** \brief el get para los caracteres y es el mismo proceso que los otros dos
 *
 * \param mensaje[] char se le pasa el mensaje a utilizar
 * \param error[] char y el mensaje de error por si la validacion falla
 * \return char si es un char pasa el buffer a un auxiliar y lo retorna
 *
 */
char getChar(char [],char []);


/** \brief validacion para los numeros enteros
 *
 * \param cadena char* se le pasa la cadena del get y la recorre
 * \return int devuelve -1 si es una letra y 1 si es un numero
 *
 */
int esNumerica(char* );

/** \brief validacion para las letras
 *
 * \param cadena char* se le pasa la cadena del get, para que la recorra
 * \return int retorna -1 si es un numero y 1 si es una letra
 *
 */
int esLetra(char* );

/** \brief validacion para saber si el numero es decimal o si es un numero o letra
 *
 * \param cadena char* se el pasa el puntero a la cadena pasada en el get y lo recorre para verificar que se un numero o sea un numero decimal
 * \return int retorna -1 si es una letra y 1 si es un numero
 *
 */
int esDecimal(char* );


/** \brief valida que se esta pasando un direccion con nombre de calle y altura
 *
 * \param char* cadea a validar
 * \return int retorna -1 si no es una direccion
 *
 */
int esDomicilio(char* );


/** \brief valida que lo que se le pasa es una tarjeta con maximo de 16 digitos
 *
 * \param char* cadena a validar
 * \return int retorna -1 si no es un numero de tarjeta
 *
 */
int esTarjeta(char* );

/** \brief muestra la lista de los propietarios
 *
 * \param ePropietario[] lista de propietarios
 * \param int cantidad de propietarios
 * \return int no retorna en realidad nada
 *
 */
int mostrarListaDePropietario(ePropietario[], int);

/** \brief mustra un propietario
 *
 * \param ePropietario lista de propietarios
 * \return int no retorna nada enrialidad
 *
 */
int mostrarPropietario(ePropietario );

/** \brief busca un lugar libre en la lista de propietario
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int retorna la posicion de de la lista libre
 *
 */
int buscarLibrePropietario(ePropietario [],int );

/** \brief id auto incremental de los propietarios
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int retorna el id auto incrementado
 *
 */
int autoIdPropietario(ePropietario [],int );

/** \brief alta de un propietario con todas las validaciones
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int retorna 1 si se logro dar de alta un propietario
 *
 */
int altaPropietario(ePropietario [],int );

/** \brief busca al propietario por medio de la id que se pide dentro de la funcion
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int retorna la posicion de la id buscada
 *
 */
int buscarIdPropietario(ePropietario [],int );

/** \brief modificacion de los propietarios, modifica la tarjeta unicamente y pregunta si quiere modificarlo
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int retorna 1 si se logro modificar
 *
 */
int modificacionPropietario(ePropietario [],int );

/** \brief baja de propietarios, realiza baja fisica
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int retorna 1 si se logro dar de baja
 *
 */
int bajaPropietario(ePropietario [],int );

/** \brief ordena por nombre y apellido la lista de propietarios
 *
 * \param [] ePropietario lista de propietarios
 * \param int cantidad de propietarios
 * \return int no retorna nada enrealidad
 *
 */
int mostrarOrdenPropietario(ePropietario [],int );
