#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "automovil.h"

int inicializarAutomovil(eAuto listaA[],int tamanioA)
{
    int i;
    int ret=-1;

    for(i=0; i<tamanioA; i++)
    {
        listaA[i].estado=0;
        ret=1;
    }

    return ret;
}

int mostrarAutomovil(eAuto listaA)
{
//    printf("\n%d %s %s %s %s\n",listaA.,listaP.nombre,listaP.apellido,listaP.tarjeta,listaP.direccion);
}

/*int mostrarListaDeAutomovil(eAuto listaA[], int tamanioA)
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
*/
