#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getInt(int* pDato);
int input_esNumerico(char* pDato);
int input_getInt(int* pDato,int cant, char* mensage, char* mensageError, int minimo, int maximo);
char input_getChar (char* message);
int getString(char* pDato,int limite);
int input_esString (char* pDato);
int input_getString (char* pDato, int intentos, char* mensage, char* mensageError, int tam);


/** \brief Valida que la cadena sea solo de caracteres numericos entre 0-9
 * \param char* puntero a cadena a validar
 * \param int tamaño de la cadena a  validar
 * \return int retorna -1 en caso de error, 0 en caso contrario
 *
 */
int miValidacion_stringDeInt(char* cad, int tam);

/** \brief Valida que la cadena sea solo de caracteres (a-z)
 * \param char* puntero a cadena a validar
 * \param int tamaño de la cadena a  validar
 * \return int retorna -1 en caso de error, 0 en caso contrario
 *
 */
int miValidacion_stringChar(char* cad, int tam);
