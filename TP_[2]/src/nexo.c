/*
 * nexo.c
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */

#include "nexo.h"

sPassenger pedirPasajero(sPassenger unPasajero, sStatusFlight statusList[], int sizeStatus, sTypePassenger typeList[], int sizeType)
{
	int retorno;

	unPasajero.id = obtenerID(0);
	CargarCadena(unPasajero.name, "Ingrese su nombre: ");
	retorno = ConfirmarCadena(unPasajero.name);
	while(retorno == 0)
	{
		CargarCadena(unPasajero.name, "Nombre inválido, ingrese uno nuevo: ");
		retorno = ConfirmarCadena(unPasajero.name);
	}
	DetectarEspacio(unPasajero.name);

	CargarCadena(unPasajero.lastName, "Ingrese su apellido: ");
	retorno = ConfirmarCadena(unPasajero.lastName);
	while(retorno == 0)
	{
		CargarCadena(unPasajero.lastName, "Apellido inválido, ingrese uno nuevo: ");
		retorno = ConfirmarCadena(unPasajero.lastName);
	}
	DetectarEspacio(unPasajero.lastName);

	unPasajero.price = IngresarFlotante("Ingrese el precio del viaje: ", "ERROR, ingrese un precio valido (de 0 a 2.000.000)", 0, 2000000);
	CargarCadena(unPasajero.flycode, "Ingrese su código de vuelo: ");
	printf("ESTADOS DE VUELO:\n");
	StatusFlight(statusList, sizeStatus);
	unPasajero.statusFlight = IngresarEntero("Ingrese el estado del vuelo (Del 1 al 4): ", "Dato inválido, ingrese un estado correcto", 1, 4);
	printf("TIPO DE PASAJERO:\n");
	TypePassenger(typeList, sizeType);
	unPasajero.typePassenger = IngresarEntero("Ingrese el tipo de vuelo (Del 1 al 3): ","Dato inválido, ingrese un tipo correcto", 1, 3);
	unPasajero.isEmpty = OCUPADO;

	return unPasajero;
}

int AltaPasajero(sPassenger passengerList[], int size, sTypePassenger typeList[], int sizeType, sStatusFlight statusList[], int sizeStatus)
{
	int index = -1;

	sPassenger unPasajero;

	unPasajero = pedirPasajero(unPasajero, statusList, sizeStatus, typeList, sizeType);
	index = addPassengers(passengerList, size, unPasajero.id, unPasajero.name, unPasajero.lastName, unPasajero.price, unPasajero.flycode, unPasajero.typePassenger, unPasajero.statusFlight);

	return index;
}

int DescripcionType(sPassenger passenger,sTypePassenger typePassenger[], int size)
{
    int index =-1;

    for(int i=0;i<size;i++)
    {
        if(passenger.typePassenger==typePassenger[i].idType)
        {
            index=i;
            break;
        }
    }
    return index;
}

int DescripcionStatus(sPassenger passenger,sStatusFlight statusFlight[], int size)
{
    int index =-1;

    for(int i=0;i<size;i++)
    {
        if(passenger.statusFlight==statusFlight[i].idStatus)
        {
            index=i;
            break;
        }
    }
    return index;
}

void mostrarUnPasajero(sPassenger passenger, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType)
{
	int typeDescription;
	int statusDescription;

	typeDescription = DescripcionType(passenger, typePassenger, sizeType);
	statusDescription = DescripcionStatus(passenger, statusFlight, sizeStatus);

    printf("\n|%-5d|",passenger.id);
    printf("%-15s|",passenger.name);
    printf("%-15s|",passenger.lastName);
    printf("%-13.2f|",passenger.price);
    printf("%-21s|",typePassenger[typeDescription].descriptionType);
    printf("%-20s|",statusFlight[statusDescription].descriptionStatus);
    printf("%-20s|",passenger.flycode);
}

