/*
 * funciones.c
 *
 *
 *
 *
 *  Created on: 6 abr. 2022
 *      Author: MATI
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define BTC 4606954.55

float solicitarDato(char mensaje[])
{
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	while(numeroIngresado<0)
	{
		printf("Respuesta inválida, %s", mensaje);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

float CalcularDebito(float precioBruto)
{
	float resultado;
	float precioDescontado;
	float descuento;

	descuento = 10;

	precioDescontado = precioBruto * descuento / 100;

	resultado = precioBruto - precioDescontado;

	return resultado;
}

float CalcularCredito(float precioBruto)
{
	float resultado;
	float precioAumentado;
	float interes;

	interes = 25;

	precioAumentado = precioBruto * interes / 100;

	resultado = precioBruto + precioAumentado;

	return resultado;
}

float CalcularBTC(float precioBruto)
{
	float resultado;

	resultado = precioBruto / BTC;

	return resultado;
}

float CalcularUnitario(float precioBruto, float km)
{
	float resultado;

	resultado = precioBruto / km;

	return resultado;
}
float CalcularDiferencia(float precioAero, float precioLatam)
{
	float resultado;

	if(precioAero >= precioLatam)
	{
		resultado = precioAero - precioLatam;
	}
	else
	{
		resultado = precioLatam - precioAero;
	}

	return resultado;
}


