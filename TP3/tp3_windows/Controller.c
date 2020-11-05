#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "UTN.h"
#include "parser.h"

static int findEmployeeById(LinkedList *pArrayListEmployee, Employee **this,
		int id);
static int findIndexById(LinkedList *pArrayListEmployee, int *index, int id);

/**
 * @brief
 *
 * @param pArrayListEmployee
 * @param index
 * @param id
 * @return
 */
static int findIndexById(LinkedList *pArrayListEmployee, int *index, int id) {
	int len;
	int i;
	int retorno = -1;
	int auxId;
	Employee *auxEmpleado;

	if (pArrayListEmployee != NULL && index != NULL && id > 0) {
		len = ll_len(pArrayListEmployee);

		for (i = 0; i < len; i++) {

			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

			if (employee_getId(auxEmpleado, &auxId) == 0 && auxId == id) {

				*index = i;
				break;
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * @brief
 *
 * @param pArrayListEmployee
 * @param this
 * @param id
 * @return
 */
static int findEmployeeById(LinkedList *pArrayListEmployee, Employee **this,
		int id) {

	int auxIndex;
	int retorno = -1;

	if (pArrayListEmployee != NULL && this != NULL && id > 0) {

		if (findIndexById(pArrayListEmployee, &auxIndex, id) == 0) {

			*this = (Employee*) ll_get(pArrayListEmployee, auxIndex);
		}
		retorno = 0;
	}

	return retorno;
}

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee,
		int *maxId) {

	int retorno = -1;
	FILE *fp;
	int len;
	int bufferId;

	if (pArrayListEmployee != NULL && path != NULL) {
		len = ll_len(pArrayListEmployee);
		if (len == 0) {

			fp = fopen("data.csv", "r");
			if (fp != NULL) {

				bufferId = parser_EmployeeFromText(fp, pArrayListEmployee);

				if (bufferId > 0) {

					*maxId = bufferId;
					printf("Carga exitosa \n");
					retorno = 0;
				}
			}
			fclose(fp);
		} else {
			printf("Ya se realizo la carga \n");
		}
	}
	system("pause");
	return retorno;
}

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee,
		int *maxId) {

	FILE *fp;
	int bufferId;
	int retorno = -1;
	int len;

	if (pArrayListEmployee != NULL && path != NULL) {
		len = ll_len(pArrayListEmployee);

		if (len == 0) {
			fp = fopen(path, "rb");

			if (fp != NULL) {

				bufferId = parser_EmployeeFromBinary(fp, pArrayListEmployee);
				if (bufferId > 0) {
					*maxId = bufferId;
					printf("Carga exitosa \n");
					retorno = 0;
				}
			}
			fclose(fp);
		} else {
			printf("Ya se realizo la carga \n");
			retorno = -1;
		}
	}
	system("pause");
	return retorno;
}

int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int len;
	int i;
	Employee *aux;

	if (pArrayListEmployee != NULL) {

		len = ll_len(pArrayListEmployee);

		if (len != 0) {

			printf("| %6s | %4s | %15s | %18s | %10s |\n", "Indice", "ID",
					"Nombre", "Horas trabajadas", "Sueldo");

			for (i = 0; i < len; i++) {
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				printf("| %3d ", i + 1);
				employee_printEmployee(aux);
			}
			retorno = 0;
		} else {
			printf("No hay datos cargados \n");
		}
	}
	system("pause");
	return retorno;
}

int controller_addEmployee(LinkedList *pArrayListEmployee, int *idEmpleado) {
	Employee *Empleado;
	Employee auxEmployee;
	char auxId[4096];
	char auxHorasT[4096];
	char auxSalario[4096];
	int retorno = -1;
	int len;

	if (pArrayListEmployee != NULL && idEmpleado != NULL) {
		len = ll_len(pArrayListEmployee);

		if (len != 0) {
			if (utn_getTexto(auxEmployee.nombre, "\nIngrese nombre: ",
					"El nombre ingresado no es valido. Reingrese\n", 1, 128, 2)
					== 0
					&& utn_getNumeroIntMin(&auxEmployee.horasTrabajadas,
							"\nIngrese las horas trabajadas: ",
							"El numero ingresado no es valido. Reingrese\n", 1,
							2) == 0
					&& utn_getNumeroIntMin(&auxEmployee.sueldo,
							"\nIngrese el sueldo: ",
							"El numero ingresado no es valido. Reingrese\n", 1,
							2) == 0) {

				(*idEmpleado)++;
				auxEmployee.id = *idEmpleado;
				sprintf(auxId, "%d", auxEmployee.id);
				sprintf(auxHorasT, "%d", auxEmployee.horasTrabajadas);
				sprintf(auxSalario, "%d", auxEmployee.sueldo);
				fflush(stdin);

				Empleado = employee_newParametros(auxId, auxEmployee.nombre,
						auxHorasT, auxSalario);
				if (Empleado != NULL) {
					ll_add(pArrayListEmployee, Empleado);
					retorno = 0;
				}
			}
		} else {
			printf("No hay datos cargados \n");
		}
	}
	system("pause");
	return retorno;
}

int controller_editEmployee(LinkedList *pArrayListEmployee) {

	int retorno = -1;
	int id;
	int opcion;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	int len;
	Employee *auxEmployee;

	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		if (len != 0) {
			if (controller_ListEmployee(pArrayListEmployee) == 0
					&& utn_getNumeroIntMin(&id,
							"Ingrese el ID del empleado a modificar: \n",
							"El numero ingresado no es valido. Reintente \n", 1,
							2) == 0) {

				if (findEmployeeById(pArrayListEmployee, &auxEmployee, id)
						== 0) {

					printf("Opciones:\n"
							"1.Nombre \n"
							"2.Horas trabajadas \n"
							"3.Sueldo \n");

					if (utn_getNumeroInt(&opcion,
							"Ingrese el campo a modificar: \n",
							"El numero ingresado no es valido. Reintente \n", 1,
							3, 2) == 0) {
						switch (opcion) {
						case 1:
							if (utn_getTexto(auxNombre, "Ingrese el nombre: ",
									"El nombre ingresado no es valido. Reintente",
									1, 128, 2) == 0
									&& employee_setNombre(auxEmployee,
											auxNombre) == 0) {
								printf("El nombre fue modificado");
							}
							break;
						case 2:
							if (utn_getNumeroIntMin(&auxHoras,
									"Ingrese la cantidad de horas: \n",
									"La cantidad ingresada no es valida. Reintente \n",
									1, 2) == 0
									&& employee_setHorasTrabajadas(auxEmployee,
											auxHoras) == 0) {
								printf(
										"Las horas trabajadas fueron modificadas");
							}
							break;
						case 3:
							if (utn_getNumeroIntMin(&auxSueldo,
									"Ingrese el sueldo: \n",
									"La cantidad ingresada no es valida. Reintente \n",
									1, 2) == 0
									&& employee_setSueldo(auxEmployee,
											auxSueldo) == 0) {
								printf("El sueldo fue modificado");
							}
							break;
						}

					}
					controller_ListEmployee(pArrayListEmployee);
					retorno = 0;
				}
			}
		} else {
			printf("No hay datos cargados \n");
		}
	}
	system("pause");
	return retorno;
}

