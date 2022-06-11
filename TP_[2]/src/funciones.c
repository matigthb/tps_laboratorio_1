/*
 * funciones.c
 *
 *  Created on: 10 may. 2022
 *      Author: MATI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

int AltaPasajero(sPassenger passengerList[], int size, sTypePassenger typeList[], int sizeType, sStatusFlight statusList[], int sizeStatus)
{
	int index = -1;

	sPassenger unPasajero;

	unPasajero = pedirPasajero(unPasajero, statusList, sizeStatus, typeList, sizeType);
	index = addPassengers(passengerList, size, unPasajero.id, unPasajero.name, unPasajero.lastName, unPasajero.price, unPasajero.flycode, unPasajero.typePassenger, unPasajero.statusFlight);

	return index;
}

void CargarCadena(char cadena[],char mensaje[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",cadena);
}

int CargaForzada(sPassenger passengerList[], int size)
{
	int retorno = -1;

	int id[] = {1000,1001,1002,1003,1004};
	char name[][51] = {"Juan", "German", "Martín", "Marta","Pedro"};
	char lastName[][51] = {"Gimenez", "Gonzalez", "Juarez", "Gimenez", "Flores"};
	float price[] = {49999.99,31000.00,89999.99,700000.00,99999.99};
	char flycode[][10] = {"BA2491A", "BA2490G", "LH5024F", "LA1164H", "C9192A"};
	int typePassenger[]={1,3,4,2,4};
	int statusFlight[]={2,3,1,2,1};
	int isEmpty[]={0,0,0,0,0};

	for(int i=0; i<size; i++)
	{
		passengerList[i].id = id[i];
		strcpy(passengerList[i].name, name[i]);
		strcpy(passengerList[i].lastName, lastName[i]);
		passengerList[i].price = price[i];
		strcpy(passengerList[i].flycode, flycode[i]);
		passengerList[i].typePassenger = typePassenger[i];
		passengerList[i].statusFlight = statusFlight[i];
		passengerList[i].isEmpty = isEmpty[i];
		retorno = 0;
	}

	return retorno;
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
	retorno = ConfirmarCadena(unPasajero.lastName);
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

int modificarPasajero(sPassenger passengerList[], int size, int id)
{
	int opcion;
	int index;
	float aux;

	int validacion;
	char nameaux[51];
	char lastNameaux[51];
	char priceaux[20];
	char flycode[10];
	int typePassenger;

	index = findPassengerById(passengerList, size, id);

	while(index==-1)
	{
		printf("El ID ingresado no pertenece a ningun pasajero registrado. Ingrese otro, o ingrese '0' si desea volver al menu principal\n");
		scanf("%d", &id);
		if(id!=0)
		{
			index = findPassengerById(passengerList, size, id);
		}
		else
		{
			main();
		}
	}

	do
	{
		printf(     "\n\n==================================\n"
					"|       1.Nombre                 |\n"
					"|       2.Apellido               |\n"
					"|       3.Precio                 |\n"
					"|       4.Tipo De Pasajero       |\n"
					"|       5.Codigo De Vuelo        |\n"
					"|           6.Salir              |\n"
					"==================================\n"
					"\n"
					"Ingrese una opcion: ");

		scanf("%d", &opcion);
		while(opcion < 1 || opcion > 6)
		{
			printf("Opcion inválida, elegir una correcta entre 1 y 7");
			scanf("%d", &opcion);
		}

		switch(opcion)
		{
			case 1:
				CargarCadena(nameaux,"Ingrese el nuevo nombre: \n");
				validacion = ValidarCadena(nameaux);
				while(validacion==0)
				{
					printf("Ingrese su nombre (solo letras): \n");
					fflush(stdin);
					gets(nameaux);
					validacion= ValidarCadena(nameaux);
				}
				strcpy(passengerList[index].name,nameaux);
				printf("El nombre del pasajero con ID:%d fue modificado correctamente. (nuevo nombre: %s)\n", id, nameaux);
			break;

			case 2:
				CargarCadena(lastNameaux,"Ingrese el nuevo apellido: \n");
				validacion= ValidarCadena(lastNameaux);
				while(validacion==0)
				{
					CargarCadena(lastNameaux,"Apellido inválido, ingrese uno nuevo: \n");
					validacion= ValidarCadena(lastNameaux);
				}
				strcpy(passengerList[index].lastName,lastNameaux);
				printf("El apellido del pasajero con ID:%d fue modificado correctamente. (Nuevo apellido: %s)\n", id, lastNameaux);
			break;

			case 3:
				CargarCadena(priceaux, "Ingrese el nuevo precio: \n");
				validacion = ConfirmarFloat(priceaux);
				while(validacion == -1 || (atof(priceaux) < 1))
				{
					printf("Precio inválido, ingrese otro: \n");
					gets(priceaux);
					validacion = ConfirmarFloat(priceaux);
				}

				aux = atof(priceaux);

				passengerList[index].price = aux;
				printf("El precio del pasajero con ID:%d fue modificado correctamente. (nuevo precio: %2.f)\n", id, aux);
			break;

			case 4:
				typePassenger = IngresarEntero("Ingrese el nuevo tipo de pasajero: \n", "ERROR, ingrese un tipo válido", 1, 4);

				passengerList[index].typePassenger = typePassenger;
				printf("El tipo del pasajero con ID:%d fue modificado correctamente. (nuevo tipo: %2.d)\n", id, typePassenger);
			break;

			case 5:
				CargarCadena(flycode,"Ingrese el nuevo código de vuelo: \n");
				validacion= DetectarEspeciales(flycode);
				while(validacion==0)
				{
					CargarCadena(flycode,"Apellido inválido, ingrese uno nuevo: \n");
					validacion= DetectarEspeciales(flycode);
				}
				strcpy(passengerList[index].lastName,flycode);
				printf("El código del pasajero con ID:%d fue modificado correctamente. (Nuevo código: %s)\n", id, flycode);
			break;

			case 6:
				printf("Volviendo al menu . . .");
			break;
		}
	}while(opcion!=6);

	return 0;
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

int obtenerID(int reset)
{
    static int idIncremental = 1000;

    if(reset == 1)
    {
    	idIncremental = 999;
    }
    return idIncremental++;
}

void StatusFlight(sStatusFlight statusFlight[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d %s\n", statusFlight[i].idStatus, statusFlight[i].descriptionStatus);
	}
}

void TypePassenger(sTypePassenger typePassenger[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d %s\n", typePassenger[i].idType, typePassenger[i].descriptionType);
	}
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

float CalcularPromedio(sPassenger passengerList[], int size)
{
	int cantidad=0;
	int total=0;
	float promedio;

	for(int i=0;i<size; i++)
	{
		if(passengerList[i].isEmpty == OCUPADO)
		{
			total = total + passengerList[i].price;
			cantidad++;
		}
	}

	promedio = total/cantidad;

	return promedio;
}

int DetectarCargas(sPassenger passengerList[], int size)
{
	int retorno = -1;

	for(int i=0; i<size;i++)
	{
		if(passengerList[i].isEmpty == OCUPADO)
		{
			retorno = 1;
		}
	}

	return retorno;
}

float CalcularTotal(sPassenger passengerList[], int size)
{
	float total=0;

	for(int i=0;i<size; i++)
	{
		if(passengerList[i].isEmpty == OCUPADO)
		{
			total = total + passengerList[i].price;
		}
	}

	return total;
}
