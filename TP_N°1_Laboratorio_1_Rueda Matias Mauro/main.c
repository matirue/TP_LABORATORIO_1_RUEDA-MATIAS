/**********************************************************************************************
*
* Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*
*  1. Ingresar 1er operando (A=x)
*  2. Ingresar 2do operando (B=y)
*  3. Calcular todas las operaciones
*     a) Calcular la suma (A+B)
*     b) Calcular la resta (A-B)
*     c) Calcular la division (A/B)
*     d) Calcular la multiplicacion (A*B)
*     e) Calcular el factorial (A!)
*  4. Informar resultados
*     a) “El resultado de A+B es: r”
*     b) “El resultado de A-B es: r”
*     c) “El resultado de A/B es: r” o “No es posible dividir por cero”
*     d) “El resultado de A*B es: r”
*     e) “El factorial de A es: r1 y El factorial de B es: r2”
*  5. Salir
*
*  • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
*  que contenga las funciones para realizar las cinco operaciones.
*  • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
*  (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
*  • Deberán contemplarse los casos de error (división por cero, etc)
*  • Documentar todas las funciones
*
***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Funciones.h"



int main()
{
    float numero_A=0, numero_B=0;
    float  sol_Suma, sol_Resta, sol_Division, sol_Multiplicacion;
    char numFloat_aux_A[999999], numFloat_aux_B[999999];;

    int salir=0;

    do{
        //system("clear");
        system("cls");

        switch(menu("ERROR. Operacion invalida",1,5))
        {
            case 1:
                //system("clear");
                system("cls");
                while(getStringNumerosFlotantes("\n Ingrese numero A: ", numFloat_aux_A)==0 ||( (atoi(numFloat_aux_A))<-3.4028235E+38 || (atoi(numFloat_aux_A))>3.4028235E+38))
                    {
                        printf("\n VALOR INVALIDO! ");
                    }
                numero_A=atoi(numFloat_aux_A);

                //printf("\n\n++++++++     %.2f      ",numero_A);

                break;

            case 2:
                //system("clear");
                system("cls");
                while(getStringNumerosFlotantes("\n Ingrese numero B: ", numFloat_aux_B)==0 ||( (atoi(numFloat_aux_B))<-3.4028235E+38 || (atoi(numFloat_aux_B))>3.4028235E+38))
                    {
                        printf("\n VALOR INVALIDO! ");
                    }
                numero_B=atoi(numFloat_aux_B);

                //printf("\n\n++++++++     %.2f      ",numero_B);

                break;

            case 3:
                sol_Suma=suma(numero_A,numero_B);
                sol_Resta=resta(numero_A,numero_B);
                sol_Division=division(numero_A,numero_B);
                sol_Multiplicacion=multiplicacion(numero_A, numero_B);
                factorial(numero_A);

                printf("\n\n++++++ Calculos realizados con exitos ++++++\n\n");

                salir=0;
                system("pause");

                break;

            case 4:
                system("cls");
                //system("clear");
                printf("\n---------CALCULADORA---------\n");
                printf("a) %.1f + %.1f = %.1f \n",numero_A,numero_B,sol_Suma);
                printf("b) %.1f - %.1f = %.1f \n",numero_A,numero_B,sol_Resta);
                if(sol_Division==-799)
                    {
                        printf("c) Error, no se puede calcular la division para B=0.\n");
                    }
                else
                    {
                        printf("c) %.1f / %.1f = %.1f \n",numero_A,numero_B,sol_Division);
                    }
                printf("d) %.1f * %.1f = %.1f \n",numero_A,numero_B,sol_Multiplicacion);
                printf("e) %.0f ! = ",numero_A);
                mostrar_Factorial(numero_A);
                printf("\n\n");

                system("pause");

                break;

            case 5:
                salir=1;
                break;

            default:
                printf("\n\n ERROR. OPCION INVALIDA");

        }

    }while(salir!=1);
     printf("\n++++++++ ADIOS +++++++\n\n");

    return 0;
}
