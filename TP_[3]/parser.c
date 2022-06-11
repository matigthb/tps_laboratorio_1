#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char id[20];
	char nombre[50];
	char apellido[50];
	char precio[20];
	char tipoPasajero[100];
	char codigoVuelo[100];
	char statusFlight[100];
	Passenger* unPasajero = NULL;
	int cantidad;
	int validacion=0;


	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, tipoPasajero, codigoVuelo, statusFlight);

		do
		{
			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, tipoPasajero, codigoVuelo, statusFlight);

			if(cantidad == 7)
			{
				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);

				if(unPasajero!=NULL)
				{
					ll_add(pArrayListPassenger, unPasajero);
					validacion = 1;
				}
			}

		}while(!feof(pFile));

	}

    return validacion;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero = NULL;
	int validacion=0;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{

		do
		{
			unPasajero = Passenger_new();

			if(unPasajero!=NULL)
			{
				if(fread(unPasajero, sizeof(Passenger)*1, 1, pFile))
				{
					ll_add(pArrayListPassenger, unPasajero);
					validacion = 1;
				}
			}

		}while(!feof(pFile));

	}

	return validacion;
}
