#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
TP N°3 Laboratorio 1
ALUMNO: Rueda Matias Mauro
CURSO: 1°B
LEGAJO: 107246
FECHA DE ENTREGA: 10-11-2018

    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int salir=0;
    ///banderas q usare para indicar si el archivo en texto y binario se abrieron o no
    int flagg_txt=0, flagg_bin=0;


    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        system("cls");
        switch(controller_menu())
        {
            case 1:
                if(flagg_txt==0 && flagg_bin==0)
                    {
                        if(controller_loadFromText("data.csv",listaEmpleados)!=-1)
                            {
                               flagg_txt=1;///cambio el estado de la bandera a 1 para indicar que ya se cargo
                            }
                        else
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**          ERROR, el archivo no existe          **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                    }
                else if(flagg_txt==1)
                    {
                        printf("\n\n EL ARCHIVO EN MODO TEXTO YA A SIDO CARGADO. . . \n\n");
                    }

                system("pause");
                break;

            case 2:
                if(flagg_bin==0 && flagg_bin==0)
                    {
                        if(controller_loadFromBinary("data.bin",listaEmpleados)!=-1)
                            {
                               flagg_bin=1;///cambio el estado de la bandera a 1 para indicar que ya se cargo
                            }
                        else if(flagg_bin==0 && flagg_txt==1)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**      EL ARCHIVO YA FUE CARGADO EN MODO .TXT   **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                            else
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**          ERROR, el archivo no existe          **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }

                    }
                else if(flagg_bin==1)
                    {
                        printf("\n\n EL ARCHIVO EN MODO BINARIO YA A SIDO CARGADO. . . \n\n");
                    }

                system("pause");
                break;

            case 3:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        if(controller_addEmployee(listaEmpleados)==0)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**                ALTA EXITOSA                   **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                    }
                else
                    {
                        printf("\n\n NO HAY UN ARCHIVO CARGADO PREVIAMENTE. . . \n\n");
                    }

                system("pause");
                break;

            case 4:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        if(controller_editEmployee(listaEmpleados)==0)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**            MODIFICACION EXITOSA               **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                    }
                else
                    {
                        printf("\n\n NO HAY UN ARCHIVO CARGADO PREVIAMENTE. . . \n\n");
                    }

                system("pause");
                break;

            case 5:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        if(controller_removeEmployee(listaEmpleados)==0)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**                BAJA EXITOSA                   **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                    }
                else
                    {
                        printf("\n\n NO HAY UN ARCHIVO CARGADO PREVIAMENTE. . . \n\n");
                    }

                system("pause");
                break;

            case 6:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        controller_ListEmployee(listaEmpleados);
                    }
                else
                    {
                        printf("\n\n NO HAY UN ARCHIVO CARGADO PREVIAMENTE. . . \n\n");
                    }
                system("pause");
                break;

            case 7:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        controller_sortEmployee(listaEmpleados);

                    }
                else
                    {
                        printf("\n\n NO HAY UN ARCHIVO CARGADO PREVIAMENTE. . . \n\n");
                    }
                system("pause");
                break;

            case 8:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        if(controller_saveAsText("data.csv",listaEmpleados)==0)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**      ARCHIVO .CSV CARGADO EXITOSAMENTE        **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                         else if(controller_saveAsText("data.csv",listaEmpleados)==1)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**      NO SE PUEDE ACCEDER AL ARCHIVO           **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                    }
                else
                    {
                        printf("\n\n NO HAY UN ARCHIVO CARGADO PREVIAMENTE. . . \n\n");
                    }
                system("pause");
                break;

            case 9:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        if(controller_saveAsBinary("data.bin",listaEmpleados)==0)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**      ARCHIVO .BIN CARGADO EXITOSAMENTE        **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                         else if(controller_saveAsBinary("data.bin",listaEmpleados)==1)
                            {
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**      NO SE PUEDE ACCEDER AL ARCHIVO           **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                            }
                    }
                else
                    {
                        printf("\n\n NO HAY UN ARCHIVO CARGADO PREVIAMENTE. . . \n\n");
                    }
                system("pause");
                break;

            case 10:
                system("cls");
                ll_clear(listaEmpleados);
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**      SE APLICO LL_CLEAR A LA LISTA            **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");

                system("pause");
                break;

            case 11:
                if(flagg_txt==1 || flagg_bin==1)
                    {
                        controller_liberoMemoria(listaEmpleados);
                    }

                salir=1;
                break;

            default:
                    printf("\n\n OPCION INVALIDA\n\n");
                    break;
        }
    }while(salir!=1);

    printf("\n\n Fin....");
    return 0;
}
