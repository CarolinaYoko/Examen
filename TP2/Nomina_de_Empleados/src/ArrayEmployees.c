
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "ArrayEmployees.h"

#define TAM 5
#define LEN 51
#define TRUE 0
#define FALSE 1
#define UP 1
#define DOWN 0

int initEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int auxiliarAdd(Employee *Aux) {
	int retorno = -1;

	if (Aux != NULL) {

		utn_getTexto(Aux->name, "Ingrese nombre: ",
				"El nombre ingresado no es valido. Reingrese", 1, LEN, 2);
		utn_getTexto(Aux->lastName, "Ingrese apellido: ",
				"El apellido ingresado no es valido. Reingrese", 1, LEN, 2);
		utn_getNumeroFlotante(&Aux->salary, "Ingrese salario (u$s): ",
				"El numero ingresado no es valido. Reingrese", 0, 10000, 2);
		utn_getNumeroInt(&Aux->sector, "Ingrese sector: ",
				"El numero ingresado no es valido. Reingrese", 1, 50, 2);
		retorno = 0;
	}
	return retorno;
}

int addEmployee(Employee *list, int len, int id, char *name, char *lastName,
		float salary, int sector) {
	int retorno = -1;
	int i = 0;

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == TRUE) {

				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = FALSE;
				retorno = 0;
				break;
			}
		}
	}

	if (retorno == -1) {
		printf("No hay lugar disponible");
	}

	return retorno;
}

int printEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {

		printf("\t| %5s | %8s | %8s | %8s | %5s |\n", "ID", "Nombre",
				"Apellido", "Salario", "Sector");

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == FALSE) {

				printf("\t| %5d | %8s | %8s | %8.2f | %6d |\n", list[i].id,
						list[i].name, list[i].lastName, list[i].salary,
						list[i].sector);
			}

		}
		retorno = 0;
	}

	return retorno;
}

int findEmployeeById(Employee *list, int len, int id) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				continue;
			} else if (list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int updateEmployee(Employee *list, int len) {
	int retorno = -1;
	int resultado;
	int id;
	int menu;
	int indice;

	resultado = utn_getNumeroInt(&id, "Ingrese el ID: ",
			"El ID no es valido. Reingrese", 1, 4096, 2);
	indice = findEmployeeById(list, len, id);

	if (list != NULL && len > 0 && resultado == 0 && indice != -1) {

		utn_getNumeroInt(&menu,
				"Ingrese el campo a modificar: \n\n1-Nombre \n2-Apellido \n3-Salario \n4-Sector \n",
				"La opcion no es valida. Reingrese", 1, 4, 2);

		switch (menu) {
		case 1:
			utn_getTexto(list[indice].name, "Ingrese nombre: ",
					"El nombre ingresado no es valido. Reingrese", 1, LEN, 2);
			break;
		case 2:
			utn_getTexto(list[indice].lastName, "Ingrese apellido: ",
					"El apellido ingresado no es valido. Reingrese", 1, LEN, 2);
			break;
		case 3:
			utn_getNumeroFlotante(&list[indice].salary,
					"Ingrese salario (u$s): ",
					"El numero ingresado no es valido. Reingrese", 0, 10000, 2);
			break;
		case 4:
			utn_getNumeroInt(&list[indice].sector, "Ingrese sector: ",
					"El numero ingresado no es valido. Reingrese", 1, 50, 2);
			break;
		}
		retorno = 0;

	}
	return retorno;
}

int removeEmployee(Employee *list, int len) {
	int retorno = -1;
	int id;
	int indice;

	utn_getNumeroInt(&id, "\nIngrese el ID a eliminar: ",
			"El ID no es valido. Reingrese", 1, 4096, 2);
	indice = findEmployeeById(list, len, id);

	if (list != NULL && len > 0 && indice > 0) {
		list[indice].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}
