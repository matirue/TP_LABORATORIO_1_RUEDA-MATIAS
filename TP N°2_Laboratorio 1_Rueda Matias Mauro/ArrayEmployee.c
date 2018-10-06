#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "ArrayEmployee.h"

/********************************************************************************************/
int empleados_menu ()
{
    int opc;

    printf("::::::::::::::::::: MENU DE OPERACIONES :::::::::::::::::::");
    printf("\n\n");
    printf("1-AGREGAR EMPLEADO\n");
    printf("2-MODIFICAR EMPLEADO\n");
    printf("3-DAR DE BAJA EMPLEADO\n");
    printf("4-INFORMES\n");
    printf("5-SALIR\n");
    printf("\n\n");

    opc=getValidInt("\n Elija una operacion: ", "\n\n  ERROR. Operacion invalida ", 1, 5);

    return opc;
}
/********************************************************************************************/
int empleados_init (eEmployee* pEmployee ,int cantidad)
{
    int i, retorna=-1;
    if(pEmployee!=NULL && cantidad>0)
        {
            for(i=0;i<cantidad;i++)
                {
                   pEmployee[i].isEmpty==FREE;  //FREE=0 que esta vacio
                }

            retorna=0;
        }
    return retorna;
}
/********************************************************************************************/
void empleados_hardCode (eEmployee* pEmployee)
{
    int idAux[3]={100,102,103};
    char nameAux[][51]={"Matias","Maria","Pablo"};
    char lastNameAux[][51]={"Rueda","Gonsalez","Fernandez"};
    float salaryAux[3]={1000,2000,3000};
    int sectorAux[3]={1,2,3};
    int i;
    for(i=0;i<3;i++)
        {
            pEmployee[i].id=idAux[i];
            pEmployee[i].salary=salaryAux[i];
            pEmployee[i].sector=sectorAux[i];
            strcpy(pEmployee[i].lastName, lastNameAux[i]);
            strcpy(pEmployee[i].name, nameAux[i]);
            pEmployee[i].isEmpty=FULL;
        }
}
/********************************************************************************************/
/** \brief funcion que genera un ID, iniciando en 103 para dar desde el 104 en adelante
 * \param void
 * \return int Retorna el id generado
 */
int empleadoscreatId ()
{
    static int contar=0;
    contar++;
    return contar;
}
/********************************************************************************************/
int empleados_findFreeSpace (eEmployee* pEmployee, int cantidad)
{
    int i, space=-1; //devuelve -1 en caso de no encontrar espacio libre

    for(i=0;i<cantidad;i++)
        {
            if(pEmployee[i].isEmpty==FREE)
                {
                    space=i;
                    break;
                }
        }
    return space;
}
/********************************************************************************************/
int empleados_findByID (eEmployee* pEmployee, int cantidad, int id)
{
    int i, indice=-1;
    if(pEmployee!=NULL)
        {
            for(i=0;i<cantidad;i++)
            {
                if( pEmployee[i].id==id && pEmployee[i].isEmpty==FULL)
                {
                    indice=i;
                    break;
                }
            }
        }

    return indice;
}
/********************************************************************************************/
int pedirEStiloDeLista (void)
{
    int estilo;
    estilo=getValidInt("\n Ordenar la lista de empleados de forma: \n   1-Ascendente \n   2-Descendente \n ", "\n\n ERROR, dato invalido.\n ",1,2);
    return estilo;
}

