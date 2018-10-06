#ifndef ARRAYEMPLOYEE_H_INLCUDED
#define ARRAYEMPLOYEE_H_INLCUDED

#include "Input.h"

#define TAM_EMPLOYEE 100
#define FREE 0
#define FULL 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    int isEmpty;
}eEmployee;


/** \brief Funcion menu de alta-modificacion-baja-informe
 * \param void
 * \return int el valor de la opcion ingresada por el usuario
 */
int empleados_menu (void);

/** \brief Funcion que inicializa todo el arry de isEmpty en FREE (en cero)
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return int (-1) en caso de error o puntero NULL - 0 si esta bien
 */
int empleados_init (eEmployee* ,int);

/** \brief Funcion que carga datos previamente
 * \param eEmployee* puntero al primer indice del array
 * \return void
 */
void empleados_hardCode (eEmployee* );

/** \brief Funcion que recorre todo el array en busca de espacios libres ( isEmpty=FREE (0) )
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return int (-1) en caso de no encotrar un espacio libre, en caso de encontrarlo retorna el indice
 */
int empleados_findFreeSpace (eEmployee* , int );

/** \brief Funcion que recorre el array en busca de coincidencias de ID
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Id a comparar
 * \return int retorna (-1) en caso de que no se encuentre coincidencia, en caso contrario retorna el indice de la coincidencia
 */
int empleados_findByID (eEmployee* , int , int );

/** \brief funcion que genera un ID, iniciando en 103 para dar desde el 104 en adelante
 * \param void
 * \return int Retorna el id generado
 */
int empleadoscreatId ();


/** \brief Funcion que pregunta el estilo de lista
 * \param void
 * \return int valor del estilo de lista (1) de forma ascendente (2) de forma descendente
 */
int pedirEStiloDeLista (void);


/** \brief Funcion que ordena de manera ascendente o descendente el array
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int estilo de orden (ascendente o descendente)
 * \return int (-1) en caso de error (tamaño no valido o puntero NULL) o (0) ok
 */
int empleados_sort (eEmployee* , int , int );


/** \brief Funcion que muestra empleados de manera creciente
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void empleados_listarPorApellido_creciente (eEmployee* , int );

/** \brief Funcion que muestra indice del arrar
 * \param eEmployee* puntero al primer indice del array
 * \return void
 */
void mostrar__empleadoPorApellido(eEmployee );

/** \brief Funcion que analiza los salarios
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void empleados_analisisDeSalarios (eEmployee* , int );


/** \brief Funcion que muestra todos los empleados con sus datos
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del arra
 * \return int (-1) en caso de error (tamaño no valido o puntero NULL) o (0) ok
 *
 */
int empleados_print (eEmployee* , int );



/** \brief Funcion que pide datos en caso de que se encuentre un lugar libre
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void empleados_darDeAlta (eEmployee*, int );


/** \brief Agreaga a la lista de empleado los valores reciidos como parametros en la posicion del indice
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Recibe el ID
 * \param char [] recibe la cadena apellido
 * \param char [] recibe una cadena nombre
 * \param int recibe el sector
 * \param int recibe el salario
 * \return int retorna int (-1) en caso de error (tamaño no valido o puntero NULL) o (0) ok
 *
 */
int addEmployees (eEmployee* pEmployee, int cantidad, int subir_id, char subir_lastName[], char subir_name[], int subir_sector, int subir_salario);


/** \brief Funcion que pide id al usuariopara darlo de baja
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 *
 */
void empleados_darBaja (eEmployee* pEmployee, int cantidad);


/** \brief Funcion que cambia el isEmpty del id a FREE
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Id a dar de baja
 * \return int retorna (1) baja exitosa, (0) baja cancelada, (-1) caso de error
 */
int empleados_remove (eEmployee* pEmployee, int cantidad, int bajaID);



/** \brief Funcion que muestra opciones del menu modificar
 * \param void
 * \return int retorna la opcion ingresada por el usuario
 */
int empleados_menuModificar (void);

/** \brief Funcion que permite ingresar un ID a modificar sus datos
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void empleados_actualizar (eEmployee* pEmployee, int cantidad);


#endif // ARRAYEMPLOYEE_H_INLCUDED
