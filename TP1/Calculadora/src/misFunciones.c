
#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"

float pedirNumero(char texto[]) {
	float numero;
	printf(texto);
	scanf("%f", &numero);
	return numero;

}

float sumarNumeros(float num1, float num2) {
	float suma;
	suma = num1 + num2;
	return suma;
}

float restarNumeros(float num1, float num2) {
	float resta;
	resta = num1 - num2;
	return resta;
}

float dividirNumeros(float num1, float num2) {
	float cociente;
	cociente = num1 / num2;
	return cociente;
}

float multiplicarNumeros(float num1, float num2) {
	float producto;
	producto = num1 * num2;
	return producto;
}

int validarNatural(float num) {
	int parteEntera;
	float decimal;
	int natural = 0;

	parteEntera = num;
	decimal = num - parteEntera;

	if (num<0 || decimal != 0) {
		natural = 1;
	}
	return natural;
}

double factorial(int num) {
	double fac;

	if(num<0){
		fac=0;
	}
	else if (num == 0) {
		fac = 1;
	}
	else {
		fac = num * factorial(num - 1);
	}

	return fac;
}


