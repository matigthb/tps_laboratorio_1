/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: MATI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

///////////////////////////////////////////////////////////////////////////////////////////

int initPassengers(sPassenger passengerList[], int size)
{
	int retorno = -1;

	if(size > 0 && size <= 2000)
	{
		retorno = 0;
	}

	for(int i=0;i<size;i++)
	{
		passengerList[i].isEmpty = VACIO;
	}

	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////////

int addPassengers(sPassenger passengerList[], int size, int id, char name[], char lastName[],float price, char flycode[], int typePassenger, int statusFlight)
{
	int retorno = -1;
	int indice;

	indice = BuscarEspacioLibre(passengerList, size);

	if(indice >= 0 && indice < 2000)
	{
		passengerList[indice].id = id;
		strcpy(passengerList[indice].name, name);
		strcpy(passengerList[indice].lastName, lastName);
		passengerList[indice].price = price;
		strcpy(passengerList[indice].flycode, flycode);
		passengerList[indice].typePassenger = typePassenger;
		passengerList[indice].statusFlight = statusFlight;
		passengerList[indice].isEmpty = OCUPADO;
		retorno = 0;
	}

	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////////

int findPassengerById(sPassenger passengerList[], int size, int id)
{
	int retorno = -1;

	for(int i=0;i<size;i++)
	{
		if(passengerList[i].id == id && passengerList[i].isEmpty == OCUPADO)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////////

int removePassenger(sPassenger passengerList[], int size, int id)
{
	int retorno = -1;
	int index;

	index = findPassengerById(passengerList, size, id);

	if(index != -1)
	{
		passengerList[index].isEmpty = VACIO;
		retorno = 0;
	}

	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////////

int sortPassengers(sPassenger passengerList[], int size, int order)
{
	int retorno = -1;

	sPassenger auxiliar;
	for(int i=0; i<size-1; i++)
	{
		for(int j = i+1; j<size; j++)
		{
			if(strcmp(passengerList[i].lastName, passengerList[j].lastName) == order)
			{
				auxiliar = passengerList[i];
				passengerList[i] = passengerList[j];
				passengerList[j] = auxiliar;
				retorno = 0;
			}
			else
			{
				if(strcmp(passengerList[i].lastName, passengerList[j].lastName) == 0)
				{
					if(order<0)
					{
						if(passengerList[i].typePassenger < passengerList[j].typePassenger)
						{
							auxiliar=passengerList[i];
							passengerList[i]=passengerList[j];
							passengerList[j]=auxiliar;
						}
					}
					else
					{
						if(passengerList[i].typePassenger > passengerList[j].typePassenger)
						{
							auxiliar=passengerList[i];
							passengerList[i]=passengerList[j];
							passengerList[j]=auxiliar;
						}
					}
				}
			}
		}
	}

	return retorno;
}


///////////////////////////////////////////////////////////////////////////////////////////

int sortPassengersByCode(sPassenger passengerList[], int size, int order)
{
	int retorno;

	sPassenger auxiliar;
	for(int i=0; i<size-1; i++)
	{
		for(int j = i+1; j<size; j++)
		{
			if(strcmp(passengerList[i].flycode, passengerList[j].flycode) == order)
			{
				auxiliar = passengerList[i];
				passengerList[i] = passengerList[j];
				passengerList[j] = auxiliar;
				retorno = 0;
			}
			else
			{
				if(strcmp(passengerList[i].flycode, passengerList[j].flycode) == 0)
				{

					if(order == 1)
					{
						if(passengerList[i].statusFlight < passengerList[j].statusFlight)
						{
							auxiliar = passengerList[i];
							passengerList[i] = passengerList[j];
							passengerList[j] = auxiliar;
							retorno = 0;
						}
					}
					else
					{
						if(passengerList[i].statusFlight > passengerList[j].statusFlight)
						{
							auxiliar = passengerList[i];
							passengerList[i] = passengerList[j];
							passengerList[j] = auxiliar;
							retorno = 0;
						}
					}
				}
			}
		}
	}

	return retorno;

}
