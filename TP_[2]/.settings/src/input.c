/*
 * funciones.c
 *
 *  Created on: 10 may. 2022
 *      Author: MATI
 */

#include "input.h"

void CargarCadena(char cadena[],char mensaje[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",cadena);
}


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

float IngresarFlotante(char mensaje [], char mensajeError[], float min, float max)
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

	while(atof(numeroIngresado) < min || atof(numeroIngresado) > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		gets(numeroIngresado);
	}

	aux = atof(numeroIngresado);

	return aux;
}

int ConfirmarCadena(char cadena[])
{
    int size = strlen(cadena);
    int validacion=-1;

    for(int i=0;i<size;i++)
    {
        if(isdigit(cadena[i]) || isalpha(cadena[i]) == 0)
        {
            validacion=0;
        }
    }

    return validacion;
}

int ValidarCadena(char cadena[])
{
	int size = strlen(cadena);
	int validacion=-1;
	for(int i=0;i<size;i++)
	{
		if(isdigit(cadena[i]))
		{
			validacion=0;
		}
	}
	return validacion;
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

int DetectarEspeciales(char cadena[])
{
	int retorno = 0;
	int size = strlen(cadena);

	for(int i=0;i<size;i++)
	{
		if(!(cadena[i] > 65 && cadena[i] < 90) && !(cadena[i] > 97 && cadena[i] < 122) && !(cadena[i]>=48 && cadena[i]<=57))
		{
			retorno=-1;
		}
	}

	return retorno;
}

void DetectarEspacio (char string[])
{
    int i;
    int size;

    size= strlen(string);
    strlwr(string);

    for(i= 0; i<size; i++)
    {
        if(string[i-1]==32 || i==0)
        {
        	string[i] = toupper(string[i]);
        }
    }

}







