#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TAM 5
#define LEN 51
#define TRUE 0
#define FALSE 1
#define UP 1
#define DOWN 0

struct {
	int id;
	char name[LEN];
	char lastName[LEN];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int initEmployees(Employee *list, int len);
int auxiliarAdd(Employee *Aux);
int addEmployee(Employee *list, int len, int id, char *name, char *lastName,float salary, int sector);
int printEmployees(Employee *list, int len);
int findEmployeeById(Employee *list, int len, int id);
int updateEmployee(Employee *list, int len);
int removeEmployee(Employee *list, int len);
int sortEmployees(Employee *list, int len, int order);
int acumularSalario(Employee *list, int len, float *acumulador);
int calcularPromedioSalario(Employee *list, int len, float* promedio);
int cuentaSuperaSalarioPromedio(Employee *list, int len, float promedio, int* contador);


#endif /* ARRAYEMPLOYEES_H_ */



