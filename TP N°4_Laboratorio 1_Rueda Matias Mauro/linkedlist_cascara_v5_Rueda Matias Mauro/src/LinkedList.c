#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex); ///funcion interna del linkedList
static int addNode(LinkedList* this, int nodeIndex,void* pElement); ///funcion interna del linkedList

/************************************************************************************************************************/

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/************************************************************************************************************************/

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
        {///si this no es nulo en returnAux cargo la cantidad de elemento que tiene mi linkedlist
            returnAux=this->size;
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    /// verifico q this no sea NULL y el indice sea mayor a 0 y menor al tamaño de la lista
    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this) )
        {   ///asigno el primer nodo a pNode
            pNode=this->pFirstNode;
            ///Recorre hasta el indice ingresado, y lo asigna a pnode
            for(i=0;i<nodeIndex;i++)
                {
                    pNode=pNode->pNextNode;
                }
        }
    return pNode;
}

/************************************************************************************************************************/

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/************************************************************************************************************************/

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    ///uso un puntero a un nuevo nodo, lo creo pidiendo memoria
    Node* pNewNode=NULL;
    pNewNode=(Node*)malloc(sizeof(Node));

    ///uso del punteros a nodos, uno para el nodo anterio y otro para el nodo siguiente
    Node* pastNode=NULL;
    Node* nextNode=NULL;
    ///valido para los 3 casos
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
        {    ///para el caso de que el indice sea 0
            if(nodeIndex==0)
                {   ///al pNextNode del pNewNode le doy la direccion del primero nodo
                    pNewNode->pNextNode=this->pFirstNode;
                    ///actualizo pFirstNode por la direccion del nuevo nodo
                    this->pFirstNode=pNewNode;
                    ///aumento el size
                    this->size++;
                    returnAux=0;
                }
                else///caso del indice mayor a cero y menor al tamaño de la lista
                    {   ///a pastNode le asigno ( con getNode )el nodo anterio al que agrego pasando el  indice-1
                        pastNode=getNode(this,nodeIndex-1);
                        ///a nextNode le cargo la dire de memoria
                        nextNode=pastNode->pNextNode;
                        ///al pastNodo le cargo la direccion del nuevo nodo
                        pastNode->pNextNode=pNewNode;
                        ///al nuevo nodo le asigno el nodo que le sigue
                        pNewNode->pNextNode=nextNode;
                        ///aumento el size
                        this->size++;
                        returnAux=0;
                    }
                    ///le asigno el elemento del nuevo nodo
                    pNewNode->pElement=pElement;
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/************************************************************************************************************************/

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    ///si la lista no es nulo entro
    if(this!=NULL)
        {   ///llamo a addNode pasando lista, indice y el emelmento
            //returnAux=addNode(this,this->size,pElement);
            returnAux=addNode(this,ll_len(this),pElement);
        }   ///retornara 0 si addNode se ejeecuto correctamente, -1 en caso de erro

    return returnAux;
}

/************************************************************************************************************************/

