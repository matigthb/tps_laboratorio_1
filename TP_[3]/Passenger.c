/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include "LinkedList.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Passenger_CompareByType(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char tipoUno[50];
	char tipoDos[50];

	if(p1 != NULL && p2 != NULL)
	{
		unPasajero = (Passenger*) p1;//UNBOXING
		otroPasajero = (Passenger*) p2;

		if(unPasajero != NULL && otroPasajero != NULL)
		{
			Passenger_getTipoPasajero(unPasajero, tipoUno);
			Passenger_getTipoPasajero(otroPasajero, tipoDos);

			compara = strcmp(tipoUno, tipoDos);
		}

	}

	return compara;
}

int Passenger_CompareByName(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char nombreUno[50];
	char nombreDos[50];

	if(p1 != NULL && p2 != NULL)
	{
		unPasajero = (Passenger*) p1;//UNBOXING
		otroPasajero = (Passenger*) p2;

		if(unPasajero != NULL && otroPasajero != NULL)
		{
			Passenger_getNombre(unPasajero, nombreUno);
			Passenger_getNombre(otroPasajero, nombreDos);

			compara = strcmp(nombreUno, nombreDos);
		}

	}

	return compara;
}

int Passenger_CompareById(void* p1, void* p2)
{
	int compara=0;
	Passenger* unPasajero;
	Passenger* otroPasajero;
	int id1;
	int id2;

	unPasajero = (Passenger*) p1;//UNBOXING
	otroPasajero = (Passenger*) p2;

	Passenger_getId(unPasajero, &id1);
	Passenger_getId(otroPasajero, &id2);

	if(id1 > id2)
	{
		compara = 1;
	}
	else
	{
		if(id1 < id2)
		{
			compara = -1;
		}
	}

	return compara;
}

Passenger* Passenger_new()
{
	Passenger* unPasajero = NULL;

	unPasajero = (Passenger*) malloc(sizeof(Passenger)*1);

	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr,  char* apellido, char* precio, char* tipoPasajeroStr, char* codigo,  char* statusFlight)
{
	Passenger* unPasajero=NULL;

	unPasajero = Passenger_new();

	if(idStr!=NULL && nombreStr!=NULL && apellido!=NULL && precio!=NULL && tipoPasajeroStr!=NULL && codigo!=NULL && statusFlight!=NULL && unPasajero != NULL)
	{
		Passenger_setId(unPasajero, atoi(idStr));
		Passenger_setNombre(unPasajero, nombreStr);
		Passenger_setApellido(unPasajero, apellido);
		Passenger_setPrecio(unPasajero,atof(precio));
		Passenger_setCodigoVuelo(unPasajero, codigo);
		Passenger_setTipoPasajero(unPasajero, tipoPasajeroStr);
		Passenger_setStatusFlight(unPasajero, statusFlight);
	}

	return unPasajero;
}

void Passenger_delete(Passenger* this)
{
	free(this);
	this = NULL;
}

int Passenger_setId(Passenger* this, int id)
{
	int validacion = 0;

	if(this!=NULL)
	{
		this->id = id;
		validacion = 1;
	}

	return validacion;
}

int Passenger_getId(Passenger* this, int* id)
{
	int validacion = 0;

	if(this!=NULL && id != NULL)
	{
		*id = this->id;
		validacion = 1;
	}

	return validacion;
}

void Passenger_UpdateID(int id)
{
	FILE* pFile;

	pFile = fopen("idLibrary.csv", "w");

	fprintf(pFile, "%d\n", id);

	fclose(pFile);
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int validacion = 0;

	if(this!=NULL)
	{
		strcpy(this->nombre, nombre);
		validacion = 1;
	}

	return validacion;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int validacion = 0;

	if(this!=NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		validacion = 1;
	}

	return validacion;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int validacion = 0;

	if(this!=NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		validacion = 1;
	}

	return validacion;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int validacion = 0;

	if(this!=NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		validacion = 1;
	}

	return validacion;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int validacion = 0;

	if(this!=NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		validacion = 1;
	}

	return validacion;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int validacion = 0;

	if(this!=NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		validacion = 1;
	}

	return validacion;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int validacion = 0;

	if(this!=NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		validacion = 1;
	}

	return validacion;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int validacion = 0;

	if(this!=NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		validacion = 1;
	}

	return validacion;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int validacion = 0;

	if(this!=NULL)
	{
		this->precio = precio;
		validacion = 1;
	}

	return validacion;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int validacion = 0;

	if(this!=NULL && precio != NULL)
	{
		*precio = this->precio;
		validacion = 1;
	}

	return validacion;
}

int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int validacion = 0;

	if(this!=NULL && statusFlight != NULL)
	{
		strcpy(this->statusFlight, statusFlight);
		validacion = 1;
	}

	return validacion;
}

int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int validacion = 0;

	if(this!=NULL && statusFlight != NULL)
	{
		strcpy(statusFlight, this->statusFlight);
		validacion = 1;
	}

	return validacion;
}

