#include <stdio.h>
#include <stdlib.h>
#include "propietario.h"
#include "automovil.h"
#define TAMP 20

int main()
{
    ePropietario propietario[TAMP];
    int opcion;
    int registro=-1;
    char seguir='s';
    int altaP=-1;
    int modiP;
    int bajaP;

    registro=inicializarPropietario(propietario,TAMP);
    altaP=inicializarPropietarioHardcode(propietario);

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
                break;
            case 6:
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
