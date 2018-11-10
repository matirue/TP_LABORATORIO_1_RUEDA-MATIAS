
#include "Employee.h"

/******************************************************************************************************/
Employee* employee_new()
{
    Employee* newEmpleado;

    newEmpleado=(Employee*)malloc(sizeof(Employee));

    return newEmpleado;
}

/******************************************************************************************************/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmpleado;
    newEmpleado=employee_new();

    if(newEmpleado!=NULL && employee_validoId(idStr)==0 && employee_validoNombre(nombreStr)==0 && employee_validoHorasTrabajadas(horasTrabajadasStr)==0 && employee_validoSueldo(sueldoStr)==0) //falta preguntar por las validaciones
    {  ///setea despues de validar
        employee_setId(newEmpleado,atoi(idStr));
        employee_setNombre(newEmpleado,nombreStr);
        employee_setHorasTrabajadas(newEmpleado,atoi(horasTrabajadasStr));
        employee_setSueldo(newEmpleado,atoi(sueldoStr));

        return newEmpleado;
    }
    else///caso de error eliminno newparametros
    {
        printf("\n\n error en employee.c al cargar datos. lin 32\n\n");
        employee_delete(newEmpleado);
        return NULL;
    }
     //retorno null en caso de error
}

/******************************************************************************************************/

int employee_delete(Employee* empleado)
{
    int retorna=-1;
    if(empleado!=NULL)
        {
            free(empleado);
            retorna=0;
        }
    return retorna;

}

/******************************************************************************************************/

int employee_setId(Employee* empleado,int id)
{
    int retorna=-1;
    int auxId=-1;

    if(empleado!=NULL && id == -1)
        {
            auxId++;
            empleado->id=auxId;
            retorna=0;
        }
    else if(id>auxId)
        {
            auxId=id;
            empleado->id=auxId;
            retorna=0;
        }

    return retorna;
}

int employee_getId(Employee* empleado,int* id)
{
    int retorna=-1;

    if(empleado!=NULL && id!=NULL)
        {
            *id=empleado->id;
             retorna=0;
        }

    return retorna;
}

/******************************************************************************************************/
int employee_setNombre(Employee* empleado,char* nombre)
{
    int retorna=-1;

    if(empleado!=NULL && nombre!=NULL)
        {
            strcpy(empleado->nombre,nombre);
            retorna=0;
        }

    return retorna;

}

int employee_getNombre(Employee* empleado,char* nombre)
{
    int retorna=-1;

    if(empleado!=NULL && nombre!=NULL)
        {
            strcpy(nombre,empleado->nombre);
            retorna=0;
        }

    return retorna;
}
/******************************************************************************************************/
int employee_setHorasTrabajadas(Employee* empleado,int horasTrabajadas)
{
    int retorna=-1;
    if(empleado!=NULL)
        {
            empleado->horasTrabajadas=horasTrabajadas;
            retorna=0;
        }

    return retorna;
}

int employee_getHorasTrabajadas(Employee* empleado,int* horasTrabajadas)
{
    int retorna=-1;
    if(empleado!=NULL && horasTrabajadas!=NULL)
        {
            *horasTrabajadas=empleado->horasTrabajadas;
            retorna=0;
        }

    return retorna;
}
/******************************************************************************************************/
int employee_setSueldo(Employee* empleado,int sueldo)
{
    int retorna=-1;
    if(empleado!=NULL)
        {
            empleado->sueldo=sueldo;
            retorna=0;
        }
    return retorna;
}
int employee_getSueldo(Employee* empleado,int* sueldo)
{
    int retorna=-1;
    if(empleado!=NULL && sueldo!=NULL)
        {
            *sueldo=empleado->sueldo;
            retorna=0;
        }

    return retorna;
}
/******************************************************************************************************/
/******************************************* Validaciones de campos ***********************************************************/
int employee_validoId(char* id)
{
    int retorna=-1, tam_id;
    tam_id=strlen(id);

    if(id!=NULL && miValidacion_stringDeInt(id,tam_id)==0)
        {
            retorna=0;
        }
    else
        {
            printf("\n ID INVALIDO. \n");
        }
    return retorna;
}

int employee_validoNombre(char* nombre)
{
    int retorna=-1, tam_nombre;

    tam_nombre=strlen(nombre);

    if(nombre!=NULL && miValidacion_stringChar(nombre,tam_nombre)==0)
        {
            nombre[0]=toupper(nombre[0]);
            retorna=0;
        }
    return retorna;

}

