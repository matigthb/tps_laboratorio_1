/*
 * Passenger.c
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */
#include "Passenger.h"
#include "ArrayPassenger.h"

int BuscarEspacioLibre(sPassenger passengerList[], int size)
{
	int index;
	index = -1; ///Por default no hay ninguno cargado;
	for(int i=0; i<size; i++)
	{
		if(passengerList[i].isEmpty != OCUPADO)
		{
			index = i;
			break;
		}
	}

	return index;
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
				validacion = ConfirmarCadena(nameaux);
				while(validacion==0)
				{
					printf("Ingrese su nombre (solo letras): \n");
					fflush(stdin);
					gets(nameaux);
					validacion= ConfirmarCadena(nameaux);
				}
				strcpy(passengerList[index].name,nameaux);
				printf("El nombre del pasajero con ID:%d fue modificado correctamente. (nuevo nombre: %s)\n", id, nameaux);
			break;

			case 2:
				CargarCadena(lastNameaux,"Ingrese el nuevo apellido: \n");
				validacion= ConfirmarCadena(lastNameaux);
				while(validacion==0)
				{
					CargarCadena(lastNameaux,"Apellido inválido, ingrese uno nuevo: \n");
					validacion= ConfirmarCadena(lastNameaux);
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
				while(validacion==-1)
				{
					CargarCadena(flycode,"Flycode inválido, ingrese uno nuevo: \n");
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

int obtenerID(int reset)
{
    static int idIncremental = 1000;

    if(reset == 1)
    {
    	idIncremental = 999;
    }
    return idIncremental++;
}
