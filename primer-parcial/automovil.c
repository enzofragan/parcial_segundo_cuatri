#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "automovil.h"
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

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

int inicializarAutomovilHardcode(eAuto listaA[])
{
    int id[5] = {10,11,12,13,14};
    int idPropietari[5] = {1,4,3,3,5};
    char patente[5][8] = {"abc-123","nfg-456","hij-789","alm-156","nop-357"};
    char marcaNombre[5][20] = {"ALPHA_ROMEO","AUDI","ALPHA_ROMEO","OTRO","AUDI"};
    int marca[5] = {1,3,1,4,3};
    int i;
    int ret=-1;

    for(i=0; i<5; i++)
    {
        listaA[i].IdAuto=id[i];
        listaA[i].IdPropietario=idPropietari[i];
        strcpy(listaA[i].patente,patente[i]);
        strcpy(listaA[i].marcaNombre,marcaNombre[i]);
        listaA[i].marca=marca[i];
        listaA[i].estado=1;
        ret=1;
    }

    return ret;
}

int buscarIdAutomovil(eAuto listaA[],int tamanioA)
{
    int i;
    int id;
    int ret=-1;

    printf("\ningrese el id del automovil ");
    id=getInt("\ningrese un id valido ");

    for(i=0; i<tamanioA; i++)
    {
        if(id>0 && listaA[i].IdAuto==id)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int mostrarAutomovil(eAuto listaA)
{
    printf("\n%d %s %d %s \n",listaA.IdAuto,listaA.marcaNombre,listaA.IdPropietario,listaA.patente);
}

int mostrarListaDeAutomovil(eAuto listaA[], int tamanioA)
{
    int i;
    for(i=0; i<tamanioA; i++)
    {
        if(listaA[i].estado==1)
        {
            mostrarAutomovil(listaA[i]);
        }
    }
}

int buscarLibreAutomovil(eAuto listaA[],int tamanioA)
{
    int i;
    int ret=-1;

    for(i=0; i<tamanioA; i++)
    {
        if(listaA[i].estado==0)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int autoIdAutomovil(eAuto listaA[],int tamanioA)
{
    int i;
    int id;

    i=buscarLibreAutomovil(listaA,tamanioA);

    id=i+10;

    return id;
}

int altaAutomovil(eAuto listaA[],ePropietario listaP[],int tamanioP,int tamanioA)
{
    int i;
    int ret=-1;
    int id;
    int idP;
    int marca;
    int opcion;
    char marcaN[10][10];
    char patente[8];

    i=buscarLibreAutomovil(listaA,tamanioA);

    if(i>=0)
    {
        id=autoIdAutomovil(listaA,tamanioA);

        mostrarListaDePropietario(listaP,tamanioP);

        idP=buscarIdPropietario(listaP,tamanioP);

        if(idP>=0)
        {
            printf("\nque marca es?\n");
            printf("1-ALPHA_ROMEO\n");
            printf("2-FERRARI\n");
            printf("3-AUDI\n");
            printf("4-OTRO\n");
            printf("5-salir\n");

            opcion=getInt("\ningrese una opcion valida ");

            while(opcion>5)
            {
                printf("\ningrese una opcion valida: ");
                opcion=getInt("\ningrese una opcion valida ");
            }

            switch(opcion)
            {
            case 1:
                marca=ALPHA_ROMEO;
                strcpy(marcaN,"ALPHA_ROMEO");
                break;
            case 2:
                marca=FERRARI;
                strcpy(marcaN,"FERRARI");
                break;
            case 3:
                marca=AUDI;
                strcpy(marcaN,"AUDI");
                break;
            case 4:
                marca=OTRO;
                strcpy(marcaN,"OTRO");
                break;
            }

            printf("\ningrese la patente abc-000 ");
            fflush(stdin);
            gets(patente);


            while(esPatente(patente)==-1)
            {
                printf("\ningrese una patente valida");
                fflush(stdin);
                gets(patente);
            }

            listaA[i].IdAuto=id;
            listaA[i].IdPropietario=listaP[idP].Id;
            strcpy(listaA[i].patente,patente);
            listaA[i].marca=marca;
            strcpy(listaA[i].marcaNombre,marcaN);
            listaA[i].estado=1;
            ret=1;

            mostrarListaDeAutomovil(listaA,tamanioA);
        }
        else
        {
            printf("id no encontrado\n");
        }
    }
    else
    {
        printf("no hay espacio\n");
    }

    return ret;
}

int esPatente(char cadena[])
{
    int largo;
    int i;
    int ret=1;

    largo=strlen(cadena);

    for(i=0; i<7; i++)
    {
        while(largo!=7)
        {
            ret=-1;
            break;
        }

        if(i<3)
        {
            if(cadena[i]==' '||cadena[i]=='\0'&& cadena[i]<'a'&& cadena[i]>'z')
            {
                ret=-1;
                break;
            }
        }
        else if(i==3)
        {
            if(cadena[i]!='-')
            {
                ret=-1;
                break;
            }
        }
        else if(i>=4 && i<7)
        {
            if(cadena[i]<'0'||cadena[i]>'9')
            {
                ret=-1;
                break;
            }
        }
    }

    return ret;
}