int Passenger_setOne(Passenger* this,int id, char* nombre, char* apellido, float precio, char* flycode, char* tipoPasajero, char* statusFlight)
{
	int validacion=0;

	if(Passenger_setId(this, id) == 1 &&
	   Passenger_setNombre(this, nombre) == 1 &&
	   Passenger_setApellido(this, apellido) == 1 &&
	   Passenger_setPrecio(this, precio) == 1 &&
	   Passenger_setCodigoVuelo(this, flycode) == 1 &&
	   Passenger_setTipoPasajero(this, tipoPasajero) == 1 &&
	   Passenger_setStatusFlight(this, statusFlight) == 1)
	{
		validacion = 1;
	}

	return validacion;
}

int Passenger_getOne(Passenger* this,int* id, char* nombre, char* apellido, float* precio, char* flycode, char* tipoPasajero, char* statusFlight)
{
	int validacion=0;

	if(Passenger_getId(this, id) == 1 &&
	   Passenger_getNombre(this, nombre) == 1 &&
	   Passenger_getApellido(this, apellido) == 1 &&
	   Passenger_getPrecio(this, precio) == 1 &&
	   Passenger_getCodigoVuelo(this, flycode) == 1 &&
	   Passenger_getTipoPasajero(this, tipoPasajero) == 1 &&
	   Passenger_getStatusFlight(this, statusFlight) == 1)
	{
		validacion = 1;
	}

	return validacion;
}

int Passenger_printOne(Passenger* unPasajero)
{
	int validacion=0;
	int retorno=0;
	int id;
	char nombre[100];
	char apellido[100];
	float precio;
	char flycode[100];
	char tipoPasajero[100];
	char statusFlight[100];

	validacion = Passenger_getOne(unPasajero, &id, nombre, apellido, &precio, flycode, tipoPasajero, statusFlight);

	if(validacion == 1)
	{
		printf("|%-4d|%-25s|%-15s|%-10.2f|%-10s|%-15s|%-10s|\n", id, nombre, apellido, precio, flycode, tipoPasajero, statusFlight);
		retorno = 1;
	}

	return retorno;

}

int Passenger_modifyName(Passenger* this)
{
	int retorno=0;
	char nombreActual[50];
	char nombreNuevo[50];
	char respuesta;

	if(this!=NULL)
	{
		Passenger_getNombre(this, nombreActual);
		CargarCadena(nombreNuevo, "Ingrese el nuevo nombre: ", "Nombre invalido, ingrese otro: ", 1);

		printf("Nombre actual: %s | Nuevo nombre: %s \nConfirma guardar los cambios? ('s' / 'n'): ", nombreActual, nombreNuevo);
		fflush(stdin);
		scanf("%c", &respuesta);

		if(respuesta == 's')
		{
			Passenger_setNombre(this, nombreNuevo);
		}

		retorno = 1;
	}

	return retorno;
}

int Passenger_modifyLastName(Passenger* this)
{
	int retorno=0;
	char apellidoActual[50];
	char apellidoNuevo[50];
	char respuesta;

	if(this!=NULL)
	{
		Passenger_getApellido(this, apellidoActual);
		CargarCadena(apellidoNuevo, "Ingrese el nuevo nombre: ", "Nombre invalido, ingrese otro: ", 1);

		printf("Nombre actual: %s | Nuevo nombre: %s \nConfirma guardar los cambios? ('s' / 'n'): ", apellidoActual, apellidoNuevo);
		fflush(stdin);
		scanf("%c", &respuesta);

		if(respuesta == 's')
		{
			Passenger_setApellido(this, apellidoNuevo);
		}

		retorno = 1;
	}

	return retorno;
}

int Passenger_modifyPrice(Passenger* this)
{
	int retorno=0;
	float precioActual;
	float precioNuevo;
	char respuesta;

	if(this!=NULL)
	{
		Passenger_getPrecio(this, &precioActual);
		precioNuevo = IngresarFlotante("Ingrese el nuevo precio: ", "Precio invalido, ingrese otro: ", 0);

		printf("Precio actual: %.2f | Nuevo Precio: %.2f \nConfirma guardar los cambios? ('s' / 'n'): ", precioActual, precioNuevo);
		fflush(stdin);
		scanf("%c", &respuesta);

		if(respuesta == 's')
		{
			Passenger_setPrecio(this, precioNuevo);
		}

		retorno = 1;
	}

	return retorno;
}

int Passenger_modifyFlycode(Passenger* this)
{
	int retorno=0;
	char flycodeActual[50];
	char flycodeNuevo[50];
	char respuesta;

	if(this!=NULL)
	{
		Passenger_getCodigoVuelo(this, flycodeActual);
		CargarCadena(flycodeNuevo, "Ingrese el nuevo codigo de vuelo: ", "Codigo invalido, ingrese otro: ", 0);

		printf("Codigo de vuelo actual: %s | Nuevo Codigo de vuelo: %s \nConfirma guardar los cambios? ('s' / 'n'): ", flycodeActual, flycodeNuevo);
		fflush(stdin);
		scanf("%c", &respuesta);

		if(respuesta == 's')
		{
			Passenger_setCodigoVuelo(this, flycodeNuevo);
		}

		retorno = 1;
	}

	return retorno;
}


int Passenger_NewID()
{
	FILE* pFile;
	char idStr[10];
	int id;

	pFile = fopen("idLibrary.csv", "r");

	if(pFile!=NULL)
	{
		do
		{
			fscanf(pFile, "%[^\n]\n", idStr);

		}while(!feof(pFile));
	}

	id = atoi(idStr);

	fclose(pFile);

	return id+1;
}
