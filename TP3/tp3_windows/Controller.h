#ifndef CONTROLLER
#define CONTROLLER

#include "Employee.h"
#include "LinkedList.h"

/**\brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo .csv
 * \param pArrayListEmployee LinkedList*
 * \param maxId*
 * \return int En caso de exito retorna 0 , en caso de error(-1)
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee, int* maxId);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* ruta del archivo .bin
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna 0, en caso de error(-1)
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee, int* maxId);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna 0, en caso de error(-1)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int *idEmpleado);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna 0, en caso de error(-1)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna 0, en caso de error(-1)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna 0, en caso de error(-1)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna 0, en caso de error(-1)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo .csv
 * \param pArrayListEmployee LinkedList*
 * \return int  En caso de exito retorna 0, en caso de error(-1)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* ruta del archivo .bin
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna 0, en caso de error(-1)
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



#endif

