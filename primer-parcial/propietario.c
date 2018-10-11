#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "propietario.h"

int inicializarPropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    int ret=-1;

    for(i=0; i<tamanioP; i++)
    {
        listaP[i].estado=0;
        ret=1;
    }

    return ret;
}

int inicializarPropietarioHardcode(ePropietario listaP[])
{
    int id[5] = {1,2,3,4,5};
    char nombre[5][20] = {"enzo","luis","maria","ana","pedro"};
    char apellido[5][20] = {"fragan","mario","santos","clemente","mario"};
    char tarjeta[5][20] = {"1234567891234567","7891238912345678","4567899123456789","1597531234567891","8624123456789123"};
    char direccion[5][20] = {"mitre 345","belgrano 487","mitre 357","mitre 267","belgrano 347"};
    int i;
    int ret=-1;

    for(i=0; i<5; i++)
    {
        listaP[i].Id=id[i];
        strcpy(listaP[i].nombre,nombre[i]);
        strcpy(listaP[i].apellido,apellido[i]);
        strcpy(listaP[i].tarjeta,tarjeta[i]);
        strcpy(listaP[i].direccion,direccion[i]);
        listaP[i].estado=1;
        ret=1;
    }

    return ret;
}

int menu()
{
    int opcion;

    printf("1- alta propietario\n");
    printf("2- modificacion propietario\n");
    printf("3- baja propietario\n");
    printf("4- listar\n");
    printf("5- listar por nombre y apellido\n");
    printf("6- salir\n");

    opcion=getInt("ingrese una opcion valida ");

    while(opcion>6)
    {
        printf("ingrese una opcion valida ");
        opcion=getInt("ingrese una opcion valida ");
    }

    return opcion;
}

/** \brief el get para los numeros enteros, el proceso es el mismo que en de decimal y si es un numero pasa el buffer a int
 *
 * \param error[] char se le pasa el mensaje de error en caso de que la validacion falle
 * \return int si es un numero primero pasa la cadena a int y luego lo retorna
 *
 */
int getInt(char error[])
{
    int aux;
    char buffer[64];
    scanf("%s",buffer);
    while(esNumerica(buffer)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%s",buffer);
    }
    aux = atoi(buffer);
    return aux;
}

/** \brief get para cadena de caracteres, el proceso es el mismo que los demas, con la diferencia de que se le pasa la variable por parametro
 *
 * \param mensaje[] char mensaje a imprimir
 * \param error[] char mensaje de error
 * \param caracter[] char varible que guarda lo que se quiera ingrasar y luego se valida
 * \return char retorna lo ingresado
 *
 */
char getString(char mensaje[],char error[],char caracter[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(caracter);

    while(esLetra(caracter)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        gets(caracter);
    }

    return caracter;
}

/** \brief obtiene el decimal a ingresar y lo pasa a string y lo valida
 *
 * \param mensaje[] char se le pasa el mensaje a utilizar
 * \param error[] char y el mensaje de error en caso de que la validacion falle
 * \return float retorna el numero pasado de string a float
 *
 */
float getDec(char mensaje[],char error[])
{
    float aux;
    char buffer[64];
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",buffer);
    while(esDecimal(buffer)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%s",buffer);
    }

    aux = atof(buffer);

    return aux;
}

/** \brief el get para los caracteres y es el mismo proceso que los otros dos
 *
 * \param mensaje[] char se le pasa el mensaje a utilizar
 * \param error[] char y el mensaje de error por si la validacion falla
 * \return char si es un char pasa el buffer a un auxiliar y lo retorna
 *
 */
char getChar(char mensaje[],char error[])
{
    char auxiliar;
    char buffer;
    printf("%s",mensaje);
    fflush(stdin);
    buffer=getche();
    while(!(isalpha(buffer)))
    {
        printf("%s",error);
        fflush(stdin);
        buffer=getche();
    }
    auxiliar=buffer;
    return auxiliar;
}

/** \brief validacion para saber si el numero es decimal o si es un numero o letra
 *
 * \param cadena char* se el pasa el puntero a la cadena pasada en el get y lo recorre para verificar que se un numero o sea un numero decimal
 * \return int retorna -1 si es una letra y 1 si es un numero
 *
 */
int esDecimal(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])) && cadena[i]!='.')
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

/** \brief validacion para los numeros enteros
 *
 * \param cadena char* se le pasa la cadena del get y la recorre
 * \return int devuelve -1 si es una letra y 1 si es un numero
 *
 */
int esNumerica(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])))
            {
                return -1;
            }///para validar numero
            i++;
        }
    }
    return 1;
}

/** \brief validacion para las letras
 *
 * \param cadena char* se le pasa la cadena del get, para que la recorra
 * \return int retorna -1 si es un numero y 1 si es una letra
 *
 */
int esLetra(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isalpha(cadena[i])))
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

int esDomicilio(char* cadena)
{
    int i=0;
    int ret=-1;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(isalpha(cadena[i]))
            {
                i++;
            }
            else if(isspace(cadena[i]))
            {
                i++;
            }
            else if(isdigit(cadena[i]))
            {
                i++;
                ret=1;
            }
        }
    }
    return ret;
}

int esFecha(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])) && cadena[i]!='/')
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

int esTarjeta(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])) || i>=16)
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

int mostrarPropietario(ePropietario listaP)
{
    printf("\n%d %s %s %s %s\n",listaP.Id,listaP.nombre,listaP.apellido,listaP.tarjeta,listaP.direccion);
}

