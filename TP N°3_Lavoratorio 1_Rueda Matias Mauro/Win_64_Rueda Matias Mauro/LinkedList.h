/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //constructor crea un nuevo linked  restornando su drieccion de memoria
int ll_len(LinkedList* this); //me dice el tamaño del linked
Node* test_getNode(LinkedList* this, int nodeIndex);//toma un nodo
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//agrega un nodo
int ll_add(LinkedList* this, void* pElement); //agrega un elemento al final de la lista
void* ll_get(LinkedList* this, int index);//toma una direccion de memoria del elemnto de la lista segun su indice
int ll_set(LinkedList* this, int index,void* pElement);//carga un elemento en la lista
int ll_remove(LinkedList* this,int index);//elimina un elemento de la lista segun su indice
int ll_clear(LinkedList* this);//limpia un elemento
int ll_deleteLinkedList(LinkedList* this);//elimina el linkedlist
int ll_indexOf(LinkedList* this, void* pElement);//busca el indice el elemento
int ll_isEmpty(LinkedList* this);// me dice si la lista esta vacia o no
int ll_push(LinkedList* this, int index, void* pElement);//agrega un elemento en un indice corriendo a los demas
void* ll_pop(LinkedList* this,int index); //saca al elemento de la lista pero el dato sigue existiendo en memoria
int ll_contains(LinkedList* this, void* pElement);//pregunta si el elemnto esta en la lista
int ll_containsAll(LinkedList* this,LinkedList* this2);//pregunta si la segunda lista esta en la primera
LinkedList* ll_subList(LinkedList* this,int from,int to); //me da un pedazo de la lista
LinkedList* ll_clone(LinkedList* this); //copia la lista en otra dire de memoria
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //ordena los elementos de la lista (ver order)
