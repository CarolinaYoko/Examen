#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"

static int esNumerica(char *cadena);
static int esNombre(char *cadena);

/**
 * @brief Determina si la cadena ingresada es numerica
 *
 * @param cadena
 * @return En caso de exito 1, sino 0
 */
static int esNumerica(char *cadena) {
	int retorno = 1;
	int i = 0;

	if (cadena[0] == '-') {
		i = 1;
	}
	for (; cadena[i] != '\0'; i++) {

		if (cadena[i] > '9' || cadena[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/**
 * @brief Determina si la cadena ingresada es un texto
 *
 * @param cadena
 * @return En caso de exito 1, sino 0
 */
static int esNombre(char *cadena) {
	int i;
	int retorno = 1;

	if (isspace(cadena[0])) {
		retorno = 0;
	}
	for (i = 0; cadena[i] != '\0'; i++) {

		if (!(isspace(cadena[i]) || isalpha(cadena[i]) || cadena[i] == '-')) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

Employee* employee_new() {
	Employee *p;
	void *retorno;

	p = (Employee*) malloc(sizeof(Employee));

	if (p != NULL) {

		if (employee_setId(p, 0) == 0 && employee_setNombre(p, '\0') == 0
				&& employee_setSueldo(p, 0) == 0
				&& employee_setHorasTrabajadas(p, 0) == 0) {
			retorno = p;
		}

	} else {
		retorno = NULL;
	}
	return retorno;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *salarioStr) {
	Employee *p;
	Employee *retorno;

	p = (Employee*) malloc(sizeof(Employee));

	if (p != NULL) {

		if (employee_setIdTxt(p, idStr) == 0
				&& employee_setNombre(p, nombreStr) == 0
				&& employee_setSueldoTxt(p, salarioStr) == 0
				&& employee_setHorasTrabajadasTxt(p, horasTrabajadasStr) == 0) {
			retorno = p;
		}

	} else {
		employee_delete(p);
		retorno = NULL;
	}
	return retorno;
}

void employee_delete(Employee *this) {
	if (this != NULL) {
		free(this);
	}
}

int employee_setId(Employee *this, int id) {
	int retorno = -1;
	if (this != NULL && id >= 0) {

		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_setIdTxt(Employee *this, char *id) {
	int vRetorno = -1;
	if (this != NULL && id >= 0) {
		if (esNumerica(id)) {
			this->id = atoi(id);
			vRetorno = 0;
		}
	}

	return vRetorno;
}

int employee_getId(Employee *this, int *id) {
	int vRetorno = -1;
	if (this != NULL && id >= 0) {
		*id = this->id;
		vRetorno = 0;
	}

	return vRetorno;
}
int employee_getIdTxt(Employee *this, char *id) {
	int vRetorno = -1;
	if (this != NULL && id >= 0) {
		sprintf(id, "%d", this->id);
		vRetorno = 0;
	}

	return vRetorno;
}

int employee_setNombre(Employee *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {

		if (esNombre(nombre)) {

			strncpy(this->nombre, nombre, 128);
			retorno = 0;
		}
	}
	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {
	int vRetorno = -1;
	if (this != NULL && nombre >= 0) {
		sprintf(nombre, "%s", this->nombre);
		vRetorno = 0;
	}

	return vRetorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno = -1;
	if (this != NULL && horasTrabajadas >= 0) {

		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadasTxt(Employee *this, char *horasTrabajadas) {
	int vRetorno = -1;
	if (this != NULL && horasTrabajadas >= 0) {
		if (esNumerica(horasTrabajadas)) {
			this->horasTrabajadas = atoi(horasTrabajadas);
			vRetorno = 0;
		}
	}

	return vRetorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int vRetorno = -1;
	if (this != NULL && horasTrabajadas >= 0) {
		*horasTrabajadas = this->horasTrabajadas;
		vRetorno = 0;
	}

	return vRetorno;
}

int employee_getHorasTrabajadasTxt(Employee *this, char *horasTrabajadas) {
	int vRetorno = -1;
	if (this != NULL && horasTrabajadas >= 0) {
		sprintf(horasTrabajadas, "%d", this->horasTrabajadas);
		vRetorno = 0;
	}

	return vRetorno;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int retorno = -1;
	if (this != NULL && sueldo >= 0) {

		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldoTxt(Employee *this, char *sueldo) {
	int vRetorno = -1;
	if (this != NULL && sueldo >= 0) {
		if (esNumerica(sueldo)) {
			this->sueldo = atoi(sueldo);
			vRetorno = 0;
		}
	}

	return vRetorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {
	int vRetorno = -1;
	if (this != NULL && sueldo >= 0) {
		*sueldo = this->sueldo;
		vRetorno = 0;
	}

	return vRetorno;
}
int employee_getSueldoTxt(Employee *this, char *sueldo) {
	int vRetorno = -1;
	if (this != NULL && sueldo >= 0) {
		sprintf(sueldo, "%d", this->sueldo);
		vRetorno = 0;
	}

	return vRetorno;
}

int employee_printEmployee(Employee *this) {

	int retorno = -1;
	int auxId;
	char auxNombre[128];
	int auxSueldo;
	int auxhorasTrabajadas;

	if (this != NULL) {

		employee_getId(this, &auxId);
		employee_getSueldo(this, &auxSueldo);
		employee_getNombre(this, auxNombre);
		employee_getHorasTrabajadas(this, &auxhorasTrabajadas);

		printf("\t | %4d | %15s | %18d | %10d |\n", auxId, auxNombre,
				auxhorasTrabajadas, auxSueldo);
		retorno = 0;
	}

	return retorno;

}

int employee_compareByID(void *Empleado1, void *Empleado2) {

	int retorno = 0;
	int Id1;
	int Id2;
	Employee *auxEmpleado1;
	Employee *auxEmpleado2;

	if (Empleado1 != NULL && Empleado2 != NULL) {

		auxEmpleado1 = (Employee*) Empleado1;
		auxEmpleado2 = (Employee*) Empleado2;

		employee_getId(auxEmpleado1, &Id1);
		employee_getId(auxEmpleado2, &Id2);

		if (Id1 > Id2) {
			retorno = 1;
		} else if (Id1 < Id2) {
			retorno = -1;
		}
	}
	return retorno;
}

int employee_compareBySalary(void *Empleado1, void *Empleado2) {

	int retorno = 0;
	int salary1;
	int salary2;

	Employee *auxEmpleado1;
	Employee *auxEmpleado2;

	if (Empleado1 != NULL && Empleado2 != NULL) {
		auxEmpleado1 = (Employee*) Empleado1;
		auxEmpleado2 = (Employee*) Empleado2;

		employee_getSueldo(auxEmpleado1, &salary1);
		employee_getSueldo(auxEmpleado2, &salary2);

		if (salary1 > salary2) {
			retorno = 1;
		} else if (salary1 < salary2) {
			retorno = -1;
		}
	}
	return retorno;
}

int employee_compareByNameAndId(void *Empleado1, void *Empleado2) {
	int retorno;
	char nombre1[128];
	char nombre2[128];
	Employee *auxEmpleado1;
	Employee *auxEmpleado2;

	if (Empleado1 != NULL && Empleado2 != NULL) {
		auxEmpleado1 = (Employee*) Empleado1;
		auxEmpleado2 = (Employee*) Empleado2;

		employee_getNombre(auxEmpleado1, nombre1);
	 	employee_getNombre(auxEmpleado2, nombre2);


		retorno = strcmp(nombre1, nombre2);

		if (retorno == 0) {
		retorno = employee_compareByID(Empleado1, Empleado2);
		}

	}
	return retorno;
}


//retorno = employee_compareBySalary(Empleado1, Empleado2);
