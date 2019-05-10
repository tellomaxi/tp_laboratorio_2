#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "arrayEmployees.h"

#define MAXIMO 1001

int inicializarEmployees(eEmployee list[], int len)
{
    int returnear = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        returnear = -1;
    };

    return returnear;
};


int funcionOpciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- DAR DE ALTA EMPLEADO \n");
    printf(" 2- MODIFICAR EMPLEADO\n");
    printf(" 3- BAJA EMPLEADO\n");
    printf(" 4- INFORMAR \n");
    printf(" 5- SALIR \n ");
    while(!getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};

int findEmptyEmpleado(eEmployee list[],int len)
{
    int index = -1;
    for(int i=1; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};



int findEmpleado(eEmployee list[],int len, int id)
{
    int idx= -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            idx = i;
            break;
        }
    }
    return idx;

};


void viewEmpleado(eEmployee sEmpleado)
{

    printf(" \nID:%d - Nombre:%s -  Apellido:%s-  Salario:%.2f-  Sector:%d \n ", sEmpleado.id, sEmpleado.name, sEmpleado.lastName, sEmpleado.salary, sEmpleado.sector);
};


void viewEmpleados(eEmployee list[], int len)
{

    system("cls");
    printf(" ID NAME LASTNAME SALARY SECTOR \n\n");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewEmpleado(list[i]);
        }
    }

};