int empleados_sort (eEmployee* pEmployee, int cantidad, int estilo)
{
    eEmployee auxiliar;
    int retorna=-1, i,j;

    if(pEmployee!=NULL && cantidad>0)
        {
            switch(estilo)
            {
               case 1: //orden ascendente

                   for(i=0;i<cantidad-1;i++)
                    {
                        for(j=i+1;j<cantidad;j++)
                            {
                                if(strcmp(pEmployee[j].lastName, pEmployee[i].lastName)<0)
                                    {
                                        auxiliar=pEmployee[i];
                                        pEmployee[i]=pEmployee[j];
                                        pEmployee[j]=auxiliar;
                                    }
                                else if(strcmp(pEmployee[j].lastName, pEmployee[i].lastName)==0 && pEmployee[j].sector<pEmployee[i].sector)
                                    {
                                        auxiliar=pEmployee[i];
                                        pEmployee[i]=pEmployee[j];
                                        pEmployee[j]=auxiliar;
                                    }
                            }
                    }

                    retorna=0;
                   break;

               case 2: //orden descendente

                   for(i=0;i<cantidad-1;i++)
                    {
                        for(j=i+1;j<cantidad;j++)
                            {
                                if(strcmp(pEmployee[j].lastName, pEmployee[i].lastName)>0)
                                    {
                                        auxiliar=pEmployee[i];
                                        pEmployee[i]=pEmployee[j];
                                        pEmployee[j]=auxiliar;
                                    }
                                else if(strcmp(pEmployee[j].lastName, pEmployee[i].lastName)==0 && pEmployee[j].sector>pEmployee[i].sector)
                                    {
                                        auxiliar=pEmployee[i];
                                        pEmployee[i]=pEmployee[j];
                                        pEmployee[j]=auxiliar;
                                    }
                            }
                    }
                    retorna=0;
                   break;

            }
        }
    return retorna;
}

void empleados_listarPorApellido_creciente (eEmployee* pEmployee, int cantidad)   ///lista q voy a usar para mostrar en la baja
{
    int i, ascendente=1;


    if(empleados_sort(pEmployee, cantidad, ascendente)==0)
        {
            if(pEmployee!=NULL && cantidad>0)
                {
                 printf("\n  APELLIDO  \t  NOMBRE  \t   ID  \t     SECTOR  ");
                 for(i=0;i<cantidad;i++)
                 {
                    if(pEmployee[i].isEmpty==FULL)
                        {
                            mostrar__empleadoPorApellido(pEmployee[i]);
                        }
                 }

                }
       }
}
void mostrar__empleadoPorApellido(eEmployee pEmployee)
{
    printf("\n  %5s  \t  %5s  \t  %4d  \t  %d ",pEmployee.lastName,pEmployee.name,pEmployee.id,pEmployee.sector);
}

void empleados_analisisDeSalarios (eEmployee* pEmployee, int cantidad)
{
    float total=0, promedio=0;
    int contadorEmpleados=0, contadorSalarios=0;
    int i;

    for(i=0;i<cantidad;i++)
        {
            if(pEmployee[i].isEmpty==FULL)   //cuento cantidad de empleados y sumo todos los salarios
                {
                    total=total+pEmployee[i].salary;

                    contadorEmpleados++;
                }
        }

    promedio=total/contadorEmpleados; //hagp el promedio del salario

    for(i=0;i<cantidad;i++)
        {
            if(pEmployee[i].isEmpty==FULL)
                {
                    if(pEmployee[i].salary>=promedio)
                        {
                            contadorSalarios++;
                        }
                }
        }


    printf("\n   -Un total de salrio de: $ %.2f \n   -Un promedio de salrio: $ %.2f \n   -Cantidadd de empleados un un sueldo mayor o igual al promedio: %d\n",total,promedio,contadorSalarios);

}


