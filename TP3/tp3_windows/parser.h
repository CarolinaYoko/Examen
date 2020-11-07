#ifndef PARSER_H_
#define PARSER_H_


/** \brief Realiza la conversion de  los datos de los empleados desde el archivo data.csv (modo texto) y los guarda en una estructura
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna el Id maximo, en caso de error(-1)
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

/** \brief Realiza la conversion de  los datos de los empleados desde el archivo data.csv (modo binario) y los guarda en una estructura
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int En caso de exito retorna el Id maximo, en caso de error(-1)
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

#endif /* PARSER_H_ */