int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int auxId;
	int index;
	int len;

	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		if (len != 0) {
			if (controller_ListEmployee(pArrayListEmployee) == 0
					&& utn_getNumeroIntMin(&auxId,
							"Seleccione el ID a remover: \n",
							"El numero ingresado no es valido. Reintente \n", 1,
							2) == 0) {
				findIndexById(pArrayListEmployee, &index, auxId);
				ll_remove(pArrayListEmployee, index);
				retorno = 0;
			}
		} else {
			printf("No hay datos cargados \n");
		}
	}
	system("pause");
	return retorno;
}

int controller_sortEmployee(LinkedList *pArrayListEmployee) {

	int retorno = -1;
	int len;
	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		if (len != 0) {
			ll_sort(pArrayListEmployee, employee_compareByNameAndId, 1);
			controller_ListEmployee(pArrayListEmployee);
			retorno = 0;
		} else {
			printf("No hay datos cargados \n");
		}
	}
	system("pause");
	return retorno;
}

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {

	FILE *fp;
	Employee *Empleado;
	int retorno = -1;
	int len;
	int i;
	int auxId;
	char auxNombre[128];
	int auxHora;
	int auxSueldo;

	if (pArrayListEmployee != NULL && path != NULL) {
		fp = fopen(path, "w");

		len = ll_len(pArrayListEmployee);

		if (len != 0) {
			if (fp != NULL) {

				fprintf(fp, "%s, %s, %s, %s\n", "ID", "Nombre",
						"Horas Trabajadas", "Sueldo");

				for (i = 0; i < len; i++) {

					Empleado = (Employee*) ll_get(pArrayListEmployee, i);

					if (employee_getId(Empleado, &auxId) == 0
							&& employee_getNombre(Empleado, auxNombre) == 0
							&& employee_getSueldo(Empleado, &auxSueldo) == 0
							&& employee_getHorasTrabajadas(Empleado, &auxHora)
									== 0) {

						fprintf(fp, "%d, %s, %d, %d\n", auxId, auxNombre,
								auxHora, auxSueldo);

					}
				}

				printf("Guardado con éxito \n");
				retorno = 0;
			}
		} else {
			printf("No hay datos cargados \n");
		}
		fclose(fp);
	}
	system("pause");
	return retorno;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {

	FILE *fp;
	Employee *Empleado;
	int retorno = -1;
	int len;
	int i;

	if (pArrayListEmployee != NULL && path != NULL) {

		len = ll_len(pArrayListEmployee);

		if (len != 0) {

			fp = fopen(path, "wb");
			if (fp != NULL) {

				len = ll_len(pArrayListEmployee);

				for (i = 0; i < len; i++) {

					Empleado = (Employee*) ll_get(pArrayListEmployee, i);

					if (Empleado != NULL) {

						fwrite(Empleado, sizeof(Employee), 1, fp);
					}
				}
				printf("Guardado con éxito \n");
				retorno = 0;
			}
			fclose(fp);
		} else {
			printf("No hay datos cargados \n");
		}
	}
	system("pause");
	return retorno;
}

