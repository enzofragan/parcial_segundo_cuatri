#include <stdio.h>
#include <stdlib.h>
#include "egreso.h"
#define TAMP 100
#define TAMA 20
#define TAME 100

int main()
{
    ePropietario propietario[TAMP];
    eAuto automovil[TAMA];
    eEgresado egrecion[TAME];
    int opcion;
    int registro=-1;
    int estacionamiento=-1;
    int egreso=-1;
    char seguir='s';
    int altaP=-1;
    int modiP;
    int bajaP;
    int altaA=-1;
    int bajaE=-1;

    registro=inicializarPropietario(propietario,TAMP);
    altaP=inicializarPropietarioHardcode(propietario);

    estacionamiento=inicializarAutomovil(automovil,TAMA);
    altaA=inicializarAutomovilHardcode(automovil);

    egreso=inicializarEgresado(egrecion,TAME);

    if(registro>0)
    {
        do
        {
            opcion=menu();

            switch(opcion)
            {
            case 1:
                altaP=altaPropietario(propietario,TAMP);
                if(altaP>0)
                {
                    printf("\nalta completa\n\n");
                    altaP=1;
                }
                else
                {
                    printf("\naccion cancelada\n\n");
                    altaP=1;
                }
                break;
            case 2:
                if(altaP>0)
                {
                    modiP=modificacionPropietario(propietario,TAMP);
                    if(modiP>0)
                    {
                        printf("\nmodificacion completa\n\n");
                    }
                    else
                    {
                        printf("\naccion cancelada\n\n");
                    }
                }
                else
                {
                    printf("\ningrese un propietario primero\n\n");
                }
                break;
            case 3:
                if(altaP>0)
                {
                    bajaP=bajaPropietario(propietario,TAMP);
                    if(bajaP>0)
                    {
                        printf("\nbaja completa\n\n");
                    }
                    else
                    {
                        printf("\naccion cancelada\n\n");
                    }
                }
                else
                {
                    printf("\ningrese un propietario primero\n\n");
                }
                break;
            case 4:
                if(altaP>0)
                {
                    mostrarOrdenPropietario(propietario,TAMP);
                }
                else
                {
                    printf("\ningrese un propietario primero\n\n");
                }
                break;
            case 5:
                if(altaP>0 && estacionamiento>0)
                {
                    altaA=altaAutomovil(automovil,propietario,TAMP,TAMA);
                    if(altaA>0)
                    {
                        printf("\nauto estacionado\n\n");
                        altaA=1;
                    }
                    else
                    {
                        printf("\naccion cancelada\n\n");
                        altaA=1;
                    }
                }
                else
                {
                    printf("\ninicie una lista y ingrese un propietario primero\n\n");
                }
                break;
            case 6:
                if(altaA>0)
                {
                    mostrarListaDeAutomovil(automovil,TAMA);
                }
                else
                {
                    printf("\ninicie una lista primero\n\n");
                }
                break;
            case 7:
                if(altaP>0 && altaA>0 && egreso>0)
                {
                    bajaE=egresarAutomovil(automovil,propietario,egrecion,TAMA,TAMP,TAME);
                    if(bajaE>0)
                    {
                        printf("\negreso completo\n\n");
                    }
                    else
                    {
                        printf("\naccion cancelada\n\n");
                    }
                }
                else
                {
                    printf("\ninicie las listar y ingrese datos primero\n\n");
                }
                break;
            case 8:
                if(bajaE>0)
                {
                    mostrarListaDeEgresado(egrecion,TAME);
                }
                else
                {
                    printf("\ninicie una lista primero\n\n");
                }
                break;
            case 9:
                seguir='n';
                break;
            }

        }
        while(seguir=='s');
    }
    else
    {
        printf("inicie la lista primero");
    }
    return 0;
}