int empleados_print (eEmployee* pEmployee, int cantidad)
{
    int retorna=-1, i;

    for(i=0;i<cantidad;i++)
        {
            if(pEmployee!=NULL && cantidad>0)
                {
                    printf("\n  APELLIDO  \t  NOMBRE  \t   ID  \t    SECTOR  \t    SALARIO");

                    for(i=0;i<cantidad;i++)
                        {
                            if(pEmployee[i].isEmpty==FULL)
                                {
                                    printf("\n  %5s  \t  %5s  \t  %4d  \t  %d  \t  $ %5.2f",pEmployee[i].lastName,pEmployee[i].name,pEmployee[i].id,pEmployee[i].sector,pEmployee[i].salary);
                                    retorna=0;
                                }
                        }
                }
        }
    return retorna;
}
/********************************************************************************************/
void empleados_darDeAlta (eEmployee* pEmployee, int cantidad)
{
    int lugar, i;
    int aux_id, aux_sector;
    char aux_name[51], aux_lastName[51];
    float aux_salario;
    char verificarSalario[999999];

    lugar=empleados_findFreeSpace(pEmployee, cantidad);

    if(lugar == -1)
        {
            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(" ::  Memoria llena, imposible seguir operando.  ::\n");
            printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
        }
    else
        {
            getValidString("\n APELLIDO: ","\n\n ERROR, apellido invalido\n",aux_lastName);
            for(i=0;i<strlen(aux_lastName);i++)
                {
                    if(i==0)
                        {
                            aux_lastName[i]=toupper(aux_lastName[i]);
                        }
                }

            getValidString("\n NOMBRE: ","\n\n ERROR, nombre invalido\n",aux_name);
            for(i=0;i<strlen(aux_name);i++)
                {
                    if(i==0)
                        {
                            aux_name[i]=toupper(aux_name[i]);
                        }
                }

            aux_sector=getValidInt("\n SECTOR : ","ERROR, sector incorrecto\n Sectores:\n 1-cobranzas\n 2-Atencion al cliente\n 3-Envios \n\n",1,3);

            while(getStringNumerosFlotantes("\n SUELDO: $", verificarSalario)==0 || ( (atoi(verificarSalario))<0 || (atoi(verificarSalario))>99999999999.99 ) )
                        {
                           printf("\n\n Error. Importe invalido: \n");
                           printf("\n - Debe ser numerico.");
                           printf("\n - Fuera de rango \n\n");
                        }
            aux_salario=atoi(verificarSalario);


            if(addEmployees(pEmployee, cantidad,aux_id,aux_lastName,aux_name,aux_sector,aux_salario) == -1)  //Cargo los datos pedidos
                {
                    printf("\n\n ERROR en la carga de datos \n");
                }
            else
                {
                    printf("\n\n Alta exitosa!  \n\n");
                }
        }
}
/********************************************************************************************/
int addEmployees (eEmployee* pEmployee, int cantidad, int subir_id, char subir_lastName[], char subir_name[], int subir_sector, int subir_salario)
{
    int retorna=-1, lugar, controlID;
    lugar=empleados_findFreeSpace(pEmployee,cantidad);
    controlID=empleados_findByID(pEmployee,cantidad,subir_id);


    if(pEmployee!=NULL)
        {
            if(subir_lastName!=NULL && subir_name!=NULL)
                {
                    if(lugar!=-1)
                        {
                            if(pEmployee[controlID].isEmpty==FULL)
                                {
                                    subir_id=empleadoscreatId();
                                    printf("\n ID generado: %d \n\n", subir_id );
                                }
                                pEmployee[lugar].id=subir_id;
                                strcpy(pEmployee[lugar].lastName, subir_lastName);
                                strcpy(pEmployee[lugar].name, subir_name);
                                pEmployee[lugar].salary=subir_salario;
                                pEmployee[lugar].sector=subir_sector;

                                pEmployee[lugar].isEmpty=FULL;

                                retorna=0;
                        }
                }
        }
    return retorna;
}
/********************************************************************************************/
void empleados_darBaja (eEmployee* pEmployee, int cantidad)
{
    int aux_id, stop=-1, baja;
    char confirmar;

    aux_id=getValidInt("\n\n Ingrese el ID del empleado a dar de baja del sistema: ","ERROR. Id invalido", 1,1000);

    baja=empleados_remove(pEmployee,cantidad,aux_id);

    if(baja==1)
        {
            printf("\n Baja de empleado exitosa. \n");
        }
    else if(baja==0)
        {
            printf("\n\n Baja cancelada \n\n");
        }
    else{
            printf("\n\n ERROR en la baja \n\n");
        }



}
/********************************************************************************************/
int empleados_remove (eEmployee* pEmployee, int cantidad, int bajaID)
{
    int existe, confirmar, stop = -1, retorna=-1;

    existe=empleados_findByID(pEmployee,cantidad,bajaID);

    if(existe== -1)
        {
            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(" ::  Id: %d no existe en el sistema.             ::\n",bajaID);
            printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
        }
    else
        {
            printf("\n\n Se encontro: \n ID: %d \n APELLIDO: %s \n NOMBRE: %s \n SECTOR: %d \n",pEmployee[existe].id,pEmployee[existe].lastName,pEmployee[existe].name,pEmployee[existe].sector);

            confirmar=getChar("\n Confirmar baja? (s/n):  ");

            do{
                if(confirmar=='s')
                {
                    pEmployee[existe].isEmpty=FREE;
                    stop=1;
                    retorna=1;
                }
                else if(confirmar=='n')
                {
                    stop=1;
                    retorna=0;
                }
                else
                {
                    printf("\n Respuesta invalida\n");
                    stop=-1;
                }
            }while(stop!=1);
        }
        return retorna;
}
/********************************************************************************************/
int empleados_menuModificar ()
{
    int opc;

    printf("::::::::::::::::::: ACTUALIZAR DATOS :::::::::::::::::::");
    printf("\n\n");
    printf("1-ACTUALIZAR APELLIDO\n");
    printf("2-ACTUALIZAR NOMBRE\n");
    printf("3-ACTUALIZAR SECTOR\n");
    printf("4-ACTUALIZAR SALARIO\n");
    printf("5-REGRESAR\n");
    printf("\n\n");

    opc=getValidInt("\n Elija una operacion: ", "\n\n  ERROR. Operacion invalida ", 1, 5);

    return opc;
}

