/*
 ============================================================================
 Name        : TP_2.c
 Author      : MATI
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

#define TAM 2000
#define TAMTYPE 3
#define TAMSTATUS 4

int main(void)
{
	setbuf(stdout, NULL);
	sPassenger passengerList[TAM];
	sTypePassenger typeList[TAMTYPE] = {{1, "Low Cost"} , {2, "Premium"} , {3, "Primera Clase"}};
	sStatusFlight statusList[TAMSTATUS] = {{1, "Activo"} , {2, "Volando"} , {3, "Cancelado"} , {4, "Demorado"}};

	int opcion;
	int retorno;
	int identificacion;
	int flag;
	int flagForzada=0;

	retorno = initPassengers(passengerList, TAM);
	if(retorno == -1)
	{
		printf("ERROR al inicializar pasajeros");
	}

	do
	{
		printf(   "\n-------------------------------------\n"
							 "-------------------------------------\n"
							 "BIENVENIDO ! ! !\n"
							 "-------------------------------------\n"
							 "-------------------------------------\n"
							 "1_ Dar de alta un Pasajero\n"
							 "2_ Modificar datos de un Pasajero\n"
							 "3_ Dar de baja a un Pasajero\n"
							 "4_ Informar listados\n"
							 "5_ Carga Forzada de 5 Pasajeros\n"
							 "6_ SALIR\n"
							 "-------------------------------------\n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				if(flagForzada == 1)
				{
					initPassengers(passengerList, TAM);
					retorno = obtenerID(1);
					flagForzada = 0;
				}
				retorno = AltaPasajero(passengerList, TAM, typeList, TAMTYPE, statusList, TAMSTATUS);

				if(retorno == -1)
				{
					printf("\nNo hay más espacio . . .\n");
				}
				else
				{
					printf("\nSe cargo exitosamente el pasajero!!\n");
				}
			break;
			case 2:
				flag = DetectarCargas(passengerList, TAM);
				if(flag == 1)
				{
					identificacion = IngresarEntero("Ingrese el id del pasajero a modificar: ", "ERROR, ingrese un ID válido", 1000, 3000);
					retorno = modificarPasajero(passengerList, TAM, identificacion);

					if(retorno == -1)
					{
						printf("\nERROR, no fue posible modificar los datos. . . \n");
					}
					else
					{
						printf("\nLos cambios se guardaron correctamente !!\n");
					}
				}
				else
				{
					printf("No se puede ingresar a la opción 2 sin tener ningún pasajero cargado.");
				}
			break;
			case 3:
				flag = DetectarCargas(passengerList, TAM);
				if(flag == 1)
				{
					identificacion = IngresarEntero("Ingrese el id del pasajero a eliminar: ","ERROR, ingrese un ID válido", 1000, 3000);
					retorno = removePassenger(passengerList, TAM, identificacion);
					if(retorno == -1)
					{
						printf("\nNo se pudo eliminar al pasajero.\n");
					}
					else
					{
						printf("\nSe elimino correctamente el pasajero.\n");
					}
				}
				else
				{
					printf("No se puede ingresar a la opción 3 sin tener ningún pasajero cargado.\n");
				}

			break;
			case 4:
				flag = DetectarCargas(passengerList, TAM);
				if(flag == 1)
				{
					MostrarListados(passengerList, TAM, statusList, TAMSTATUS, typeList, TAMTYPE);
				}
				else
				{
					printf("No se puede ingresar a la opción 4 sin tener ningún pasajero cargado.\n");
				}
			break;

			case 5:
				initPassengers(passengerList, TAM);
				retorno = CargaForzada(passengerList, 5);
				if(retorno == -1)
				{
					printf("\nNo se pudo realizar la carga forzada.\n");
				}
				else
				{
					printf("\nSe realizo correctamente la carga forzada.\n");
					flagForzada = 1;
				}
			break;

			case 6:
				printf("\nSaliendo...\nPrograma terminado.\n");
			break;

			default:
				printf("\nOpción inválida, ingrese una que se encuentre en el menú de opciones.\n");
			break;
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}
