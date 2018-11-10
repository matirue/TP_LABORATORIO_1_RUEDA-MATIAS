#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/******************************************* Original del tp ************************************************************/
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista donde se guardaran los datos
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista donde se guardaran los datos
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* puntero al linked donde se cargaran los datos
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* puntero al linked donde se cargaran los datos
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *\param pArrayListEmployee LinkedList* puntero al linked
 * \return int retorna -1 en caso de error, 0 en caso exitosa, 2 en caso de cancelacion
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* puntero al linked
 * \return int retorna -1 en caso de error, 0 en caso contrario
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* puntero al linked
 * \return retorna -1 en caso de error, 0 en orden exitoso por id, 1 en orden exitoso por nombre,
 *                 2 en orden exitoso por hora de trabajo, 3 en orden exitoso por sueldo
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int -1 en caso de error, 0 caso contrario
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int -1 en caso de error, 0 caso contrario
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Funcion encargada de liberar memoria
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int -1 en caso de error, 0 caso contrario
 */
int controller_liberoMemoria(LinkedList* pArrayListEmployee);

/******************************************* Agregadas ************************************************************/
/** \brief Funcion menu
 * \return int retorna valor pedido al usuario
 *
 */
int controller_menu();

/** \brief Funcion menu de modificaciones
 * \return int retorna valor pedido al usuario
 *
 */
int controller_menuModificacion();

/** \brief Funcion menu de ordenamiento
 * \return int retorna valor pedido al usuario
 *
 */
int controller_menuSort();