void MostrarListados(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType)
{
	int opcion;
	int orden;
	int validacion;
	float promedio;
	int total;

	printf("\n---------------------------------------------------------------------------\n"
					"1_Pasajeros ordenados por Apellido y Tipo de Pasajero.\n"
					"2_Total y Promedios, y pasajeros que superan el promedio.\n"
					"3_Pasajeros ordenados por Código de vuelo y con estado de vuelo 'Activo'.\n"
					"\n---------------------------------------------------------------------------\n");
	scanf("%d", &opcion);

	switch(opcion)
	{
		case 1:
			printf( "Opcion elegida: Pasajeros ordenados por Apellido y Tipo de Pasajero.\n"
					"Debe elegir entre orden ascendente(Ingrese '1'), u orden descendente (Ingrese '0') ");
			scanf("%d", &orden);
			if(orden == 1)
			{
				sortPassengers(passengerList, size, 1);
			}
			else
			{
				sortPassengers(passengerList, size, -1);
			}

			validacion = printPassengers(passengerList, size, statusFlight, sizeStatus, typePassenger, sizeType, "Mostrando listado de Pasajeros por Apellido y Tipo de Pasajero");
			if(validacion ==-1)
			{
				printf("ERROR. No se pudo printear ningún pasajero.");
			}
		break;

		case 2:
			promedio = CalcularPromedio(passengerList, size);
			total = CalcularTotal(passengerList, size);

			MostrarPromedios(passengerList, size, statusFlight, sizeStatus, typePassenger, sizeType, total, promedio);
		break;

		case 3:
			printf( "Opcion elegida: Pasajeros ordenados por Codigo de vuelo y Estado del mismo.\n"
					"Debe elegir entre orden ascendente(Ingrese '1'), u orden descendente (Ingrese '0')\n");
			scanf("%d", &orden);
			if(orden == 1)
			{
				sortPassengersByCode(passengerList, size, 1);
			}
			else
			{
				sortPassengersByCode(passengerList, size, -1);
			}

			printFiltrados(passengerList, size, statusFlight, sizeStatus, typePassenger, sizeType);
		break;

	}
}

void MostrarPromedios(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType, float totalPasajeros, float promedioPasajeros)
{
	int contador=0;

	printf( "    TOTAL VIAJES            PROMEDIO\n"
			"        %2.f               %2.f", totalPasajeros, promedioPasajeros);

	printf("\n\nListado de pasajeros que superan el promedio:\n"
		           " __\n"
		           "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n\n"
		           "|=====|===============|===============|=============|=====================|====================|====================|", "ID", "Nombre", "Apellido", "Precio", "Tipo de pasajero", "Estado de Vuelo", "Codigo de vuelo");


	for(int i;i<size;i++)
	{
		if(passengerList[i].price > promedioPasajeros && passengerList[i].isEmpty == OCUPADO)
		{
			mostrarUnPasajero(passengerList[i], statusFlight, sizeStatus, typePassenger, sizeType);
			contador++;
		}
	}

	printf("\nExisten %d pasajeros que superan el promedio.", contador);
}

void printFiltrados(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType)
{
	for(int i=0; i<size;i++)
	{
		if(passengerList[i].statusFlight == 1)
		{
			mostrarUnPasajero(passengerList[i], statusFlight, sizeStatus, typePassenger, sizeType);
		}
	}
}

int printPassengers(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus,sTypePassenger typePassenger[], int sizeType, char mensaje[])
{
	int retorno=-1;

	printf("\n%s\n\n"
	           " ___________________________________________________________________________________________________________________\n"
	           "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
	           "|=====|===============|===============|=============|=====================|====================|====================|", mensaje, "ID", "Nombre", "Apellido", "Precio", "Tipo de pasajero", "Estado de Vuelo", "Codigo de vuelo");

	for(int i=0;i<size;i++)
	{
		if(passengerList[i].isEmpty == OCUPADO)
		{
			mostrarUnPasajero(passengerList[i], statusFlight, sizeStatus, typePassenger, sizeType);
			retorno = 0;
		}
	}

	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
	return retorno;
}
