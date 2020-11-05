#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	char auxId[4096];
	char auxNombre[4096];
	char auxHorasTrabajadas[4096];
	char auxsueldo[4096];
	char auxEncabezado[4096];
	Employee *auxEmpleado;

	if (pFile != NULL && pArrayListEmployee != NULL) {

		fscanf(pFile, "%[^\n]\n", auxEncabezado);
		do {
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre,
					auxHorasTrabajadas, auxsueldo) == 4) {
				auxEmpleado = employee_newParametros(auxId, auxNombre,
						auxHorasTrabajadas, auxsueldo);
				if (auxEmpleado != NULL) {
					if (ll_add(pArrayListEmployee, auxEmpleado) == 0) {
						retorno = 0;
					}
				}
			}
		} while (!feof(pFile));
	}

	return retorno;
}


int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {

	int retorno = -1;
	char auxId[4096];
	char auxHorasTrabajadas[4096];
	char auxsueldo[4096];
	Employee auxEmpleado;
	Employee *Empleado;

	if (pFile != NULL && pArrayListEmployee != NULL) {

		do {
			if (fread(&auxEmpleado, sizeof(auxEmpleado), 1, pFile) == 1) {

				sprintf(auxId, "%d", auxEmpleado.id);
				sprintf(auxHorasTrabajadas, "%d", auxEmpleado.horasTrabajadas);
				sprintf(auxsueldo, "%d", auxEmpleado.sueldo);


				Empleado = employee_newParametros(auxId, auxEmpleado.nombre,
						auxHorasTrabajadas, auxsueldo);
				if (Empleado != NULL) {

					if (ll_add(pArrayListEmployee, Empleado) == 0) {
						retorno = 0;
					}
				}
			}

		} while (!feof(pFile));
	}

	return retorno;
}
