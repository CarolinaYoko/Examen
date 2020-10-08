/*
 ============================================================================
 Name        : Tp_n2.c
 Author      : Carolina Yokoyama
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

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

int sortEmployees(Employee *list, int len, int order);

int main(void) {

	setbuf(stdout, NULL);

	Employee arrayEmployees[TAM];
	Employee Aux;
	int opcion;
	int subopcion;
	int respuestaMenu;
	char respuestaContinuar = 's';
	int respuestaSubMenu;
	int resultadoSubMenuOp4;
	int order;
	int contadorId = 0;

	initEmployees(arrayEmployees, TAM);

	do {
		respuestaMenu = utn_getNumeroInt(&opcion, "\nMENU DE OPCIONES: \n\n"
				"1.ALTA \n"
				"2.MODIFICAR \n"
				"3.BAJA \n"
				"4.INFORMAR \n"
				"5.SALIR\n"
				"Ingrese una opcion: \n\n",
				"La opcion ingresada no es valida \n", 1, 5, 2);

		if (!respuestaMenu) {

			switch (opcion) {
			case 1:
				printf("----ALTA EMPLEADO----\n\n");
				contadorId++;
				auxiliarAdd(&Aux);
				addEmployee(arrayEmployees, TAM, contadorId, Aux.name,
						Aux.lastName, Aux.salary, Aux.sector);
				break;
			case 2:
				printf("----MODIFICAR EMPLEADO----\n\n");
				updateEmployee(arrayEmployees, TAM);
				break;
			case 3:
				printf("----BAJA EMPLEADO----\n\n");
				printEmployees(arrayEmployees, TAM);
				removeEmployee(arrayEmployees, TAM);
				break;
			case 4:
				printf("----INFORMES----\n\n");
				printEmployees(arrayEmployees, TAM);
				respuestaSubMenu =
						utn_getNumeroInt(&subopcion,
								"\n1. Listado de empleados ordenados alfabeticamente por Apellido y Sector \n"
										"2. Total y promedio de salarios, y cantidad de empleados que superan el salario promedio \n\n Ingrese una opcion: ",
								"La opcion ingresada no es valida \n", 1, 2, 2);
				if (respuestaSubMenu == 0) {
					switch (subopcion) {
					case 1:
						resultadoSubMenuOp4 =
								utn_getNumeroInt(&order,"Ingrese el orden: ascendente(1) o desdendente (0) \n\nIngrese una opcion: ","El numero no es valido. Reingrese \n", 0,	1, 2);
						if (resultadoSubMenuOp4 == 0) {
							sortEmployees(arrayEmployees,TAM, order);
							printEmployees(arrayEmployees, TAM);
						}
						break;
					case 2:

						break;
					}
				}

				break;
			case 5:
				printf("¿Esta seguro que desea salir?: s/n");
				fflush(stdin);
				scanf("%c", &respuestaContinuar);
				break;
			}
		} else {
			printf("Se terminaron los intentos. Reinicie");
		}
	} while (respuestaContinuar == 's');

	return EXIT_SUCCESS;
}

int sortEmployees(Employee *list, int len, int order) {
	int retorno = -1;
	int i;
	int j;
	Employee aux;

	if (list != NULL && len > 0) {

		switch (order) {
		case 0: //Orden ascendente
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {

					if (strcmp(list[i].lastName, list[j].lastName) < 0) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					} else if (strcmp(list[i].lastName, list[j].lastName) == 0
							&& list[i].sector < list[j].sector) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		case 1: //Orden descendente
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {

					if (strcmp(list[i].lastName, list[j].lastName) > 0) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					} else if (strcmp(list[i].lastName, list[j].lastName) == 0
							&& list[i].sector > list[j].sector) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		}
	}

	return retorno;
}