int mostrarListaDePropietario(ePropietario listaP[], int tamanioP)
{
    int i;
    for(i=0; i<tamanioP; i++)
    {
        if(listaP[i].estado==1)
        {
            mostrarPropietario(listaP[i]);
        }
    }
}

int buscarLibrePropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    int ret=-1;

    for(i=0; i<tamanioP; i++)
    {
        if(listaP[i].estado==0)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int autoIdPropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    int id;

    i=buscarLibrePropietario(listaP,tamanioP);

    id=i+1;

    return id;
}

int altaPropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    int id;
    int ret=-1;
    int repN;
    int repA;
    char nombre[20];
    char apellido[20];
    char tarjeta[20];
    char domicilio[20];


    i=buscarLibrePropietario(listaP,tamanioP);

    if(i>=0)
    {
        id=autoIdPropietario(listaP,tamanioP);

        getString("ingrese su nombre ","ingrese una nombre valido ",nombre);

        getString("ingrese su apellido ","ingrese un apellido valido ",apellido);

        printf("ingrese su numero de tarjeta ");
        fflush(stdin);
        gets(tarjeta);

        while(esTarjeta(tarjeta)==-1)
        {
            printf("ingrese un numero de tarjeta valido ");
            fflush(stdin);
            gets(tarjeta);
        }

        printf("\ningrese su direccion ");
        fflush(stdin);
        gets(domicilio);

        while(esDomicilio(domicilio)==-1)
        {
            printf("\ningrese una direccion valida ");
            fflush(stdin);
            gets(domicilio);
        }

        listaP[i].Id=id;
        strcpy(listaP[i].nombre,nombre);
        strcpy(listaP[i].apellido,apellido);
        strcpy(listaP[i].tarjeta,tarjeta);
        strcpy(listaP[i].direccion,domicilio);
        listaP[i].estado=1;
        ret=1;

        mostrarPropietario(listaP[i]);
    }
    else
    {
        printf("no hay mas espacio\n");
    }

    return ret;
}

int buscarIdPropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    int id;
    int ret=-1;

    printf("ingrese el id del propietario ");
    id=getInt("ingrese un id valido ");

    for(i=0; i<tamanioP; i++)
    {
        if(id>0 && listaP[i].Id==id)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int modificacionPropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    int opcion;
    int repN=-1;
    int repA=-1;
    char nombre[20];
    char apellido[20];
    char tarjeta[20];
    char domicilio[20];
    char respuesta;
    int ret=-1;

    mostrarListaDePropietario(listaP,tamanioP);

    i=buscarIdPropietario(listaP,tamanioP);

    if(i>=0)
    {
        mostrarPropietario(listaP[i]);

        printf("ingrese nuevo numero de tarjeta ");
        fflush(stdin);
        gets(tarjeta);

        while(esTarjeta(tarjeta)==-1)
        {
            printf("ingrese un numero de tarjeta valido ");
            fflush(stdin);
            gets(tarjeta);
        }

        respuesta=getChar("desea modificar este propietario? s/n ","ingrese una opcion valida ");

        while(respuesta!='s' && respuesta!='n')
        {
            respuesta=getChar("ingrese una opcion valida ","ingrese una opcion valida ");
        }

        if(respuesta=='s')
        {
           strcpy(listaP[i].tarjeta,tarjeta);
            ret=1;
            mostrarPropietario(listaP[i]);
        }
        else
        {
            ret=0;
        }
    }
    else
    {
        printf("\nid no encontrado\n\n");
    }

    return ret;
}

int bajaPropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    char respuesta;
    int ret=-1;

    mostrarListaDePropietario(listaP,tamanioP);

    i=buscarIdPropietario(listaP,tamanioP);

    if(i>=0)
    {
        mostrarPropietario(listaP[i]);

        respuesta=getChar("desea eliminar este propietario? s/n ","ingrese una opcion valida ");

        while(respuesta!='s' && respuesta!='n')
        {
            respuesta=getChar("ingrese una opcion valida ","ingrese una opcion valida ");
        }

        if(respuesta=='s')
        {
            listaP[i].estado=0;
            listaP[i].Id=0;
            strcpy(listaP[i].nombre,"");
            strcpy(listaP[i].apellido,"");
            strcpy(listaP[i].tarjeta,"");
            strcpy(listaP[i].direccion,"");
            ret=1;
        }
        else
        {
            ret=0;
        }

    }
    else
    {
        printf("\nid no encontrado\n\n");
    }

    return ret;
}

int mostrarOrdenPropietario(ePropietario listaP[],int tamanioP)
{
    int i;
    int j;
    int ret=-1;
    ePropietario aux;

    for(i=0;i<tamanioP-1;i++)
    {
        for(j=i+1;j<tamanioP;j++)
        {
            if(listaP[i].estado==1 && listaP[j].estado==1)
            {
                if(strcmp(listaP[i].nombre,listaP[j].nombre)<0)
                {
                    aux=listaP[i];
                    listaP[i]=listaP[j];
                    listaP[j]=aux;
                    ret=1;
                }
                if(strcmp(listaP[i].apellido,listaP[j].apellido)<0)
                {
                    aux=listaP[i];
                    listaP[i]=listaP[j];
                    listaP[j]=aux;
                }
            }
        }
    }

    mostrarListaDePropietario(listaP,tamanioP);

    return ret;
}
