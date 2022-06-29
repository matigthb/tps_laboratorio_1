/*
 * Passenger.h
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define VACIO 1
#define OCUPADO 0

#include "input.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}sPassenger;


/// @brief Funcion para detectar el primer espacio libre en el array de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @return Primer indice con espacio libre
int BuscarEspacioLibre(sPassenger passengerList[], int size);

/// @brief Funcion para realizar los procesos necesarios para modificar un dato dentro de un pasajero
///
/// @param sPassenger passengerList lista de pasajeros
/// @param int size longitud de la lista
/// @param int id numero de identificacion de un pasajero
/// @return validacion de cambios realizados
int modificarPasajero(sPassenger passengerList[], int size, int id);

/// @brief Funcion para detectar al menos un espacio ocupado del array
///
/// @param sPassenger passengerList lista de pasajeros a verificar
/// @param int size tamaño de la lista de pasajeros
/// @return indice de validacion, (0 por OK, -1 por caracter no deseado)
int DetectarCargas(sPassenger passengerList[], int size);

/// @brief funcion para calcular un promedio entre todos los precios de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @return promedio flotante de precios entre todos los pasajeros cargados
float CalcularPromedio(sPassenger passengerList[], int size);

/// @brief funcion para calcular un total entre todos los precios de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @return total de precios entre todos los pasajeros cargados
float CalcularTotal(sPassenger passengerList[], int size);

/// @brief Funcion para realizar la carga forzada
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista a cargar
/// @return confirmacion de cambios de datos
int CargaForzada(sPassenger passengerList[], int size);

/// @brief funcion para obtener el ID incremental
///
/// @param int reset para definir si se resetea el codigo o no, luego de una carga forzada
/// @return int ID incremental
int obtenerID(int reset);

#endif /* PASSENGER_H_ */
