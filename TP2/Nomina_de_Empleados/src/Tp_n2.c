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
	float acumuladorSalario = 0;
	float promedioSalario;
	int contadorEmpleado = 0;

	initEmployees(arrayEmployees, TAM);

	do {
		system("cls");
		respuestaMenu = utn_getNumeroInt(&opcion, "\nMENU DE OPCIONES: \n\n"
				"1.ALTA \n"
				"2.MODIFICAR \n"
				"3.BAJA \n"
				"4.INFORMAR \n"
				"5.SALIR\n"
				"Ingrese una opcion: ",
				"\nLa opcion no es valida. Reingrese \n", 1, 5, 2);

		if (!respuestaMenu) {
			system("cls");
			switch (opcion) {
			case 1:
				printf("----ALTA EMPLEADO----\n\n");
				contadorId++;
				auxiliarAdd(&Aux);
				system("cls");
				if (addEmployee(arrayEmployees, TAM, contadorId, Aux.name,
						Aux.lastName, Aux.salary, Aux.sector) == 0) {
					printf("\nAlta exitosa \n\n");
				} else {
					printf("\nError. Reintente\n");
				}
				system("pause");
				break;
			case 2:
				if (hayAltasEmpleados(arrayEmployees, TAM) == 1) {
					printf("----MODIFICAR EMPLEADO----\n\n");
					printEmployees(arrayEmployees, TAM);

					if (updateEmployee(arrayEmployees, TAM) == 0) {
						printf("\n\nModificacion exitosa \n\n");
						system("pause");
					} else {
						printf("\nError. Reintente\n");
					}
					system("cls");
				} else {
					printf(
							"\nNo hay empleados a modificar. Ingrese en Opcion 1. \n");
				}
				break;
			case 3:
				if (hayAltasEmpleados(arrayEmployees, TAM) == 1) {
					printf("----BAJA EMPLEADO----\n\n");
					printEmployees(arrayEmployees, TAM);
					if (removeEmployee(arrayEmployees, TAM) == 0) {
						printf("\nBaja exitosa \n\n");
					} else {
						printf("\nError. Reintente\n");
					}
					system("cls");
				} else {
					printf(
							"\nNo hay empleados a bajar. Ingrese en Opcion 1. \n");
				}
				break;
			case 4:
				if (hayAltasEmpleados(arrayEmployees, TAM) == 1) {
					printf("----INFORMES----\n\n");
					printEmployees(arrayEmployees, TAM);
					respuestaSubMenu =
							utn_getNumeroInt(&subopcion,
									"\n1. Listado de empleados ordenados alfabeticamente por Apellido y Sector \n"
											"2. Total y promedio de salarios, y cantidad de empleados que superan el salario promedio \n3. Volver al Menu principal \n\n Ingrese una opcion: ",
									"La opcion ingresada no es valida \n", 1, 3,
									2);
					if (respuestaSubMenu == 0) {
						switch (subopcion) {
						case 1:
							resultadoSubMenuOp4 =
									utn_getNumeroInt(&order,
											"Ingrese el orden: ascendente(1) o desdendente (0) \n\nIngrese una opcion: ",
											"El numero no es valido. Reingrese \n",
											0, 1, 2);
							if (resultadoSubMenuOp4 == 0) {
								sortEmployees(arrayEmployees, TAM, order);
								printEmployees(arrayEmployees, TAM);
								system("pause");
							}
							break;
						case 2:
							acumularSalario(arrayEmployees, TAM,
									&acumuladorSalario);
							calcularPromedioSalario(arrayEmployees, TAM,
									&promedioSalario);
							cuentaSuperaSalarioPromedio(arrayEmployees, TAM,
									promedioSalario, &contadorEmpleado);
							printf(
									"El total de salario de empleados es: %.2f \n",
									acumuladorSalario);
							printf("\nEl salario promedio es: %.2f \n",
									promedioSalario);
							printf(
									"\nLa cantidad de empleados que supera el sueldo promedio es: %d \n",
									contadorEmpleado);
							system("pause");
							break;

						case 3:
							break;
						}
					}
				} else {
					printf(
							"\nNo hay empleados a informar. Ingrese en Opcion 1. \n");
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




