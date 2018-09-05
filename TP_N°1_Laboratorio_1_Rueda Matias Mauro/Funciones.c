#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
/******************************************************************************************************************************************************/
 void getString(char message[], char text[])
 {
    printf("%s", message);
    setbuf(stdin, NULL);
    scanf("%[^\n]", text);
    //gets(text);
    //pause_Linux();
 }

int esNumericoFlotante(char dato[])
{
   int i=0;
   int cantidadPuntos=0;
   while(dato[i] != '\0')
   {
       if (dato[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(dato[i] < '0' || dato[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/******************************************************************************************************************************************************/
int menu(char messageError [], int minimo, int maximo)
{
    int opcion_aux, opcion=0;

    printf("---------CALCULADORA---------\n\n");
    printf("1. Ingresar 1er operando A ");
    printf("\n2. Ingresar 2do operando B ");
    printf("\n3. Calcular todas las operaciones:\n    a)Suma (A+B)\n    b)Resta (A-B)\n    c)Division (A/B)\n    d)Multiplicacion (A*B)\n    e)Factorial (A!)");
    printf("\n4. Informar todos resultados");
    printf("\n5. Salir\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion_aux);

    if(opcion_aux>=minimo && opcion_aux<=maximo)
        {
            opcion=opcion_aux;
        }
    else
        {
            printf("\n\n %s \n\n", messageError);
            getch()!='n';
        }

    return opcion;
}
/******************************************************************************************************************************************************/

float suma (float numero_A, float numero_B)
{
    float solucion;

    solucion=numero_A+numero_B;

    return solucion;
}

/******************************************************************************************************************************************************/

float resta (float numero_A, float numero_B)
{
    float solucion;

    solucion=numero_A-numero_B;

    return solucion;
}

/******************************************************************************************************************************************************/

float multiplicacion (float numero_A, float numero_B)
{
    float solucion;

    solucion=numero_A*numero_B;

    return solucion;
}

/******************************************************************************************************************************************************/

float division (float numero_A, float numero_B)
{
    float solucion;
    //char numFloat_aux_B[999999];

    if(numero_B==0)
        {
            printf("\n ERROR. El valor de B no puede ser cero para la division. ");

            solucion=-799; /**Se que no es correcto, pero no se me ocurre como hacer para q salga el mensaje en este caso
                           por eso elegi un valor dificil de acertar para que salga este mensaje**/

            system("pause");
        }
        else
            {
                solucion=numero_A/numero_B;
            }

        return solucion;
}

/******************************************************************************************************************************************************/

int factorial(float numero_A)
{
    int solucion,fac_aux;
    fac_aux=numero_A;
    fac_aux=(int)fac_aux;

    if(numero_A<0 || fac_aux!=numero_A)
    {
        solucion= -1;
    }
    else
    {
        if(numero_A==0)
        {
            solucion= 1;
        }
        else
        {
            solucion=numero_A*factorial(numero_A-1); //vuelvo a llamar a la funcion
        }
    }
    return solucion;
}

int mostrar_Factorial(float numero_A)
{
    int solucion=factorial(numero_A); //llamo a la funcion factorial

    if(factorial==-1) //acodate que es la funcion anterior
    {
        printf("\n\n   ERROR   \n\n");
    }
    else
    {
        printf(" %d  \n",solucion);
    }
    return solucion;
}

/******************************************************************************************************************************************************/



