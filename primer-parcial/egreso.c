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
    char marcaNombre[5][20] = {"ALPHA_ROMEO","AUDI","ALPHA_ROMEO","OTRO","FERRARI"};
    int recaudacion[5] = {190,350,240,672,120};
    int i;
    int ret=-1;

    for(i=0; i<5; i++)
    {
        listaE[i].idEgreso=id[i];
        listaE[i].idAutomovil=idAuto[i];
        listaE[i].horas=horas[i];
        listaE[i].marca=marcas[i];
        strcpy(listaE[i].marcaNombre,marcaNombre[i]);
        listaE[i].recaudaciones=recaudacion[i];
        listaE[i].estado=1;
        ret=1;
    }

    return ret;
}

int mostrarEgresado(eEgresado listaE)
{
    printf("\n\n%d %d %s %d horas: %d recaudado: %d\n",listaE.idEgreso,listaE.idAutomovil,listaE.marcaNombre,listaE.marca,listaE.horas,listaE.recaudaciones);
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
    int precio;
    int ret=-1;
    char respuesta;

    mostrarListaDePropietario(listaP,tamanioP);

    idP=buscarIdPropietario(listaP,tamanioP);


    if(idP>=0)
    {
        mostrarListaDeAutomovil(listaA,tamanioA);

        idA=buscarIdAutomovil(listaA,tamanioA);

        if(idA>=0)
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

                respuesta=getChar("desea egresar este auto? s/n ","ingrese una opcion valida ");

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
                        strcpy(listaE[i].marcaNombre,listaA[idA].marcaNombre);
                        listaE[i].horas=horas;
                        listaE[i].recaudaciones=precio;
                        listaE[i].estado=1;
                        mostrarEgresado(listaE[i]);
                        mostrarRecaudaciones(listaE,tamanioE);
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
            printf("automovil no encontrado\n");
        }
    }
    else
    {
        printf("propietario no encontrado\n");
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
    int precio;
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

                    printf("\npropietario: %s\n",listaP[i].nombre);
                    printf("\npatente: %s\n",listaA[j].patente);
                    printf("\nmarca: %s\n",listaA[j].marcaNombre);
                    printf("\nhoras: %d\n",horas);
                    printf("\ntotal: %d\n",precio);

                    h=buscarLibreEgresado(listaE,tamanioE);

                    if(h>=0)
                    {
                        listaA[j].estado=0;
                        idE=autoIdEgresado(listaE,tamanioE);
                        listaE[h].idEgreso=idE;
                        listaE[h].idAutomovil=listaA[j].IdAuto;
                        listaE[h].marca=listaA[j].marca;
                        strcpy(listaE[h].marcaNombre,listaA[j].marcaNombre);
                        listaE[h].horas=horas;
                        listaE[h].recaudaciones=precio;
                        listaE[h].estado=1;
                        mostrarEgresado(listaE[h]);
                        mostrarRecaudaciones(listaE,tamanioE);
                        break;
                    }
                    else
                    {
                        printf("no hay espacio\n");
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
    int egresos=0;
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
    printf("\nrecaudacion total del estacionamiento: $%d\n",egresos);

    return ret;
}

int mostrarRecaudacionesPorMarca(eEgresado listaE[],int tamanioE)
{
    int alpha=0;
    int ferrari=0;
    int audi=0;
    int otro=0;
    int ret=-1;
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
    mostrarListaDeEgresado(listaE,tamanioE);
    printf("\n\nrecaudacion de la marca Alfa Romeo: $%d\n",alpha);
    printf("\nRecaudacion de la marca Ferrari: $%d\n",ferrari);
    printf("\nRecaudacion de la marca Audi: $%d\n",audi);
    printf("\nRecaudacion de otras marcas: $%d\n\n",otro);
    ret=1;

    return ret;
}

int mostrarPropietariosConSusAutomoviles(ePropietario listaP[],eAuto listaA[],int tamanioP,int tamanioA)
{
        int IdPropietario;
        int indice;
        int i;
        int ret=-1;
        mostrarListaDePropietario(listaP,tamanioP);
        indice=buscarIdPropietario(listaP,tamanioP);

        if(indice!=-1)
        {
            printf("\npropietario: %s\n",listaP[indice].nombre);
            for(i=0; i<tamanioA; i++)
            {
                if(listaP[indice].Id==listaA[i].IdPropietario)
                {
                    printf("\nmarca: %s",listaA[i].marcaNombre);
                    printf("\npatente: %s\n\n",listaA[i].patente);
                    ret=1;
                }
            }
        }
        else
        {
            printf("\npropietario no encontrado\n");
        }

    return ret;
}

int mostrarPropietarioAudi(ePropietario listaP[],eAuto listaA[],int tamanioP,int tamanioA)
{
        int i;
        int j;
        int flag=0;
        int ret=-1;
        for(i=0; i<tamanioA; i++)
        {
            if(listaA[i].estado==1 && listaA[i].marca==3)
            {
                for(j=0; j<tamanioP; j++)
                {
                    if(listaA[i].IdPropietario==listaP[j].Id && listaP[j].estado==1)
                    {
                        flag=flag+1;
                        printf("\nid: %d\nnombre: %s\ntarjeta de credito: %s\ndireccion: %s\n\n",listaP[j].Id,listaP[j].nombre,listaP[j].tarjeta,listaP[j].direccion);
                        ret=1;
                        break;
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("\nNo hay propietarios que tengan estacionado un coche marca AUDI");
        }
    return ret;
}

int mostrarAutosPorPatente(ePropietario listaP[],eAuto listaA[],int tamanioP,int tamanioA)
{
        eAuto aux;
        int largo;
        int i;
        int j;
        int ret=-1;
        for(i=0; i<tamanioA-1; i++)
        {
            for(j=i+1; j<tamanioA; j++)
            {
                if(strcmp(listaA[i].patente,listaA[j].patente)>0)
                {
                    aux=listaA[i];
                    listaA[i]=listaA[j];
                    listaA[j]=aux;
                }
            }
        }
        for(i=0; i<tamanioA; i++)
        {
            if(listaA[i].estado==1)
            {
                for(j=0; j<tamanioP; j++)
                {
                    if(listaA[i].IdPropietario==listaP[j].Id && listaP[j].estado==1)
                    {
                        printf("\nid: %d\npatente: %s\nmarca: %s\npropietario: %s\nid propietario: %d\n\n",listaA[i].IdAuto,listaA[i].patente,listaA[i].marcaNombre,listaP[j].nombre,listaP[j].Id);
                        ret=1;
                        break;
                    }
                }
            }
        }
    return ret;
}