/** \brief Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    /// puntero a nodo utilizado para el test
    Node* pNode=NULL;
    ///valido q this no sea null, indice sea mayor o igual a cero y menor al tamaño de la lista
    if(this!=NULL && index>=0 && index<ll_len(this))
        {   ///pido un nodo con el indice
            pNode=getNode(this,index);
            ///le asigno el valor del pelement
            returnAux=pNode->pElement;
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    ///puntero a nodo para realizar el seteo
    Node* pNewNode=NULL;
    ///valido q this no sea null, indice sea mayor o igual a cero y menor al tamaño de la lista
    if(this!=NULL && index>=0 && index<ll_len(this))
        {   ///pido el nodo que se encuentra en el indice ingresado
            pNewNode=getNode(this,index);
            ///valido si getnode no me devuelve un null en caso de que en ese indice no exista un nodo
            if(pNewNode!=NULL)
                {   ///piso el elemento por el nuevo
                    pNewNode->pElement=pElement;
                    returnAux=0;
                }
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    ///puntero a nodo para eliminar su elemento
    Node* pNewNode=NULL;
    ///puntero a nodo auxiliar
    Node* pPastNode=NULL;
    ///valido q this no sea null, indice sea mayor o igual a cero y menor  al tamaño de la lista
    if(this!=NULL && index>=0 && index<=ll_len(this))
        {   ///caso indice igual a cero
            if(index==0)
                {   ///pido el nodo en ese indice
                    pNewNode=getNode(this,index);
                    ///valido q getnode no devuelva null
                    if(pNewNode!=NULL)
                        {   ///a pFirstNode le asigno la direccion del nodo siguente al que voy a liberar
                            this->pFirstNode=pNewNode->pNextNode;
                            ///libero el nodo
                            free(pNewNode);
                            this->size--;
                            ///resto uno al size
                            returnAux=0;
                        }
                }
             else if(index>0 && index<=ll_len(this))
                {   ///pido el nodo anterior al indice agregado
                    pPastNode=getNode(this,index-1);
                    ///pido el nodo del indice agregado
                    pNewNode=getNode(this,index);
                    ///valido que ninguno de los dos me de NULL
                    if(pPastNode!=NULL && pNewNode!=NULL)
                        {   ///al nodo anterior le asigno la direccion del nodo siguente al que voy a liberar
                            pPastNode->pNextNode=pNewNode->pNextNode;
                            ///libero el nodo
                            free(pNewNode);
                            ///resto uno al size
                            this->size--;
                            returnAux=0;
                        }
                }

        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i, tam_lista;
    ///verifico q this no sea NULL
    if(this!=NULL)
        {  ///pido el tamaño de la lista
           tam_lista=ll_len(this);
           ///recorro toda la lista
           for(i=0;i<tam_lista;i++)
            {   ///llamo a la funcion ll_remove y elimino cada nodo
                returnAux=ll_remove(this,i);
            }
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    ///verifico q this no sea NULL
    if(this!=NULL)
        {   ///libero los nodos
            if(ll_clear(this)==0)
                {
                   ///libero la lista
                   free(this);
                   returnAux=0;
                }
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    ///puntero a nodo auxiliar
    Node* pNode=NULL;
    int i, tam_lista;
    ///verifico q this no sea NULL
    if(this!=NULL)
        {  ///pido el tamaño de la lista
           tam_lista=ll_len(this);
           ///recorro toda la lista
           for(i=0;i<tam_lista;i++)
            {   ///asigno nodo a pnode con getnode por cada indice
                pNode=getNode(this,i);
                ///valido q pnode no sea NULL
                if(pNode!=NULL)
                    {
                        ///comparo los elementos
                        if(pNode->pElement==pElement)
                            {   ///retorno el indice donde se da la igualdad y rompo el bucle
                                returnAux=i;
                                break;
                            }
                    }
            }
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
     ///verifico q this no sea NULL
    if(this!=NULL)
        {    //caso 1
            ///pregunto si el siz de lista es nulo
             if(this->size == 0)
                {
                    returnAux=1;
                }
            else///this no esta vacio
                {
                    returnAux=0;
                }
           /*
           caso 2
           ///pregunto si this esta vacio
            if(ll_len(this)==0)
                {
                    returnAux=1;
                }
            else///this no esta vacio
                {
                    returnAux=0;
                }

            caso 3
            if(this->pFirstNode == NULL)
                    {
                    returnAux=1;
                }
            else///this no esta vacio
                {
                    returnAux=0;
                }
             */
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    ///valido q this no sea null, indice sea mayor o igual a cero y menor  al tamaño de la lista
    if(this!=NULL && index>=0 && index<=ll_len(this))
        {   ///llamo a addnode y agrego el pelement
            returnAux=addNode(this,index,pElement);
        }

    return returnAux;
}

/************************************************************************************************************************/

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    ///valido q this no sea null, indice sea mayor o igual a cero y menor  al tamaño de la lista
    if(this!=NULL && index>=0 && index<=ll_len(this))
        {   /// pido el nodo del indie, y lo retorno
            returnAux=ll_get(this,index);
            ///si el retorno es distinto de NULL
            if(returnAux!=NULL)
                {
                    ///libero el nodo del indice ingresado de la lista
                    ll_remove(this,index);
                }
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    ///puntero a nodo auxiliar
    Node* pNode=NULL;
    ///verifico q this no se NULL
    if(this!=NULL)
        {   ///retorno cero en caso de que encuentr coincidencia
            returnAux=0;
            ///pido indice de pElement
            index=ll_indexOf(this,pElement);
            ///verifico si encontro el elemento
            if(index!=-1)
                {
                     returnAux=1;
                }
        }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    ///Puntero a nodo auxiliar
    void* pElement_this=NULL;
    //Node* pElement_this=NULL;
   int i, tam_lita1, tam_lita2, returnLista1;
   ///verifico que ambos thiss no sean NULL
   if(this!=NULL && this2!=NULL)
    {   ///pido los tamaños de cada lista
        tam_lita1=ll_len(this);
        tam_lita2=ll_len(this2);
        returnAux=1;
        ///valido que this2 no sea mayor a this
        if(tam_lita1<tam_lita2)
            {   ///recorro this2
                for(i=0;i<tam_lita2;i++)
                 {  ///pido un elemento
                    pElement_this=ll_get(this2,i);
                    ///verifico que ese elemento este en this
                    returnLista1=ll_contains(this,pElement_this);
                    ///segun lo retornado cambio el estado de returnaux
                    if(returnLista1==0)
                      {
                          returnAux=0;
                          break;
                      }
                    else if(returnLista1==1)
                      {
                          returnAux=1;
                      }
                  }

            }
    }
    return returnAux;
}

