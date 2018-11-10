#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"

#include "miValidaciones.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/******************************************* Original del tp ************************************************************/

/** \brief Funcion que crea espacio en memoria
 * \param void
 * \return Employee* retorna el espacion en memoria reservado
 */
Employee* employee_new();


/** \brief Funcion que genera un nuevo empleado cargando los parametros que recibe
 * \param idStr char* parametro ID
 * \param nombreStr char* parametro nombre
 * \param horasTrabajadasStr char* parametro horas de trabajo
 * \param sueldoStr char* parametro sueldo
 * \return Restorna NULL en caso de error, caso contrario retorna un nuevo empleado cargado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr); //agregar las validaciones


/** \brief Funcion que libera espacio en memoria del empleado
 * \param Employee* empleado a liberar
 * \return int Retorna -1 en caso de error, 0en caso contrario
 */
int employee_delete(Employee*);


/** \brief Funcion que setea campo id de la estructura Employee
 * \param this Employee* Puntero a la lista
 * \param id int Dato a cargar.
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_setId(Employee* empleado,int id);

/** \brief Funcion que lee campo id de la estructura Employee
 * \param this Employee* puntero a la lista
 * \param id int* Dato que lee
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_getId(Employee* empleado,int* id);

/** \brief Funcion que setea campo nombre de la estructura Employee
 * \param this Employee* Puntero a la lista
 * \param nombre int Dato a cargar.
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_setNombre(Employee* empleado,char* nombre);

/** \brief Funcion que lee campo nombre de la estructura Employee
 * \param this Employee* puntero a la lista
 * \param nombre int* Dato que lee
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_getNombre(Employee* empleado,char* nombre);

/** \brief Funcion que stea campo horasTrabajadas de la estructura Employee
 * \param this Employee* Puntero a la lista
 * \param horasTrabajadas int Dato a cargar.
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_setHorasTrabajadas(Employee* empleado,int horasTrabajadas);

/** \brief Funcion que lee campo horas de la estructura Employee
 * \param this Employee* puntero a la lista
 * \param horasTrabajadas int* Dato que lee
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_getHorasTrabajadas(Employee* empleado,int* horasTrabajadas);

/** \brief Funcion que setea campo sueldo de la estructura Employee
 * \param this Employee* Puntero a la lista
 * \param sueldo int Dato a cargar.
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_setSueldo(Employee* empleado,int sueldo);

/** \brief Funcion que lee campo sueldo de la estructura Employee
 * \param this Employee* puntero a la lista
 * \param sueldo int* Dato que lee
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_getSueldo(Employee* empleado,int* sueldo);

/******************************************* Agregadas ************************************************************/

/** \brief Funcio que valida campo id
 * \param char* puntero a validar
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int employee_validoId(char* id);


/** \brief Funcion que valida campo nombre
 * \param char* puntero a validar
 * \return int retorna -1 en caso de error, 0 en caso contrario
 *
 */
int employee_validoNombre(char* nombre);


/** \brief Funcion que valida campo horasTrabajadas
 * \param char* puntero a validar
 * \return int retorna -1 en caso de error, 0 en caso contrario
 *
 */
int employee_validoHorasTrabajadas(char* hora);

/** \brief Funcion que valida campo sueldo
 * \param char* Puntero a validar
 * \return int retorna -1 en caso de error, 0 en caso contrario
 *
 */
int employee_validoSueldo(char* sueldo);


/** \brief Funcion que recorre el linkerlist devolviendo el siguiente id del ultimo leido
 * \param pListaEmpleados void* puntero a la lista de empleados a recorrer
 * \return int retorna el id generado
 *
 */
int employee_nexId(void* pListaEmpleados);

/** \brief Funcion que muestra un solo empleado
 * \param Employee* puntero a la lista de empleados a recorrer
 * \return void
 */
void employee_mostrarUno (Employee* empleado);

/** \brief Funcion que ordena (por id)dos estructura
 * \param void* puntero a estructura
 * \param void* puntero a estructura
 * \return int retorna el tipo de orden
 */
int employee_ordenPorId (void* empleadoA, void* empleadoB);


/** \brief Funcion que ordena (por nombre)dos estructura
 * \param void* puntero a estructura
 * \param void* puntero a estructura
 * \return int retorna el tipo de orden
 */
int employee_ordenPorNombre (void* empleadoA, void* empleadoB);

/** \brief Funcion que ordena (por horas trabajadas)dos estructura
 * \param void* puntero a estructura
 * \param void* puntero a estructura
 * \return int retorna el tipo de orden
 */
int employee_ordenPorHora (void* empleadoA, void* empleadoB);

/** \brief Funcion que ordena (por sueldo)dos estructura
 * \param void* puntero a estructura
 * \param void* puntero a estructura
 * \return int retorna el tipo de orden
 */
int employee_ordenPorSueldo (void* empleadoA, void* empleadoB);

#endif // employee_H_INCLUDED
