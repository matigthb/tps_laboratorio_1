#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int validacion=0;


	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo!=NULL)
		{
			validacion = parser_PassengerFromText(pArchivo, pArrayListPassenger);
		}

		fclose(pArchivo);
	}

    return validacion;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int validacion=0;


	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path, "rb");

		if(pArchivo!=NULL)
		{
			validacion = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
		}

		fclose(pArchivo);
	}

	return validacion;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[100];
	char apellido[100];
	float precio;
	char flycode[100];
	char tipoPasajero[100];
	char statusFlight[100];
	int retorno=0;
	int validacion=0;
	Passenger* auxPasajero=NULL;

	//ll_add(pArrayListPassenger, unPasajero);

	id = Passenger_NewID();
	CargarCadena(nombre, "Ingrese el nombre del pasajero: ", "Nombre incorrecto, ingrese otro: ",1);
	CargarCadena(apellido, "Ingrese el apellido del pasajero: ", "Apellido incorrecto, ingrese otro: ",1);
	precio = IngresarFlotante("Ingrese el precio del vuelo: ", "Precio incorrecto, ingrese otro: ", 0);
	CargarCadena(flycode, "Ingrese el flycode del pasajero: ", "Flycode incorrecto, ingrese otro: ",0);
	strupr(flycode);
	CargarCadena(tipoPasajero, "Ingrese el tipo de pasajero: ", "Tipo incorrecto, ingrese otro: ",1);
	CargarCadena(statusFlight, "Ingrese el estado del vuelo: ", "Estado incorrecto, ingrese otro: ",1);

	auxPasajero = Passenger_new();

	validacion = Passenger_setOne(auxPasajero, id, nombre, apellido, precio, flycode, tipoPasajero, statusFlight);
	if(validacion==1)
	{
		ll_add(pArrayListPassenger, auxPasajero);
		Passenger_UpdateID(id);
		retorno = 1;
	}

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int validacion = 0;
	int id;
	int index = 0;
	char respuesta;
	int option;

	Passenger* unPasajero;

	if(pArrayListPassenger!=NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		id = IngresarEntero("Ingrese el ID del pasajero a modificar: ","ID invalido, ingrese otro: ", 1, 100000);
		index = controller_searchById(pArrayListPassenger, id);

		if(index != -1)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, index);

			Passenger_printOne(unPasajero);

			printf("Desea modificar este pasajero? ('s' / 'n'): ");
			fflush(stdin);
			scanf("%c", &respuesta);
			while(respuesta != 's' && respuesta != 'n')
			{
				printf("Respuesta incorrecta, Ingrese 's' para proseguir, 'n' para volver al menu: ");
				fflush(stdin);
				scanf("%c", &respuesta);
			}

			if(respuesta == 's')
			{

				do
				{
					option = IngresarEntero( "|-------------------------|\n"
											 "|    1_Nombre.            |\n"
											 "|    2_Apellido.          |\n"
											 "|    3_Precio.            |\n"
											 "|    4_Codigo de vuelo.   |\n"
											 "|    5_Tipo de pasajero.  |\n"
											 "|        6_SALIR.         |\n"
											 "|-------------------------|","Opcion invalida, ingrese otra: ", 1, 6);
					switch(option)
					{
						case 1:
							Passenger_modifyName(unPasajero);
						break;

						case 2:
							Passenger_modifyLastName(unPasajero);
						break;

						case 3:
							Passenger_modifyPrice(unPasajero);
						break;

						case 4:
							Passenger_modifyFlycode(unPasajero);
						break;


						/*case 5:
							caseTipoPasajero(listaPasajeros, index, pasajeroAuxiliar);
						break;*/

						case 6:
							printf("Saliendo . . .\n");
						break;
					}
				}while(option != 6);
			}
			else
			{
				printf("Retornando al menu principal. . .\n");
			}
		}
		else
		{
			printf("El ID ingresado no existe.\n");
		}

	}

    return validacion;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int validacion = 0;
	int id;
	int index = 0;
	char respuesta;

	Passenger* unPasajero;

	if(pArrayListPassenger!=NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		id = IngresarEntero("Ingrese el ID del pasajero a eliminar: ","ID invalido, ingrese otro: ", 1, 100000);
		index = controller_searchById(pArrayListPassenger, id);

		if(index != -1)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, index);

			if(unPasajero != NULL)
			{
				Passenger_printOne(unPasajero);

				printf("Desea modificar este pasajero? ('s' / 'n'): ");
				fflush(stdin);
				scanf("%c", &respuesta);
				while(respuesta != 's' && respuesta != 'n')
				{
					printf("Respuesta incorrecta, Ingrese 's' para proseguir, 'n' para volver al menu: ");
					fflush(stdin);
					scanf("%c", &respuesta);
				}

				if(respuesta == 's')
				{
					ll_remove(pArrayListPassenger, index);
					Passenger_delete(unPasajero);
					validacion = 1;
				}
			}
		}
	}

    return validacion;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno=0;
    int size;
	int validacion;
	Passenger* unPasajero;

    if(pArrayListPassenger != NULL)
    {
		size = ll_len(pArrayListPassenger);

		if(size>0)
		{
			printf("| ID |          NOMBRE         |    APELLIDO   |  PRECIO  |  FLYCODE | TIPO PASAJERO |  ESTADO  |\n");
			for(int i=0; i<size; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unPasajero!=NULL)
				{
					validacion = Passenger_printOne(unPasajero);

					if(validacion == 1)
					{
						retorno = 1;
					}
					else
					{
						retorno = 0;
						break;
					}
				}
			}
			printf("|-----------------------------------------------------------------------------------------------|\n");
		}
    }

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	int ordenamiento;
	int opcion;
	LinkedList* clon=NULL;

	if(pArrayListPassenger!=NULL)
	{
		clon = ll_clone(pArrayListPassenger);

		if(clon != NULL)
		{
			do
			{
				opcion = IngresarEntero("\n|---------------------------------|\n"
										  "| 1. Ordenar por ID               |\n"
										  "| 2. Ordenar por Nombre           |\n"
										  "| 3. Ordenar por Tipo de Pasajero |\n"
										  "| 4. SALIR                        |\n"
										  "|---------------------------------|\n"
										  "Ingrese una opcion: ", "Opcion incorrecta, ingrese otra: ", 1, 4);

				if(opcion != 4)
				{
					ordenamiento = IngresarEntero("\n|--------------------------------|\n"
											        "| 0. Orden Descendente           |\n"
												    "| 1. Orden Ascendente            |\n"
												    "|--------------------------------|\n"
												    "Ingrese una opcion: ", "Opcion incorrecta, ingrese otra: ", 0, 1);
				}

				switch(opcion)
				{
					case 1:
						ll_sort(clon, Passenger_CompareById, ordenamiento);
						controller_ListPassenger(clon);
						retorno = 1;
					break;

					case 2:
						ll_sort(clon, Passenger_CompareByName, ordenamiento);
						controller_ListPassenger(clon);
						retorno = 1;
					break;

					case 3:
						ll_sort(clon, Passenger_CompareByType, ordenamiento);
						controller_ListPassenger(clon);
						retorno = 1;
					break;

					case 4:
						printf("Volviendo al menú. . .");
						retorno = 1;
					break;
				}

			}while(opcion!=4);
		}

	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* unPasajero = NULL;
	int size;
	int validacion = 0;
	int retorno = 0;
	int id;
	char nombre[100];
	char apellido[100];
	float precio;
	char flycode[100];
	char tipoPasajero[100];
	char statusFlight[100];

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		size = ll_len(pArrayListPassenger);
		pFile = fopen(path, "w");

		if(pFile!=NULL && size>0)
		{
			fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n", "id", "nombre", "apellido", "precio", "flycode", "tipoPasajero", "statusFlight");

			for(int i=0; i<size; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unPasajero!=NULL)
				{
					validacion = Passenger_getOne(unPasajero, &id, nombre, apellido, &precio, flycode, tipoPasajero, statusFlight);

					if(validacion == 1)
					{
						fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", id, nombre, apellido, precio, flycode, tipoPasajero, statusFlight);
						retorno = 1;
					}
				}
			}
		}

		Passenger_UpdateID(id);
	}

	fclose(pFile);

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* unPasajero = NULL;
	int size;
	int validacion = 0;
	int idContador=0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		size = ll_len(pArrayListPassenger);
		pFile = fopen(path, "wb");

		if(pFile!=NULL && size>0)
		{
			for(int i=0; i<size; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unPasajero!=NULL)
				{
					fwrite(unPasajero, sizeof(Passenger)*1, 1, pFile);
					idContador++;
					validacion = 1;
				}
			}

			Passenger_UpdateID(idContador);
		}
	}

	fclose(pFile);

    return validacion;
}

/// @brief funcion que busca un pasajero por su ID
///
/// @param pArrayListPassenger
/// @param id
/// @return indice del pasajero encontrado
int controller_searchById(LinkedList* pArrayListPassenger, int id)
{
	int indice=-1;
	int size;
	int idBuscado;

	Passenger* unPasajero;

	size = ll_len(pArrayListPassenger);

	for(int i = 0; i<size; i++)
	{
		unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

		Passenger_getId(unPasajero, &idBuscado);

		if(idBuscado == id)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