/************************************************************************************************************************/

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    ///puntero a la lista clonada que retorna
    LinkedList* cloneArray = NULL;
    ///puntero auxiliar a cada elemento a usar
    void* pNewList=NULL;

    int tam_list, i;
    ///verifico que la lista no sea NULL
    if(this!=NULL)
        {   ///pido el tamaño de la lista
            tam_list=ll_len(this);
            ///verifico que from sea mayor o igual a 0 y menor al tamaño de la lista
            ///verifico q to sea mayor o igual al from y menor o igual al tamaño de la lista
            if(from>=0 && from<tam_list && to>=from && to<=tam_list )
                {   ///llamo al constructor para mi nueva lista
                    cloneArray=ll_newLinkedList();
                    ///recorro this segun los datos ingresados
                    for(i=from;i<to;i++)
                        {  ///pido cada elemento de la lista segun el indice ingresado
                           pNewList=ll_get(this,i);
                           ///agrego cada elemento pedido a la nueva lista
                           ll_add(cloneArray, pNewList);
                        }
                }
        }
    return cloneArray;
}


/************************************************************************************************************************/


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
   /* ///puntero auxiliar a cada elemento a usar
    void* pNewList=NULL;
    int tam_list, i;
    ///verifica que this sea distinto de NULL
    if(this!=NULL)
        {   ///pido tamaño de la lista
            tam_list=ll_len(this);
            ///llamo al constructo para mi nueva lista
            cloneArray=ll_newLinkedList();
            ///recorro la lista
            for(i=0;i<tam_list;i++)
                {   ///pido cada elemento de la lista segun el indice ingresado
                    pNewList=ll_get(this, i);
                    ///agrego cada elemento pedido a la nueva lista
                    ll_add(cloneArray,pNewList);
                }
        }*/

        if(this!=NULL)
            {
                cloneArray=ll_subList(this,0,ll_len(this));
            }
    return cloneArray;
}


/************************************************************************************************************************/

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    ///punteros a nodos donde copiare cada elemento para ordenar
    void* pNodo_1=NULL;
    void* pNodo_2=NULL;
    void* pAux=NULL;

    int tam_lista,i,j;
    ///valido q this y la pFunc no sean NULL
    if(this!=NULL && pFunc!=NULL)
        {   ///valido que erder reciva los datos validos
            if(order==1 || order==0)
                {   ///pid tamaño de la lista
                    tam_lista=ll_len(this);
                    ///recorro la lista desde el inicio  hasta el ultimo menos uno
                    for(i=0;i<tam_lista-1;i++)
                        {   ///pido los elementos
                            pNodo_1=ll_get(this,i);
                            ///recorro la lista desde el indice mas uno hasta el final de la lista
                            for(j=i+1;j<tam_lista;j++)
                                {   ///pido los elementos
                                    pNodo_2=ll_get(this,j);
                                    ///ordeno de manera ascendente
                                    if(order==1)
                                        {
                                            if(pFunc(pNodo_1,pNodo_2)>0)
                                               {
                                                    pAux=pNodo_1;
                                                    pNodo_1=pNodo_2;
                                                    pNodo_2=pAux;
                                               }
                                        }
                                     ///ordeno de manera descendente
                                     else
                                        {
                                            if(pFunc(pNodo_1,pNodo_2)<0)
                                               {
                                                    pAux=pNodo_2;
                                                    pNodo_2=pNodo_1;
                                                    pNodo_1=pAux;
                                               }
                                        }
                                     ///seteo los elementos ordenaos
                                     ll_set(this,i,pNodo_1);
                                     ll_set(this,j,pNodo_2);

                                }
                        }
                returnAux=0;

                }
        }

    return returnAux;

}


/************************************************************************************************************************/
