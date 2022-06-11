#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	LinkedList* listaPasajeros = ll_newLinkedList();
	int option = 0;
	int validar=0;
	int flagSave=0;
	//int flagLoad=0;

	Passenger_UpdateID(1000);//INICIALIZO IDS

	do{
		option = IngresarEntero( "|-------------------------------------------------------------------------------|\n"
				 "|1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).   |\n"
				 "|2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). |\n"
				 "|3. Alta de pasajero                                                            |\n"
				 "|4. Modificar datos de pasajero                                                 |\n"
				 "|5. Baja de pasajero                                                            |\n"
				 "|6. Listar pasajeros                                                            |\n"
				 "|7. Ordenar pasajeros                                                           |\n"
				 "|8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).     |\n"
				 "|9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).   |\n"
				 "|10. Salir                                                                      |\n"
				 "|-------------------------------------------------------------------------------|\n"
				 "Ingrese una opcion: ","Opcion invalida, ingrese otra: ", 1, 10);

		switch(option)
		{
			case 1:
				validar = controller_loadFromText("data.csv", listaPasajeros);
				if(validar==1)
				{
					printf("Se cargó correctamente la lista de pasajeros en modo texto.\n");
				}
				else
				{
					printf("No se cargó\n");
				}
			break;

			case 2:
				validar = controller_loadFromBinary("data.bin", listaPasajeros);
				if(validar==1)
				{
					printf("Se cargó correctamente la lista de pasajeros en modo binario.\n");
				}
				else
				{
					printf("No se cargó\n");
				}
			break;

			case 3:
				validar = controller_addPassenger(listaPasajeros);
				if(validar==1)
				{
					printf("Se dio de alta correctamente.\n");
				}
				else
				{
					printf("No se pudo dar de alta.\n");
				}
			break;

			case 4:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					validar = controller_editPassenger(listaPasajeros);
					if(validar==1)
					{
						printf("Se modifico correctamente al pasajero.\n");
					}
					else
					{
						printf("No se pudo modificar.\n");
					}
				}
				else
				{
					printf("No existe ningun pasajero cargado para modificar.\n");
				}
			break;

			case 5:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					validar = controller_removePassenger(listaPasajeros);
					if(validar==1)
					{
						printf("Se elimino correctamente al pasajero.\n");
					}
				}
				else
				{
					printf("No hay pasajeros cargados para dar de baja.\n");
				}
			break;

			case 6:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					validar = controller_ListPassenger(listaPasajeros);
					if(validar==1)
					{
						printf("Se listaron correctamente todos los pasajeros.\n");
					}
					else
					{
						printf("No se pudo listar correctamente todos los pasajeros.\n");
					}
				}
				else
				{
					printf("No hay pasajeros cargados para listar.\n");
				}
			break;

			case 7:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					validar = controller_sortPassenger(listaPasajeros);
					if(validar==1)
					{
						printf("Se ordenaron correctamente todos los pasajeros.\n");
					}
					else
					{
						printf("No se pudo ordenar correctamente todos los pasajeros.\n");
					}
				}
				else
				{
					printf("No hay pasajeros cargados para ordenar.\n");
				}
			break;

			case 8:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					validar = controller_saveAsText("data.csv", listaPasajeros);
					if(validar==1)
					{
						printf("Se guardó correctamente la lista de pasajeros en modo texto.\n");
						flagSave=1;
					}
					else
					{
						printf("No se pudo cargar la lista.");
					}
				}
				else
				{
					printf("ERROR, La lista a guardar se encuentra vacia.\n");
				}
			break;

			case 9:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					validar = controller_saveAsBinary("data.bin", listaPasajeros);
					if(validar==1)
					{
						printf("Se guardó correctamente la lista de pasajeros en modo binario.\n");
						flagSave=1;
					}
					else
					{
						printf("No se pudo cargar la lista.\n");
					}
				}
				else
				{
					printf("ERROR, La lista a guardar se encuentra vacia.\n");
				}
			break;

			case 10:
				if(flagSave==1)
				{
					printf("Saliendo . . .\n");
				}
				else
				{
					printf("No se puede salir del programa sin antes guardar cambios.\n");
					option = 0;
				}
			break;
		}
	}while(option != 10);

}