void empleados_actualizar (eEmployee* pEmployee, int cantidad)
{
    int i, aux_id, lugar;
    int aux_sector;
    float aux_salario;
    char aux_lastName[51], aux_name[51], verificarSalario[999999], seguir=1;

    aux_id=getValidInt("\n ID del empleado a actulizar: ","\n ERROR, id invalido\n\n ", 1,1000);

    lugar=empleados_findByID(pEmployee,cantidad,aux_id);

    if(pEmployee!=NULL)
        {
            if(lugar>=0)
                {
                    do{
                        system("cls");
                        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                        printf("\ Empleado a renovar: \n ID: %d \n APELLIDO: %s \n NOMBRE: %s \n SECTOR: %d \n SALARIO: $ %.2f \n",pEmployee[lugar].id,pEmployee[lugar].lastName,pEmployee[lugar].name,pEmployee[lugar].sector,pEmployee[lugar].salary);
                        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

                        switch(empleados_menuModificar())
                        {
                        case 1://apellido
                            setbuf(stdin,NULL);
                            getValidString("\n\n NUEVO APELLIDO: ","\n\n ERROR, apellido invalido\n",aux_lastName);
                            for(i=0;i<strlen(aux_lastName);i++)
                            {
                              if(i==0)
                                {
                                    aux_lastName[i]=toupper(aux_lastName[i]);
                                }
                           }
                           strcpy(pEmployee[lugar].lastName,aux_lastName);
                           break;

                        case 2://Nombre
                            setbuf(stdin,NULL);
                            getValidString("\n\n NUEVO NOMBRE: ","\n\n ERROR, nombre invalido\n",aux_name);
                            for(i=0;i<strlen(aux_name);i++)
                            {
                              if(i==0)
                               {
                                  aux_name[i]=toupper(aux_name[i]);
                               }
                            }
                             strcpy(pEmployee[lugar].name,aux_name);
                           break;

                        case 3://sector
                            aux_sector=getValidInt("\n\n NUEVO SECTOR : ","ERROR, sector incorrecto\n Sectores:\n 1-cobranzas\n 2-Atencion al cliente\n 3-Envios \n\n",1,3);
                            pEmployee[lugar].sector=aux_sector;
                            break;

                        case 4://salario
                            while(getStringNumerosFlotantes("\n\n NUEVO SUELDO: $", verificarSalario)==0 || ( (atoi(verificarSalario))<0 || (atoi(verificarSalario))>99999999999.99 ) )
                            {
                                printf("\n\n Error. Importe invalido: \n");
                                printf("\n - Debe ser numerico.");
                                printf("\n - Fuera de rango \n\n");
                            }
                            aux_salario=atoi(verificarSalario);
                            pEmployee[lugar].salary=aux_salario;
                            break;

                        case 5:
                            seguir=-1;
                            printf("\n saliendo del menu modificar\n\n");

                            break;

                        default:
                           printf("\n\n    ERROR. Operacion invalida   \n\n");
                           system("pause");
                        }
                    }while(seguir!=-1);
                }
                else
                {
                        printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
                        printf(" ::  Id: %d no existe en el sistema.             ::\n",aux_id);
                        printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
                }
        }
}
