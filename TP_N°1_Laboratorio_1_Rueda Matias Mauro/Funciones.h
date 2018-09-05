/******************************************************************************************************************************************************/
/**
 * \brief Pide un texto al usuario y lo devuelve
 * \param char Es el texto a ser mostrado
 * \param char Es el Array donde se cargara el texto pedido
 * \return void
 */
 void getString(char [], char []);

/**
* \brief Verifica si el valor recibido es numérico aceptando flotantes
* \param char Array con la cadena a ser analizada
* \return int 1 si es númerico y 0 si no lo es
*/
int esNumericoFlotante(char []);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param char Es el mensaje a ser mostrado
 * \param char Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char [],char []);

/******************************************************************************************************************************************************/

/** \brief Funcion menu que listara opciones y pedira un entero
 * \param char Mensage a mostrar en caso de error
 * \param int Valor minimo a validar
 * \param int Valor maximo a validar
 * \return int Retorna el entero ingresado
 */
int menu(char [], int , int );

/******************************************************************************************************************************************************/

/** \brief Funcion que suma dos valores
 * \param float Primer valor
 * \param float Segundo valor
 * \return float Resultado de la suma
 */
float suma (float numero_A, float numero_B);

/** \brief Funcion que resta dos valores
 * \param float Primer valor
 * \param float Segundo valor
 * \return float Resultado de la resta
 */
float resta (float numero_A, float numero_B);

/** \brief Funcion que multiplica dos valores
 * \param float Primer valor
 * \param float Segundo valor
 * \return float Resultado de la multiplicacion
 */
float multiplicacion (float numero_A, float numero_B);

/** \brief Funcion que divide dos valores
 * \param float Primer valor
 * \param float Segundo valor
 * \return float Resultado de la division
 */
float division (float numero_A, float numero_B);

/******************************************************************************************************************************************************/

/** \brief Funcion que recibe un numero y calcula su factorial
 * \param float Numero recibido
 * \return int Retorna el resultado del factorial
 */
int factorial(float );

/** \brief Funcion que muestra el factorial calculado
 * \param float Numero recibido
 * \return int Retorna el resultado del factorial
 */
int mostrar_Factorial(float );

