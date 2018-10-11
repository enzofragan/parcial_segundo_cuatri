#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "egreso.h"

int inicializarEgresado(eEgresado listaE[],int tamanioE)
{
    int i;
    int ret=-1;

    for(i=0; i<tamanioE; i++)
    {
        listaE[i].estado=0;
        ret=1;
    }

    return ret;
}

int mostrarEgresado(eEgresado listaE)
{
    printf("\n%d %d %d %d \n",listaE.idEgreso,listaE.idAutomovil,listaE.marca,listaE.horas);
}

int mostrarListaDeEgresado(eEgresado listaE[],int tamanioE)
{
    int i;
    for(i=0; i<tamanioE; i++)
    {
        if(listaE[i].estado==1)
        {
            mostrarEgresado(listaE[i]);
        }
    }
}

int buscarLibreEgresado(eEgresado listaE[],int tamanioE)
{
    int i;
    int ret=-1;

    for(i=0; i<tamanioE; i++)
    {
        if(listaE[i].estado==0)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int autoIdEgresado(eEgresado listaE[],int tamanioE)
{
    int i;
    int id;

    i=buscarLibreAutomovil(listaE,tamanioE);

    id=i+100;

    return id;
}

int egresarAutomovil(eAuto listaA[],ePropietario listaP[],eEgresado listaE[],int tamanioA,int tamanioP,int tamanioE)
{
    int i;
    int idE;
    int idA;
    int idP;
    int horas;
    int marca;
    int precio;
    int ret=-1;
    char respuesta;

    mostrarListaDeAutomovil(listaA,tamanioA);

    idA=buscarIdAutomovil(listaA,tamanioA);

    mostrarListaDePropietario(listaP,tamanioP);

    idP=buscarIdPropietario(listaP,tamanioP);

    if(idA>=0)
    {
        if(idP>=0)
        {
            if(listaA[idA].IdPropietario==listaP[idP].Id)
            {
                horas=devolverHorasEstadia();
                marca=listaA[idA].marca;

                switch(marca)
                {
                case 1:
                    precio=horas*150;
                    break;
                case 2:
                    precio=horas*175;
                    break;
                case 3:
                    precio=horas*200;
                    break;
                case 4:
                    precio=horas*250;
                    break;
                }
                printf("\npropietario: %s\n",listaP[idP].nombre);
                printf("\npatente: %s\n",listaA[idA].patente);
                printf("\nmarca: %s\n",listaA[idA].marcaNombre);
                printf("\nhoras: %d\n",horas);
                printf("\ntotal: %d\n\n",precio);

                respuesta=getChar("desea modificar este propietario? s/n ","ingrese una opcion valida ");

                while(respuesta!='s' && respuesta!='n')
                {
                    respuesta=getChar("ingrese una opcion valida ","ingrese una opcion valida ");
                }

                if(respuesta=='s')
                {
                    i=buscarLibreEgresado(listaE,tamanioE);

                    if(i>=0)
                    {
                        listaA[idA].estado=0;
                        idE=autoIdEgresado(listaE,tamanioE);
                        listaE[i].idEgreso=idE;
                        listaE[i].idAutomovil=listaA[idA].IdAuto;
                        listaE[i].marca=listaA[idA].marca;
                        listaE[i].horas=horas;
                        listaE[i].estado=1;
                        ret=1;
                    }
                    else
                    {
                        printf("no hay espacio\n");
                    }
                }
                else
                {
                    ret=0;
                }
            }
            else
            {
                printf("no es el propietario de ese auto\n");
            }
        }
        else
        {
            printf("propietario no encontrado\n");
        }
    }
    else
    {
        printf("automovil no encontrado\n");
    }

    return ret;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}
