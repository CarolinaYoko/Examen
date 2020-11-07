#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @brief Crea y retorna un puntero a employee. Es un constructor
 *
 * @return un puntero a employee en caso de exito, NULL en caso de error
 */
Employee* employee_new();

/**
 * @brief Crea y retorna un puntero a employee. Tambien carga los datos a la estructura. Es un constructor
 *
 * @param idStr char con id
 * @param nombreStr char con nombre
 * @param horasTrabajadasStr char con horas trabajadas
 * @param salarioStr char con el salario
 * @return un puntero a employee en caso de exito, NULL en caso de error
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salarioStr);

/**
 * @brief libera la memoria de la estructura
 *
 */
void employee_delete();

/**
 * @brief Carga el nombre de un empleado desde una variable Int
 *
 * @param this puntero al empleado
 * @param id entero con el ID a cargar en la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_setId(Employee* this,int id);

/**
 * @brief Carga el nombre de un empleado desde una variable Char
 *
 * @param this puntero al empleado
 * @param id char con el ID a cargar en la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_setIdTxt(Employee *this, char *id);

/**
 * @brief Obtiene el Id de un empleado y se guarda en una variable Int
 *
 * @param this puntero al empleado
 * @param id puntero a entero con el ID obtenido de la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_getId(Employee* this,int* id);

/**
 * @brief Obtiene el Id de un empleado y se guarda en una variable Char
 *
 * @param this puntero al empleado
 * @param id puntero a char con el ID obtenido de la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_getIdTxt(Employee *this, char *id);

/**
 * @brief Carga el nombre de un empleado desde una variable Char
 *
 * @param this puntero al empleado
 * @param nombre char con el nombre a cargar en la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @brief Obtiene el nombre de un empleado y se guarda en una variable Char
 *
 * @param this puntero al empleado
 * @param nombre puntero a char con el nombre obtenido de la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @brief Carga las horas trabajadas de un empleado desde una variable Int
 *
 * @param this puntero al empleado
 * @param horasTrabajadas entero con la cantidad de horas trabajadas a cargar en la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @brief Carga las horas trabajadas de un empleado desde una variable Char
 *
 * @param this puntero al empleado
 * @param horasTrabajadas char con la cantidad de horas trabajadas a cargar en la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_setHorasTrabajadasTxt(Employee *this, char *horasTrabajadas);

/**
 * @brief Obtiene las horas trabajadas de un empleado y se guarda en una variable Int
 *
 * @param this puntero al empleado
 * @param horasTrabajadas puntero a entero con la cantidad de horas trabajadas a obtener de la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @brief Obtiene las horas trabajadas de un empleado y se guarda en una variable Char
 *
 * @param this puntero al empleado
 * @param horasTrabajadas puntero a char con la cantidad de horas trabajadas a obtener de la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_getHorasTrabajadasTxt(Employee *this, char *horasTrabajadas);

/**
 * @brief Carga el sueldo de un empleado desde una variable Int
 *
 * @param this puntero al empleado
 * @param sueldo entero con el sueldo a cargar en la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @brief Carga el sueldo de un empleado desde una variable Char
 *
 * @param this puntero al empleado
 * @param sueldo char con el sueldo a cargar en la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_setSueldoTxt(Employee *this, char *sueldo);

/**
 * @brief Obtiene el sueldo de un empleado y se guarda en una variable Int
 *
 * @param this puntero al empleado
 * @param sueldo puntero a entero con el sueldo a obtener de la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @brief Obtiene el sueldo de un empleado y se guarda en una variable Char
 *
 * @param this puntero al empleado
 * @param sueldo puntero a char con el sueldo a obtener de la entidad
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_getSueldoTxt(Employee *this, char *sueldo);

/**
 * @brief Muestra id, nombre, horas trabjadas y sueldo de un empleado
 *
 * @param Empleado puntero al empleado
 * @return (-1) si hubo error, (0) si se realizo con exito
 */
int employee_printEmployee(Employee *Empleado);

/**
 * @brief Compara dos estructuras primero por nombre y luego por ID
 *
 * @param Empleado1 puntero al empleado a comparar
 * @param Empleado2 puntero al otro empleado a comparar
 * @return (1) si la primera estructura es mayor que la segunda, (-1) si es menor la primera y (0) si son iguales
 */
int employee_compareByNameAndId(void* Empleado1, void* Empleado2);

/**
 * @brief  Compara dos estructuras respecto al sueldo
 *
 * @param Empleado1 puntero al empleado a comparar
 * @param Empleado2 puntero al otro empleado a comparar
 * @return (1) si el primer sueldo es mayor que el segundo, (-1) si es menor, (0) si son iguales
 */
int employee_compareBySalary(void *Empleado1, void *Empleado2);

/**
 * @brief  Compara dos estructuras respecto al ID
 *
 * @param Empleado1 puntero al empleado a comparar
 * @param Empleado2 puntero al otro empleado a comparar
 * @return (1) si el primer ID es mayor que el segundo, (-1) si es menor, (0) si son iguales
 */
int employee_compareByID(void* Empleado1, void* Empleado2);

#endif // employee_H_INCLUDED
