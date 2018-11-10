#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"



 ///                      path el achivo a abrir
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    system("cls");
    printf(" ABRIENDO EN MODO TEXTO . . .\n\n");

    FILE* pArchivo;
    int retorna=-1, cantidad;


    if(pArrayListEmployee!=NULL)
        {
            pArchivo=fopen(path,"r");

            if(pArchivo!=NULL)
                {
                    retorna=parser_EmployeeFromText(pArchivo,pArrayListEmployee);

                    if(retorna!=-1)
                        {
                            cantidad=ll_len(pArrayListEmployee);
                            printf("\n\n***************************************************\n");
                            printf("**                 CARGA EXITOSA                 **\n");
                            printf("**         CANTIDAD DE EMPLEADOS:   %d         **\n",cantidad);
                            printf("***************************************************\n\n");

                        }
                }
                else
                    {
                        retorna=-1;

                    }
                fclose(pArchivo);
        }
    return retorna;
}


 ///                      path el achivo a abrir
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    system("cls");
    printf(" ABRIENDO EN MODO BINARIO . . .\n\n");
    FILE* pArchivo;
    int retorna=-1, cantidad;

    if(pArrayListEmployee!=NULL)
        {
            pArchivo=fopen(path,"rb");

            if(pArchivo!=NULL)
                {
                    retorna=parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

                    if(retorna!=-1)
                        {
                            cantidad=ll_len(pArrayListEmployee);
                            printf("\n\n***************************************************\n");
                            printf("**                 CARGA EXITOSA                 **\n");
                            printf("** CANTIDAD DE EMPLEADOS:  %d                    **\n",cantidad);
                            printf("***************************************************\n\n");
                        }
                }
             else
                {
                    retorna=-1;

                }
             fclose(pArchivo);
        }
    return retorna;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    printf(" ALTA EMPLEADO . . .\n\n");
    Employee* newEmpleado;
    int retorna=-1;

    char buffer_Id[1024], buffer_nombre[1024], buffer_horas[1024], buffer_sueldo[1024];

    int aux_id, aux_horas, aux_sueldo;

    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
    {

    aux_id=employee_nexId(pArrayListEmployee); ///recorro el arraylist y genero el proximo id

    sprintf(buffer_Id, "%d", aux_id);///paso el id de entero a char al buffer

    printf("\n ID generado: %s ",buffer_Id);

    if(input_getString(buffer_nombre,10,"\n\n INGRESE NOMBRE DEL EMPLEADO: ","\n\n ERROR. Nombre invalido\n",1024)!=-1 &&
       input_getInt(&aux_horas,10,"\n\n INGRESE HORAS DE TRABAJO: ","\n\n ERROR. Dato invalido\n ",1,100000)!=-1 &&
       input_getInt(&aux_sueldo,10,"\n\n INGRESE SUELDO: ","\n\n ERROR. Dato invalido\n",1,1000000)!=-1)
        {
            sprintf(buffer_horas,"%d",aux_horas);///paso las horas de entero a char
            sprintf(buffer_sueldo,"%d",aux_sueldo);///paso el sueldo de entero a char

            newEmpleado=employee_newParametros(buffer_Id,buffer_nombre,buffer_horas,buffer_sueldo);
            if(newEmpleado!=NULL)
                {
                    ll_add(pArrayListEmployee,newEmpleado); ///cargo los datos
                    //printf("\n\n ALTA EXITOSA\n\n");
                    retorna=0;
                }
            else
                {
                    printf("\n\n***************************************************\n");
                    printf("**                                               **\n");
                    printf("**               ERROR EN LA CARGA               **\n");
                    printf("**                                               **\n");
                    printf("***************************************************\n\n");
                    employee_delete(newEmpleado);
                }
        }
    }
    else
    {
        printf("\n\n***************************************************\n");
        printf("**                                               **\n");
        printf("**       NO EXISTE LA LISTA EN EL SISTEMA        **\n");
        printf("**                                               **\n");
        printf("***************************************************\n\n");
    }
    return retorna;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* unEmpleado;

    int retorna=-1;
    int existe=0;
    int salir=0;

    int buffer_Id[1024], buffer_horas[1024], buffer_sueldo[1024];
    char buffer_nombre[1024];

    int aux_id, aux_idLista, aux_horas, aux_sueldo;
    char aux_nombre[1024];

    int tam_lista, i, indiceEmpleado;

    system("cls");

    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
        {   ///pido el id al usuario
            if(input_getInt(&aux_id,10,"\n INGRESE EL ID DEL EMPLEADO A MODIFICAR: ","\n\n ERROR, id invalido\n\n",0,9999)!=-1)
                {   ///pido el tamaño de la lisata
                    tam_lista=ll_len(pArrayListEmployee);

                    for(i=1;i<tam_lista;i++)
                        {
                            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                            employee_getId(unEmpleado,&aux_idLista);

                            if(aux_idLista==aux_id)
                                {
                                    existe=1; ///caso de coincidencia de id
                                    printf("\n\n Empleado encontrado... \n"); ///acrdate de printf
                                    break;
                                }
                            ///sin coincidencia existe queda en cero
                        }

                        if(existe==1)
                            {
                                ///obtengo los datos del empleado para mostrarlo
                                employee_getNombre(unEmpleado,aux_nombre);
                                employee_getHorasTrabajadas(unEmpleado,&aux_horas);
                                employee_getSueldo(unEmpleado,&aux_sueldo);

                                printf("\n\n   ID   \t-  NOMBRE    \t-  HORAS TRABAJADAS  \t-   SUELDO\n");
                                printf("  %d  \t- %7s  \t-    %7d    \t-    $ %d \n",aux_id,aux_nombre,aux_horas,aux_sueldo);

                                do{

                                switch(controller_menuModificacion())
                                {
                                case 1:
                                    if(input_getString(buffer_nombre,10,"\n\n INGRESE EL NUEVO NOMBRE: ","\n\n ERROR. Nombre invalido\n",1024)!=-1)
                                        {
                                            employee_setNombre(unEmpleado,buffer_nombre);
                                            retorna=0;
                                        }
                                    break;

                                case 2:
                                    if(input_getInt(&buffer_horas,10,"\n\n INGRESE NUEVAS HORAS DE TRABAJO: ","\n\n ERROR. Dato invalido\n ",1,100000)!=-1)
                                        {
                                            employee_setHorasTrabajadas(unEmpleado,*buffer_horas);
                                            retorna=0;
                                        }
                                    break;

                                case 3:
                                    if(input_getInt(&buffer_sueldo,10,"\n\n INGRESE NUEVAS SUELDO: ","\n\n ERROR. Dato invalido\n ",1,1000000)!=-1)
                                        {
                                            employee_setHorasTrabajadas(unEmpleado,*buffer_sueldo);
                                            retorna=0;
                                        }
                                    break;

                                case 4:
                                    printf("\n\n Volviendo al menu principal. . .\n");
                                    salir=1;
                                    break;


                                default:
                                    printf("\n\n ERROR, OPCION INVALIDA\n\n");
                               }

                             }while(salir!=1);
                            }
                            else
                                {
                                    printf("\n\n EL ID INGRESADO NO CORRESPONDE A NINGUN EMPLEADO REGISTRADO \n\n");
                                }
                }
        }
    return retorna;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorna=-1;
    Employee* unEmpleado;
    int tam_lista, existe=0, stop=0;
    char confirmar;
    int buffer_id, indice; ///int usado para tomar id de la lista//indice donde voy a guardar el i
    int aux_id, i;///aux_id usado para pedi dato al usuario//i es el indice del empleado
    system("cls");

    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
        {
            ///pido id del empleado a dar de baja
            if(input_getInt(&aux_id,10,"\n INGRESE EL ID DEL EMPLEADO A DAR DE BAJA: ","\n\n ERROR, id invalido\n\n",0,9999)!=-1)
                {
                    tam_lista=ll_len(pArrayListEmployee);
                    for(i=0;i<tam_lista;i++)
                        {
                            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                            employee_getId(unEmpleado,&buffer_id);

                            if(buffer_id==aux_id)
                                {
                                    existe=1;///cambio el estado de la bandera al encontrar el id
                                    indice=i;
                                    printf("\n\n Empleado encontrado... \n"); ///acrdate de printf
                                    break;
                                }
                        }
                    if(existe==1)
                        {   ///muestro el empleado
                            printf("\n\n   ID   \t-  NOMBRE    \t-  HORAS TRABAJADAS  \t-   SUELDO\n");
                            employee_mostrarUno(unEmpleado);

                            //confirmar=input_getChar("\n\n Cofirmar baja? (s/n): ");
                            do{
                                confirmar=input_getChar("\n\n Cofirmar baja? (s/n): ");
                                if(confirmar=='s')
                                    {
                                        ll_remove(pArrayListEmployee,indice);
                                        //printf("\n\n BAJA EXITOSA. . .\n");
                                        retorna=0;
                                        stop=1;
                                    }
                                else if(confirmar=='n')
                                    {
                                        printf("\n\n BAJA CANCELADA. . .\n\n");
                                        retorna=2;
                                        stop=1;
                                    }
                                else
                                    {
                                        printf("\n\n Respuesta invalida. . . ");
                                    }
                            }while(stop!=1);
                        }
                      else
                        {
                            printf("\n\n EL ID INGRESADO NO CORRESPONDE A NINGUN EMPLEADO REGISTRADO \n\n");
                        }
                }

        }
    return retorna;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorna=-1;
    Employee* unEmpleado;
    int tam_lista,i;

    system("cls");

    tam_lista=ll_len(pArrayListEmployee);
    printf("\n EMPLEADOS EN EL SISTEMA. . . \n\n   ID   \t-  NOMBRE    \t-  HORAS TRABAJADAS  \t-   SUELDO\n");
    for(i=0;i<tam_lista;i++)
        {
            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);///asigno el retorno a unEmpleado
            employee_mostrarUno(unEmpleado);///lo muestro
            retorna=0;
        }
    return retorna;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorna=-1;
    int ordenElegido;
    //int salir=0;

    system("cls");
    //do{

        switch(controller_menuSort())
        {
        case 1:
            printf("\n\n ORDEN POR ID. . .\n");
            if(input_getInt(&ordenElegido,10,"\n Elija 0 (cero) para orden ascendente, 1 (uno) para orden descendente: ","\n\n ERROR, dato invalido",0,1)!=-1)
                {
                    ll_sort(pArrayListEmployee,employee_ordenPorId,ordenElegido);
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**          ORDEN POR ID EXITOSA                 **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                    retorna=0;
                    //salir=1;
                }
           break;

        case 2:
            printf("\n\n ORDEN POR NOMBRE. . .\n");
            if(input_getInt(&ordenElegido,10,"\n Elija 0 (cero) para orden ascendente, 1 (uno) para orden descendente: ","\n\n ERROR, dato invalido",0,1)!=-1)
                {
                    ll_sort(pArrayListEmployee,employee_ordenPorNombre,ordenElegido);
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**          ORDEN POR NOMBRE EXITOSA             **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                    retorna=0;
                    //salir=1;
                }
           break;

        case 3:
            printf("\n\n ORDEN POR HORA DE TRABAJO. . .\n");
            if(input_getInt(&ordenElegido,10,"\n Elija 0 (cero) para orden ascendente, 1 (uno) para orden descendente: ","\n\n ERROR, dato invalido",0,1)!=-1)
                {
                    ll_sort(pArrayListEmployee,employee_ordenPorHora,ordenElegido);
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**      ORDEN POR HORAS DE TRABAJO EXITOSA       **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                    retorna=0;
                    //salir=1;
                }
           break;

        case 4:
            printf("\n\n ORDEN POR SUELDO. . .\n");
            if(input_getInt(&ordenElegido,10,"\n Elija 0 (cero) para orden ascendente, 1 (uno) para orden descendente: ","\n\n ERROR, dato invalido",0,1)!=-1)
                {
                    ll_sort(pArrayListEmployee,employee_ordenPorSueldo,ordenElegido);
                                printf("\n\n***************************************************\n");
                                printf("**                                               **\n");
                                printf("**          ORDEN POR SUELDO EXITOSA             **\n");
                                printf("**                                               **\n");
                                printf("***************************************************\n\n");
                    retorna=0;
                    //salir=1;
                }
           break;

        case 5:
            printf("\n\n Volviendo al menu principal. . .\n");
            //salir=1;
            break;


        default:
           printf("\n\n ERROR, OPCION INVALIDA\n\n");
        }
     //}while(salir!=1);


    return retorna;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorna=-1;

    ///PUNTERO AL ARCHIVO
    FILE* pArchivo;

    Employee* unEmpleado;
    int buffer_id, buffer_hora, buffer_sueldo;
    char buffer_nombre[1024];
    int i, tam_lista;
    ///el archivo ya fue abierto en 1 asi q me evito volver a verificar por las banderas en el main
    pArchivo=fopen(path,"w"); ///lo pisa

    if(pArrayListEmployee!=NULL && pArchivo!=NULL)
        {
            ///me paro en el principio del archivo
            rewind(pArchivo);
            fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n"); ///coloco los indicadores
            tam_lista=ll_len(pArrayListEmployee);

            for(i=1;i<tam_lista;i++)///arranco de uno para no pisar los indicadores
                {
                    unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

                    employee_getId(unEmpleado,&buffer_id);
                    employee_getNombre(unEmpleado,buffer_nombre);
                    employee_getHorasTrabajadas(unEmpleado,&buffer_hora);
                    employee_getSueldo(unEmpleado,&buffer_sueldo);

                    ///cargo al archivo los datos
                    fprintf(pArchivo,"%d,%s,%d,%d\n",buffer_id,buffer_nombre,buffer_hora,buffer_sueldo);
                }
            retorna=0;
        }
        else
            {
                retorna=1;
            }
        fclose(pArchivo);///lo cierro
    return retorna;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorna=-1;

    FILE* pArchivo;
    Employee* unEmpleado;
    int tam_lista, i, datosEscritos;

    pArchivo=fopen(path,"wb"); ///lo pisa

    if(pArrayListEmployee!=NULL && pArchivo!=NULL)
        {
            rewind(pArchivo);
            tam_lista=ll_len(pArrayListEmployee);

            for(i=1;i<tam_lista;i++)
                {
                    unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

                    datosEscritos=fwrite(unEmpleado,sizeof(Employee),1,pArchivo);

                    retorna=0;
                    if(datosEscritos!=1)
                        {
                            printf("\n\n ERROR AL ESCRIBIR EL ARCHIVO BINARIO. . . \n\n");
                        }
                }
        }
        else
            {
                retorna=1;
            }
        fclose(pArchivo);

    return retorna;
}


