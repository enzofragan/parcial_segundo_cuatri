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

int inicializarEgresadoHardcode(eEgresado listaE[])
{
    int id[5] = {100,101,102,103,104};
    int idAuto[5] = {10,14,11,10,13};
    int horas[5] = {5,9,8,6,2};
    int marcas[5] = {1,3,1,4,2};
    float recaudacion[5] = {190.00,350.20,240.25,672.50,120.10};
    int i;
    int ret=-1;

    for(i=0; i<5; i++)
    {
        listaE[i].idEgreso=id[i];
        listaE[i].idAutomovil=idAuto[i];
        listaE[i].horas=horas[i];
        listaE[i].marca=marcas[i];
        listaE[i].recaudaciones=recaudacion[i];
        listaE[i].estado=1;
        ret=1;
    }

    return ret;
}

int mostrarEgresado(eEgresado listaE)
{
    printf("\n%d %d %d %d %.2f\n",listaE.idEgreso,listaE.idAutomovil,listaE.marca,listaE.horas,listaE.recaudaciones);
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

    i=buscarLibreEgresado(listaE,tamanioE);

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
    float precio;
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
                    precio=(float)horas*150;
                    break;
                case 2:
                    precio=(float)horas*175;
                    break;
                case 3:
                    precio=(float)horas*200;
                    break;
                case 4:
                    precio=(float)horas*250;
                    break;
                }
                printf("\npropietario: %s\n",listaP[idP].nombre);
                printf("\npatente: %s\n",listaA[idA].patente);
                printf("\nmarca: %s\n",listaA[idA].marcaNombre);
                printf("\nhoras: %d\n",horas);
                printf("\ntotal: %.2f\n\n",precio);

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
                        listaE[i].recaudaciones=precio;
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

int bajaPropietario(ePropietario listaP[],eAuto listaA[],eEgresado listaE[],int tamanioP,int tamanioA,int tamanioE)
{
    int i;
    int j;
    int h;
    float precio;
    int idE;
    char respuesta;
    int horas;
    int marca;
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
            for(j=0; j<tamanioA; j++)
            {
                while(listaA[j].IdPropietario==listaP[i].Id)
                {

                    horas=devolverHorasEstadia();
                    marca=listaA[j].marca;

                    switch(marca)
                    {
                    case 1:
                        precio=(float)horas*150;
                        break;
                    case 2:
                        precio=(float)horas*175;
                        break;
                    case 3:
                        precio=(float)horas*200;
                        break;
                    case 4:
                        precio=(float)horas*250;
                        break;
                    }

                    printf("\npropietario: %s\n",listaP[i].nombre);
                    printf("\npatente: %s\n",listaA[j].patente);
                    printf("\nmarca: %s\n",listaA[j].marcaNombre);
                    printf("\nhoras: %d\n",horas);
                    printf("\ntotal: %.2f\n\n",precio);

                    respuesta=getChar("desea modificar este propietario? s/n ","ingrese una opcion valida ");

                    while(respuesta!='s' && respuesta!='n')
                    {
                        respuesta=getChar("ingrese una opcion valida ","ingrese una opcion valida ");
                    }

                    if(respuesta=='s')
                    {
                        h=buscarLibreEgresado(listaE,tamanioE);

                        if(h>=0)
                        {
                            listaA[j].estado=0;
                            idE=autoIdEgresado(listaE,tamanioE);
                            listaE[h].idEgreso=idE;
                            listaE[h].idAutomovil=listaA[j].IdAuto;
                            listaE[h].marca=listaA[j].marca;
                            listaE[h].horas=horas;
                            listaE[h].recaudaciones=precio;
                            listaE[h].estado=1;
                            mostrarEgresado(listaE[h]);
                            break;
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
            }
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

int mostrarRecaudaciones(eEgresado listaE[],int tamanioE)
{
    float egresos=0;
    int i;
    int ret=-1;
    for(i=0; i<tamanioE; i++)
    {
        if(listaE[i].estado==1)
        {
            egresos=egresos+listaE[i].recaudaciones;
            if(egresos>0)
            {
                ret=1;
            }
        }
    }
    printf("\nrecaudacion total del estacionamiento: $%.2f\n",egresos);
}

int mostrarRecaudacionesPorMarca(eEgresado listaE[],int tamanioE)
{
    float alpha=0;
    float ferrari=0;
    float audi=0;
    float otro=0;
    int i;
    for(i=0; i<tamanioE; i++)
    {
        if(listaE[i].estado==1)
        {
            if(listaE[i].marca==1)
            {
                alpha=alpha+listaE[i].recaudaciones;
            }
            else if(listaE[i].marca==2)
            {
                ferrari=ferrari+listaE[i].recaudaciones;
            }
            else if(listaE[i].marca==3)
            {
                audi=audi+listaE[i].recaudaciones;
            }
            else
            {
                otro=otro+listaE[i].recaudaciones;
            }
        }
    }
    printf("\n\nrecaudacion de la marca Alfa Romeo: $%.2f\n",alpha);
    printf("\nRecaudacion de la marca Ferrari: $%.2f\n",ferrari);
    printf("\nRecaudacion de la marca Audi: $%.2f\n",audi);
    printf("\nRecaudacion de otras marcas: $%.2f\n\n",otro);
}