int addEmpleado(eEmployee list[], int len)
{
    eEmployee nuevoEmpleado;

    int idx;
    char auxiliarName[32];
    char auxiliarLastName[32];
    char auxiliarSalary[12];
    char auxiliarSector[12];
    int rep;

    int pNombre=0,pApellido=0,pSalario=0,pSector=0;

    if(list != NULL && MAXIMO > 0)
    {
        system("cls");
        fflush(stdin);
        idx=findEmptyEmpleado(list,len);
        printf("ALTA DE EMPLEADO!!!");

        if(idx == -1)
        {
            printf("ERROR, NO HAY LUGAR EN EL SISTEMA");
            rep=-1;
            system("pause");
        }
        else
        {
            printf("NUEVO EMPLEADO! ID:%d \n\n",idx);
            nuevoEmpleado.id=idx;


            if(pApellido==0)
            {
                while(!getStringLetras("Ingrese el apellido:\n\n",auxiliarLastName))
                {
                    printf("ERROR, EL APELLIDO SOLAMENTE PUEDE CONTENER LETRAS\n\n");
                    system("pause");
                    system("cls");
                    pApellido=1;
                }
                pApellido=1;
            }
            printf("\nApellido:%s\n\n",auxiliarLastName);


            if(pNombre==0)
            {
                while(!getStringLetras("Ingrese el nombre:\n\n",auxiliarName))
                {
                    printf("ERROR, EL NOMBRE SOLAMENTE PUEDE CONTENER LETRAS\n\n");
                    system("pause");
                    system("cls");
                    pNombre=1;
                }
                pNombre=1;
            }
            printf("\nApellido:%s - Nombre:%s \n\n",auxiliarLastName,auxiliarName);

            if(pSalario == 0)
            {
                while(!getStringNumerosFlotantes("Ingrese Salario:\n\n", auxiliarSalary))
                {
                    printf("ERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");
                    pSalario=1;
                };
                pSalario=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s \n\n",auxiliarName,auxiliarLastName,auxiliarSalary);


            if(pSector==0)
            {
                while(!getStringNumeros("Ingrese el sector:\n\n",auxiliarSector))
                {
                    printf("ERROR, EL SECTOR TIENE QUE CONTENER SOLO NUMEROS ENTEROS\n\n");
                    system("pause");
                    system("cls");
                    pSector=1;
                }
                pSector=1;
            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s - Sector:%s\n\n",auxiliarName,auxiliarLastName,auxiliarSalary,auxiliarSector);


            while((pApellido==1)&&(pNombre==1)&&(pSalario==1)&&(pSector==1))
            {
                strcpy(nuevoEmpleado.name,auxiliarName);
                strcpy(nuevoEmpleado.lastName,auxiliarLastName);
                nuevoEmpleado.salary=atof(auxiliarSalary);
                nuevoEmpleado.sector=atoi(auxiliarSector);
                nuevoEmpleado.isEmpty=0;

                list[idx]=nuevoEmpleado;

                system("cls");
                printf("----NUEVO EMPLEADO CARGADO CON EXITO!!!----\n");
                printf("******BIENVENIDO %s******\n",auxiliarName);

                viewEmpleado(list[idx]);
                rep=0;
                break;
            }
        }
    }
    else
    {
        rep=-1;
    }
    return rep;
};


int funcionOpcionesModificacionEmpleado()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES DE MODIFICACION *******");
    printf("\n Que desea modificar?\n");
    printf(" 1- NOMBRE DEL EMPLEADO\n");
    printf(" 2- APELLIDO DEL EMPLEADO \n");
    printf(" 3- SUELDO DEL EMPLEADO\n");
    printf(" 4- SECTOR DEL EMPLEADO \n");
    printf(" 5- NO MODIFICAR NADA \n ");
    while(!getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};


void modificarEmpleado(eEmployee list[], int len)
{
    int id;
    char auxiliarId[5];
    int index;
    char nuevoNombre[21];
    char nuevoApellido[21];
    char nuevoSector[10];
    char nuevoSalario[21];
    char continuar='s';
    int rpp;
    int paraId=0;

    system("cls");
    printf("*******MODIFICAR EMPLEADO*******");

    if(paraId==0)
    {
        while(!getStringNumeros("Ingrese el ID: ",auxiliarId))
        {
            printf("ERROR, EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
    }
    id = atoi(auxiliarId);

    index=findEmpleado(list,len,id);

    if(index==-1)
    {
        printf("ERROR, NO HAY NINGUN EMPLEADO CON EL ID %d",id);
    }
    else
    {
        while(!getStringNumeros("Ingrese un ID correcto:",auxiliarId))
        {
            printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxiliarId);
        index= findEmpleado(list,len,id);
    }

    while(index<1001 && index > 0)
    {
        viewEmpleado(list[index]);

        do
        {
            switch(funcionOpcionesModificacionEmpleado())
            {
            case 1:
                fflush(stdin);
                viewEmpleado(list[index]);

                while(!getStringLetras("Ingrese el nuevo nombre:",nuevoNombre))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].name,nuevoNombre);
                rpp = 0;
                break;

            case 2:
                fflush(stdin);
                viewEmpleado(list[index]);

                while(!getStringLetras("Ingrese apellido nuevo: ",nuevoApellido))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].lastName,nuevoApellido);
                rpp = 0;
                break;

            case 3:
                fflush(stdin);
                viewEmpleado(list[index]);

                while(!getStringNumerosFlotantes("Ingrese el nuevo salario:",nuevoSalario))
                {
                    printf("ERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                }
                list[index].salary=atof(nuevoSalario);
                rpp = 0;
                break;

            case 4:
                fflush(stdin);
                viewEmpleado(list[index]);

                while(!getStringNumeros("Ingrese el nuevo sector:",nuevoSector))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                }
                list[index].sector=atoi(nuevoSector);
                rpp = 0;
                break;

            case 5:
                printf("VOLVIENDO AL MENU ANTERIOR");
                rpp = 0;
                break;

            default:
                printf("\n\n Opcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
                system("pause");
                break;
            }

            if(rpp==0)

            {
                printf("\n MODIFICACCION REALIZADA CORRECTAMENTE");
                printf("\n  Desea continuar modificando? \n\n");
                scanf("%c",&continuar);

                fflush(stdin);
                system("cls");
                break;
            }
            else
            {
                printf("\n\n Deses salir de la modificacion? s/n \n\n");
                scanf("%c",&continuar);

                fflush(stdin);
                system("cls");

            }
            return;

        }while(continuar == 's' || continuar == 'S');
    }
}

int removeEmpleado(eEmployee list[], int len,int id)
{
    char auxiliarId[10];
    char auxiliarYes[10];
    int conf,index,ret;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\t\t  ***Baja de Empleado***\n");
        viewEmpleados(list,len);
        while(!getStringNumeros("\nIngrese ID del empleado a borrar: ",auxiliarId))
        {
            printf("***Error*** Debe ingresar un numero.\n");
            system("pause");
        }
        id = atoi(auxiliarId);
        index = findEmpleado(list, len, id);

        if( index == -1)
        {
            printf("No hay ningun empleado con id %d.\n\n", id);
            system("pause");
        }
        else
        {
            viewEmpleado(list[index]);

            while(!getStringNumeros("\nEs este el empleado/a que desea borrar?\nIngrese 1 si es correcto / Otro numero si es incorrecto: ",auxiliarYes))
            {
                printf("***Error*** Debe ingresar un numero.\n");
                system("pause");
            }
            conf = atoi(auxiliarYes);

            if(conf == 1)
            {
                system("cls");
                printf("El empleado/a ha sido borrado con exito!\n");
                system("pause");
                list[index].isEmpty = 1 ;
            }
            else
            {
                printf("Baja cancelada.\n");
                system("pause");
            }
        }
    }
    else
    {
        ret = -1;
    }



    return ret;





}


int sortEmployees(eEmployee list[], int len)
{
    eEmployee auxEmployee;
    char auxOrder[1] ;
    int ret,order;


    if(list != NULL && len > 0)
    {
        while(!getStringNumeros("\n Ingrese 1 para ordenar Apellido de forma ascendente o ingrese 2 para ordenar de forma descendente: ",auxOrder))
        {
            printf("*** ERROR DEBE INGRESAR UN NUMERO ***");

        }
        order = atoi(auxOrder);
        switch(order)
        {
        case 1:
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) < 0  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
            printf("\n\nSe ordeno correctamente.\n");
            system("pause") ;
            system("cls") ;
            break;
        case 2:
            for(int i = 0; i < len-1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }

            system("pause") ;
            system("cls") ;
            break;
        default:
            printf("No ingreso 1 o 2");
        }

    }
    else
    {
        ret = -1;
    }


    return ret;

};
