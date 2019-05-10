#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "arrayEmployees.h"

#define MAXIMO 1001

int main()
{
    char continuar='s';
    eEmployee empleado[MAXIMO];
    inicializarEmployees(empleado,MAXIMO);
    int flagParaNoEntrar=0;


    do
    {
        switch(funcionOpciones())
        {
        case 1:
            addEmpleado(empleado,MAXIMO);
            flagParaNoEntrar++;
            break;
        case 2:
            if(flagParaNoEntrar==0)
            {
                printf("ERROR, NO SE CARGARON EMPLEADOS EN EL SISTEMA!!!");
                break;
            }
            else
            {
                modificarEmpleado(empleado,MAXIMO);

            }
            break;
        case 3:
            if(flagParaNoEntrar==0)
            {
                printf("ERROR, NO SE CARGARON EMPLEADOS EN EL SISTEMA!!!");
                break;
            }
            else
            {
                removeEmpleado(empleado,MAXIMO);
            }
            break;
        case 4:
            if(flagParaNoEntrar==0)
            {
                printf("ERROR, NO SE CARGARON EMPLEADOS EN EL SISTEMA!!!");
                break;
            }
            else
            {
                sortEmployees(empleado,MAXIMO);
                //reports(empleado,MAXIMO);
                viewEmpleados(empleado,MAXIMO);
            }
            break;
        case 5:
            printf("SALIENDO...");
            exit(-1);
            break;
        default:
            printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
            system("pause");
            break;
        }
        printf("\n Desea continuar? si/no \n\n");
        scanf("%c",&continuar);

        fflush(stdin);
        system("cls");


    }while (continuar == 's' || continuar == 'S');


    printf("Saliendo perro!");
}
