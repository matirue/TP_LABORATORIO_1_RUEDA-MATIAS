
/******************************************* Original del tp ************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param char* puntero de tipo FILE al archivo a parsear
 * \param LinkedList* puntero a donde se guardaran los datos
 * \return int -1 en caso de error, 0 caso contrario
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param char* puntero de tipo FILE al archivo a parsear
 * \param LinkedList* puntero a donde se guardaran los datos
 * \return int -1 en caso de error, 0 caso contrario
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/******************************************* Agregadas ************************************************************/