int controller_liberoMemoria(LinkedList* pArrayListEmployee)
{
    int retorna=-1;
    int tam_lista,i;
    if(pArrayListEmployee!=NULL)
        {
            tam_lista=ll_len(pArrayListEmployee);
            for(i=0;i<tam_lista;i++)
                {
                    ll_remove(pArrayListEmployee,i);///libera memora de cada indice
                }
            ll_deleteLinkedList(pArrayListEmployee);///limpio la lista
            retorna=0;
        }
    return retorna;
}

/*******************************************************************************************************/
int controller_menu()
{
    int opcion=0;
    //printf("\n---------- MENU DE OPERACIONES ----------\n");
    input_getInt(&opcion,10,"\n---------- MENU DE OPERACIONES ----------\n 1- Carga de empleado (modo texto)\n 2- Carga de empleado (mono binario)\n 3- Alta de empleado\n"
    " 4- Modificar empleado\n 5- Baja de empleado\n 6- Lista de empleados\n"
    " 7- Ordenar empleados\n 8- Guardar empleados (modo texto)\n 9- Guardar empleados (modo binario)\n 10- Limpiar lista\n 11- Salir\n"
    "\n OPCION: ","\n\n ERROR, OPCION INVALIDA\n\n", 1, 11);
    return opcion;
}

int controller_menuModificacion()
{
    int opcion=0;

    input_getInt(&opcion,10,"\n\n---------- MENU DE MODIFICACION ----------\n 1- Modificar nombre\n 2- Modificar horas de trabajo\n 3- Modificar sueldo\n"
    " 4- VOLVER\n\n OPCION: ","\n\n ERROR, OPCION INVALIDA\n\n", 1, 4);
    return opcion;
}

int controller_menuSort()
{
    int opcion=0;

    input_getInt(&opcion,10,"\n\n---------- MENU DE ORDEN ----------\n 1- ORDENAR POR ID\n 2- ORDENAR POR NOMBRE\n 3- ORDENAR POR HORA\n"
    " 4- ORDENAR POR SUELDO\n 5- VOLVER\n\n OPCION: ","\n\n ERROR, OPCION INVALIDA\n\n", 1, 5);
    return opcion;
}
