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
/**
 * @brief Crea y retorna un nuevo LinkedList. Es el contructor.
 *
 * @return retorna un nuevo LinkedList
 */
LinkedList* ll_newLinkedList(void);

/**
 * @brief Retorna el tamaño de la LinkedList y verifica que this sea distinto de  NULL
 *
 * @param this puntero al LinkedList
 * @return (-1) si la verificacion falla y si tiene exito retorna la longitud del array
 */
int ll_len(LinkedList* this);

/**
 * @brief Retorna un puntero al nodo que se encuentra en el indice especificado. Verifica que el puntero sea distinto de NULL y que index sea positivo e inferior al tamaño del array
 *
 * @param this puntero al LinkedList
 * @param nodeIndex indice del nodo buscado
 * @return (NULL) si la verificacion falla y si tiene exito retorna el puntero al nodo
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/**
 * @brief Agrega un nodo en la posicion indexNode. Verificando que el puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array
 *
 * @param this puntero al LinkedList
 * @param nodeIndex posicion donde agregaremos el nuevo nodo
 * @param pElement  elemento a agregar a la lista
 * @return (-1) si la verificacion falla y si tiene exito (0)
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * @brief Agrega un elemento al final de la LinkedList. Verifica que eel puntero this sea distinto de NULL
 *
 * @param this puntero al LinkedList
 * @param pElement puntero al elemento a agregar a la lista
 * @return Si la verificacion falla la funcion retorna (-1) y si tiene exito (0)
 */
int ll_add(LinkedList* this, void* pElement);

/**
 * @brief Retorna un puntero al elemento que se encuentra en el indice especificado. Verificando que el puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *
 * @param this puntero al LinkedList
 * @param index Si la verificacion falla retorna NULL y si tiene exito retorna el elemento
 */
void* ll_get(LinkedList* this, int index);

/**
 * @brief Inserta un elemento en el LinkedList, en el indice especificado
 *
 * @param this puntero al LinkedList
 * @param index entero que indica el indice del nodo a actualizar
 * @param pElement puntero al elemento de la lista a actualizar
 * @return Si la verificacion falla retorna (-1) y exito (0)
 */
int ll_set(LinkedList* this, int index,void* pElement);

/**
 * @brief Elimina un elemento del LinkedList, en el indice especificado. Verificando que el puntero this sea distinto de  NULL y que index sea positivo e inferior al tamaño del array
 *
 * @param this puntero al LinkedList
 * @param index entero que indica el indice del nodo a eliminar
 * @return Si la verificacion falla la funcion retorna (-1) y si tiene exito (0)
 */
int ll_remove(LinkedList* this,int index);

/**
 * @brief Borra todos los element
 *
 * @param this puntero a LinkedList
 * @return Si la verificacion falla la funcion retorna (-1) y si tiene exito (0)
 */
int ll_clear(LinkedList* this);

/**
 * @brief Elimina el LinkedList. Verificando que el puntero this sea distinto de NULL.
 *
 * @param this puntero al LinkedList
 * @return Si la verificacion falla la funcion retorna (-1), si esta vacio (1) y si contiene elementos(0)
 */
int ll_deleteLinkedList(LinkedList* this);

/**
 * @brief Retorna el indice de la primera aparicion de un elemento
 *
 * @param this puntero al LinkedList
 * @param pElement puntero al elemento de la lista a encontrar el indice
 * @return Si la verificacion falla o no encunetra el elemento la funcion retorna (-1) y si encuentra el elemento retorna su indice
 */
int ll_indexOf(LinkedList* this, void* pElement);

/**
 * @brief Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero this sea distinto de NULL.
 *
 * @param this puntero al LinkedList
 * @return Si la verificacion falla la funcion retorna (-1), si esta vacio (1) y si contiene elementos (0)
 */
int ll_isEmpty(LinkedList* this);

/**
 * @brief Desplaza los elementos e inserta en la posicion index. Verificando que el puntero this sea distinto de NULL y index sea positivo e inferior al tamaño del array
 *
 * @param this puntero al LinkedList
 * @param index entero que indica el indice donde ubicaremos el nuevo elemento
 * @param pElement puntero al elemento de la lista a desplazar
 * @return (-1) si la verificacion falla y si tiene exito (0)
 */
int ll_push(LinkedList* this, int index, void* pElement);

/**
 * @brief Retorna un puntero al elemento que se encuentra en el indice especificado y luego lo elimina de la lista.
 * Verificando que el puntero this sea NULL y que index sea positico e inferior al tamaño del array. Si la verificacion falla la funcion retorna (NULL) y si tiene exito retorna el elemento
 *
 * @param this  puntero al LinkedList
 * @param index entero que indica el indice que se eliminara
 */
void* ll_pop(LinkedList* this,int index);

/**
 * @brief Comprueba si existe el elemento que se le pasa como parametro. Verificando que tanto el puntero this como element sean distintos de NULL.
 *
 * @param this puntero al LinkedList
 * @param pElement puntero al elemento de la lista que se desea comprobar si existe
 * @return Si la verificacion falla la funcion retorna (-1), si encuentra el elemento (1) y si no lo encuentra (0)
 */
int ll_contains(LinkedList* this, void* pElement);

/**
 * @brief Comprueba si los elementos pasados son contenidos por el LinkedList. Verificando que tanto el puntero this como this2 sean distintos de NULL.
 *
 * @param this  puntero al LinkedList
 * @param this2  puntero al LinkedList
 * @return Si la verificacion falla o no encuentra el elemento la funcion retorna (-1), si las lista difieren (0) y si ambas listas son iguales retorna (1)
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/**
 * @brief Retorna un nuevo LinkedList con el subconjunto de elementos.
 * Verificando que el puntero this sea distinto de NULL y que tanto el indice "from" como "to" sean positivos e inferiores al tamaño del array.
 *
 * @param this  puntero al LinkedList
 * @param from entero que indica el indice de partida
 * @param to entero que indica el indice de llegada
 * @return Si la verificacion falla la funcion retorna (NULL) y si tiene exito retorna el nuevo array
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/**
 * @brief Retorna un nuevo LinkedList copia del LinkedList original. Verificando que el puntero this sea distinto de NULL.
 *
 * @param this puntero al LinkedList
 * @return Si la verificacion falla la funcion retorna (NULL) y si tiene exito retorna el nuevo array.
 */
LinkedList* ll_clone(LinkedList* this);

/**
 * @brief Ordena los elementos del array recibiendo como parametros la funcion que sera la encargada de determinar que elemento es mas grande que otro y si se debe ordenar de manera ascendente o descendente.
 * Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL
 *
 * @param this puntero al LinkedList
 * @param pFunc puntero a funcion que determina el criterio de ordenamiento.
 * @param order (0) descendente (1) ascendente
 * @return Si la verificacion falla (-1) caso contrario retorna (1)
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
