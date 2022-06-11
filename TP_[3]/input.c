/*
 * input.c
 *
 *  Created on: 6 jun. 2022
 *      Author: MATI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int IngresarEntero(char mensaje [], char mensajeError[], int min, int max)
{
	char numeroIngresado[10];
	int validacion;
	int aux;

	printf("%s", mensaje);
	fflush(stdin);
    gets(numeroIngresado);

	validacion = ConfirmarEntero(numeroIngresado);
	while(validacion == -1)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		gets(numeroIngresado);
		validacion = ConfirmarEntero(numeroIngresado);
	}

	while(atoi(numeroIngresado) < min || atoi(numeroIngresado) > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		gets(numeroIngresado);
	}

	aux = atoi(numeroIngresado);

	return aux;
}

int ConfirmarEntero(char numeros[])
{
    int validacion=0;
    int size;

    size = strlen(numeros);

    for(int i=0;i<size;i++)
    {
        if(numeros[i] < 48 || numeros[i] > 57)
        {
            validacion=-1;
        }
    }
    return validacion;
}

float IngresarFlotante(char mensaje [], char mensajeError[], float min)
{
	char numeroIngresado[10];
	int validacion;
	float aux;

	printf("%s", mensaje);
	fflush(stdin);
    gets(numeroIngresado);

	validacion = ConfirmarFloat(numeroIngresado);
	while(validacion == -1)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		gets(numeroIngresado);
		validacion = ConfirmarFloat(numeroIngresado);
	}

	while(atof(numeroIngresado) < min)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		gets(numeroIngresado);
	}

	aux = atof(numeroIngresado);

	return aux;
}

int ConfirmarFloat(char numeros[])
{
    int validacion=0;
    int size;

    size = strlen(numeros);

    for(int i=0;i<size;i++)
    {
        if((numeros[i]<48 || numeros[i]>57) && numeros[i] != 46 )
        {
            validacion=-1;
        }
    }
    return validacion;
}

void CargarCadena(char* cadena,char* mensaje, char* mensajeError, int validar)
{
	int validacion=0;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",cadena);

    if(validar==1)
    {
		validacion = ConfirmarCadena(cadena);
		while(validacion == 0)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",cadena);
			validacion = ConfirmarCadena(cadena);
		}
    }

    DetectarEspacio(cadena);

}

int ConfirmarCadena(char cadena[])
{
    int size = strlen(cadena);
    int validacion=-1;
    for(int i=0;i<size;i++)
    {
        if (isdigit(cadena[i]) || isalpha(cadena[i]) == 0)
        {
            validacion=0;
        }
    }
    return validacion;
}

void DetectarEspacio (char* cadena)
{
    int i;
    int size;

    size= strlen(cadena);
    strlwr(cadena);

    for(i= 0; i<size; i++)
    {
        if(cadena[i-1]==32 || i==0)
        {
        	cadena[i] = toupper(cadena[i]);
        }
    }

}
