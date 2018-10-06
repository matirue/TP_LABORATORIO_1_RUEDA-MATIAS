#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployee.h"


/**
Comentario:
          Soy conciente de que a la hora de listar me muestra 3 datos basura, pero no encuentro la manera de evitar ese error.
          Y al ser entregado el dia viernes 5/10 sobre las 23 hs, me es imposible preguntar a un profesor.
          Alumno: Rueda Matias (1°B)
**/

int main()
{
    int salir=0;
    int i,estilo;

    eEmployee employee[TAM_EMPLOYEE]; //inicializo los estados

    if(empleados_init(employee, TAM_EMPLOYEE)==-1)
    {
        printf("\n :::::::::::::::::::: ALERTA! ::::::::::::::::::::\n");
        printf(" ::  Memoria llena, imposible seguir operando.  ::\n");
        printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    }
    else
    {   /*****************************************************************/
        empleados_hardCode(employee); //carga dato al sistema

        printf("\n   APELLIDO\t  NOMBRE\t ID\t  SECTOR\t  SUELDO($) \n");

        for(i=0;i<3;i++){
            if(employee[i].isEmpty==FULL && employee!=NULL){
                printf(" %10s  %10s  %10d  %10d  %15.2f \n",employee[i].lastName,employee[i].name,employee[i].id,employee[i].sector,employee[i].salary);
            }
        }
        system("pause");
        /*****************************************************************/

        do
        {
            system("cls");

            switch(empleados_menu())
            {
            case 1:
                system("cls");
                printf("::::::::::::::   DAR DE ALTA   ::::::::::::::\n");
                empleados_darDeAlta(employee, TAM_EMPLOYEE);
                system("pause");
                break;

            case 2:
                system("cls");
                printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

                printf(" Lista de empleados cargados\n");
                empleados_listarPorApellido_creciente(employee, TAM_EMPLOYEE);
                printf("\n\n (Sector: 1-Cobranzas|2-Atencion al cliente|3-Envios)\n");

                printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

                empleados_actualizar(employee, TAM_EMPLOYEE);

                system("pause");
                break;

            case 3:
                system("cls");
                printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

                printf(" Lista de empleados cargados\n");
                empleados_listarPorApellido_creciente(employee, TAM_EMPLOYEE);
                printf("\n\n (Sector: 1-Cobranzas|2-Atencion al cliente|3-Envios)\n");

                printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

                printf("\n:::::::::::::           DAR DE BAJA           ::::::::::::::\n");
                empleados_darBaja(employee, TAM_EMPLOYEE);

                system("pause");
                break;

            case 4:
                system("cls");
                printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf("\n:::::::::::::::      INFORMES      :::::::::::::::\n");

                estilo=pedirEStiloDeLista();
                empleados_sort(employee,TAM_EMPLOYEE,estilo); //ordena segun el estilo que elijio el usuario
                system("cls");

                printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

                printf("\n\n Lista compleat de todos los empleados \n"); //muestro todos los empleados
                empleados_print(employee,TAM_EMPLOYEE);
                printf("\n\n (Sector: 1-Cobranzas|2-Atencion al cliente|3-Envios)\n");

                printf("\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

                printf(" Se informa que se registro: ");
                empleados_analisisDeSalarios(employee,TAM_EMPLOYEE); //informa de salarios

                printf("\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

                system("pause");
                break;

            case 5:
                salir=1;
                break;

            default:
                printf("\n\n    ERROR. Operacion invalida   \n\n");
                system("pause");

            }

        }
        while(salir!=1);
    }
    return 0;
}
