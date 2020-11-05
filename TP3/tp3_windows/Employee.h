#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salarioStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_setIdTxt(Employee *this, char *id);
int employee_getId(Employee* this,int* id);
int employee_getIdTxt(Employee *this, char *id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee *this, char *horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getHorasTrabajadasTxt(Employee *this, char *horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoTxt(Employee *this, char *sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_getSueldoTxt(Employee *this, char *sueldo);

int employee_printEmployee(Employee *Empleado);

int employee_compareByNameAndId(void* Empleado1, void* Empleado2);
int employee_compareByID(void* Empleado1, void* Empleado2);

#endif // employee_H_INCLUDED
