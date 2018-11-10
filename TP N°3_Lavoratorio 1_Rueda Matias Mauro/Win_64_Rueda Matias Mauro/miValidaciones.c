#include "miValidaciones.h"


int getInt(int* pDato)
{
    int retorna=-1;
    char cadena[100];

    scanf("%s", cadena);
    if(input_esNumerico(cadena)==0)
    {
        *pDato = atoi(cadena);
        retorna=0;
    }
    return retorna;
}

int input_esNumerico(char* pDato)
{
    int retorna=-1, i, contPunto=0;
    char punto;

    for(i = 0; i < strlen(pDato); i++)
    {
        punto= pDato [i];
        if(punto == ',' || punto == '.')
        {
            punto = '.';
            contPunto++;
            if (contPunto == 1)
            {
                break;
            }
        }
        else if (punto < 48  || punto > 57)
        {
            break;
        }
        else
        {
            retorna=0;
        }
    }
    return retorna;
}

int input_getInt(int* pDato,int intentos, char* mensage, char* mensageError, int minimo, int maximo)
{
    int retorna=-1, aux, i;

    for(i=0;i<intentos;i++)
    {
        printf("%s", mensage);
        if(getInt(&aux) == 0)
        {
            if(aux >= minimo && aux <=maximo)
            {
                *pDato = aux;
                retorna=0;
                break;
            }
            else
            {
                printf("%s",mensageError);
                system("pause");
                //system("cls");
            }
        }
        else
        {
            printf("%s",mensageError);
            system("pause");

        }
    }
    return retorna;
}

char input_getChar (char* message)
{
    char dato;
    printf("%s",message);
    setbuf(stdin,NULL);
    scanf("%c",&dato);
    dato=tolower(dato);
    return dato;
}

int getString(char* pDato,int limite)
{
    int retorna=-1;
    char bufferString[4096];


    if (pDato!=NULL && limite>0)
    {
        setbuf(stdin,NULL);
        fgets (bufferString,sizeof(bufferString),stdin);
        if (bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString)<=limite)
        {
            strncpy(pDato,bufferString,limite);
            retorna=0;
        }
    }
    return retorna;
}

int input_esString (char* pDato)
{
    int retorna=-1, i;
    char c;

    for(i=0;i<strlen(pDato);i++)
    {
        c=pDato [i];
        if ((c<64  || c>91) && (c<60 || c>123))
        {
            break;
        }
        else
        {
            retorna= 0;
        }
    }
    return retorna;
}

int input_getString (char* pDato, int intentos, char* mensage, char* mensageError, int tam)
{
    int retorna=-1, i;
    char aux[tam];

    if(pDato!=NULL && tam>0)
    {
        for(i=0; i<intentos; i++)
        {
            printf("%s", mensage);
            if (getString(aux, tam)==0 && input_esString(aux)==0)
            {
                strncpy(pDato,aux,tam);
                retorna=0;
                break;
            }
            else
            {
                printf("%s", mensageError);
            }
        }
    }
    return retorna;
}


/************************************************************************/
int miValidacion_stringDeInt(char* cad, int tam)
{
    int retorna=-1, i;

    if(cad!=NULL && tam>0)
    {
        retorna=0;
        for(i=0;i<tam && cad[i]!='\0';i++)
        {
            if((cad[i]<'0') && (cad[i]>'9'))
            {
                retorna=-1;
                break;
            }
        }
    }
    return retorna;
}

int miValidacion_stringChar(char* cad, int tam)
{
    int retorna=-1, i, cantEspacio=0;

    if((cad!= NULL && tam > 0) && (strlen(cad) > 0))
    {
        retorna = 0;

        for (i=1;i<tam && cad[i]!='\0';i++)
        {
            switch(cad[i])
            {
            case 39:
                break;
            case 45:
                break;
            case 32:
                cantEspacio=i;
                if(cantEspacio!=0)
                {
                    cad[cantEspacio+1]=toupper(cad[cantEspacio+1]);
                }
                break;
            default:
                if((cad[i] < 97) || (cad[i] > 122))
                {
                    if((cad[i]<65) || (cad[i]>90))
                    {
                        retorna=-1;
                    }
                }
                break;
            }
        }
    }
    return retorna;
}