int employee_validoHorasTrabajadas(char* hora)
{
    int retorna=-1, tam_hora;

    tam_hora=strlen(hora);

    if (hora!=NULL && miValidacion_stringDeInt(hora,tam_hora)==0)
        {
            retorna=0;
        }
    return retorna;
}

int employee_validoSueldo(char* sueldo)
{
    int retorna=-1, tam_sueldo;

    tam_sueldo=strlen(sueldo);

    if(sueldo!=NULL && miValidacion_stringDeInt(sueldo,tam_sueldo)==0)
        {
            retorna=0;
        }
    return retorna;
}
/******************************************************************************************************/
int employee_nexId(void* pListaEmpleados)
{
    Employee* empleado;
    int retorna=-1, i, aux_id=0, tam;
    ///           i= indice       tam tamaño del linkerlist
    tam=ll_len(pListaEmpleados);

    if(pListaEmpleados!=NULL)
        {
            for(i=0;i<tam;i++)
                {
                    empleado=ll_get(pListaEmpleados,i);///agarra a cada empleado
                    employee_getId(empleado,&aux_id);///toma su id
                }
                retorna=aux_id+1; ///al ultimo id q tomo le suma 1
        }
    return retorna;
}

void employee_mostrarUno (Employee* empleado)
{
    int buffer_id, buffer_horas, buffer_sueldo;
    char buffer_nombre[1024];
    ///tomo los datos
    employee_getId(empleado,&buffer_id);
    employee_getNombre(empleado,buffer_nombre);
    employee_getHorasTrabajadas(empleado,&buffer_horas);
    employee_getSueldo(empleado,&buffer_sueldo);
    ///lo muestro
    printf("  %d  \t- %7s  \t-    %7d    \t-    $ %d \n",buffer_id,buffer_nombre,buffer_horas,buffer_sueldo);
}

int employee_ordenPorId (void* empleadoA, void* empleadoB)
{
    int retorna;
    Employee* listaA;
    Employee* listaB;

    if(empleadoA!=NULL && empleadoB!=NULL)
        {
            listaA=(Employee*)empleadoA;
            listaB=(Employee*)empleadoB;

            if((listaA->id)>(listaB->id))
                {
                    retorna=-1;
                }
            else if((listaA->id)<(listaB->id))
                {
                    retorna=1;
                }
            else if ((listaA->id)==(listaB->id))
                {
                    retorna=0;
                }
        }
    return retorna;
}

int employee_ordenPorNombre (void* empleadoA, void* empleadoB)
{
    int retorna;
    Employee* listaA;
    Employee* listaB;

    if(empleadoA!=NULL && empleadoB!=NULL)
        {
            listaA=(Employee*)empleadoA;
            listaB=(Employee*)empleadoB;

            retorna=stricmp((listaB->nombre),(listaA->nombre));
        }
    return retorna;
}

int employee_ordenPorHora (void* empleadoA, void* empleadoB)
{
    int retorna;
    Employee* listaA;
    Employee* listaB;

    if(empleadoA!=NULL && empleadoB!=NULL)
        {
            listaA=(Employee*)empleadoA;
            listaB=(Employee*)empleadoB;

            if((listaA->horasTrabajadas)>(listaB->horasTrabajadas))
                {
                    retorna=-1;
                }
            else if((listaA->horasTrabajadas)<(listaB->horasTrabajadas))
                {
                    retorna=1;
                }
            else if ((listaA->horasTrabajadas)==(listaB->horasTrabajadas))
                {
                    retorna=0;
                }
        }
    return retorna;
}

int employee_ordenPorSueldo (void* empleadoA, void* empleadoB)
{
    int retorna;
    Employee* listaA;
    Employee* listaB;

    if(empleadoA!=NULL && empleadoB!=NULL)
        {
            listaA=(Employee*)empleadoA;
            listaB=(Employee*)empleadoB;

            if((listaA->sueldo)>(listaB->sueldo))
                {
                    retorna=-1;
                }
            else if((listaA->sueldo)<(listaB->sueldo))
                {
                    retorna=1;
                }
            else if ((listaA->sueldo)==(listaB->sueldo))
                {
                    retorna=0;
                }
        }
    return retorna;
}
/******************************************************************************************************/
/******************************************************************************************************/
/******************************************************************************************************/
/******************************************************************************************************/

