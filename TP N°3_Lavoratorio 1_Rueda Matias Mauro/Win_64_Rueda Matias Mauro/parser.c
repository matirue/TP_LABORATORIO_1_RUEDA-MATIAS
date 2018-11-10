#include "parser.h"

///         FILE* puntero al archivo q recive abierto      LinkerList* puntero a linked donde carga los datos
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) ///parsea en modo texto
{
    Employee* unEmpleado;
    int retorna=-1, flagVueltas=1;

    char buffer_id[1024], buffer_nombre[1024], buffer_horas[1024], buffer_sueldo[1024];

    if(pFile!=NULL && pArrayListEmployee!=NULL)
        {
            while(!feof(pFile))
            {
                if(flagVueltas==1)
                    {
                        flagVueltas=0;
                        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer_id,buffer_nombre,buffer_horas,buffer_sueldo);
                    }

                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer_id,buffer_nombre,buffer_horas,buffer_sueldo);

                unEmpleado=employee_newParametros(buffer_id,buffer_nombre,buffer_horas,buffer_sueldo);

                if(unEmpleado!=NULL)
                    {
                        ll_add(pArrayListEmployee,unEmpleado);
                        retorna=0;
                    }
            }
        }

    return retorna;
}

///         FILE* puntero al archivo q recive abierto      LinkerList* puntero a linked donde carga los datos
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) ///parsea en modo binario
{
    Employee* unEmpleado;
    Employee* auxiliar;
    int retorna=-1, lee;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
        {
            do{
                unEmpleado=employee_new();
                auxiliar=employee_new();
                lee=fread(unEmpleado, sizeof(Employee),1,pFile);
                if(unEmpleado!=NULL && lee==1)
                    {
                        employee_setId(auxiliar,0);

                        ll_add(pArrayListEmployee,unEmpleado);

                        retorna=0;
                    }
                else
                    {
                        employee_delete(unEmpleado);
                        employee_delete(auxiliar);
                        retorna=-1;
                    }
            }while(!feof(pFile));
        }
    return retorna;
}
