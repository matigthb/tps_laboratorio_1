/*
 * ArrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: MATI
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "Passenger.h"

// FUNCIONES OBLIGATORIAS
/// @brief Funcion para inicializar de todos los pasajeros en vacio
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de tipos de pasajeros
/// @return validacion de que cambios fueron realizados
int initPassengers(sPassenger passengerList[], int size);

/// @brief Funcion para cargar pasajeros a la lista general
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param id identificacion del pasajero a cargar
/// @param name nombre del pasajero a cargar
/// @param lastName apellido del pasajero a cargar
/// @param price precio del pasajero a cargar
/// @param flycode codigo de vuelo del pasajero a cargar
/// @param typePassenger tipo de pasajero del pasajero a cargar
/// @param statusFlight estado de vuelo del pasajero a cargar
/// @return validacion de que cambios fueron realizados
int addPassengers(sPassenger passengerList[], int size, int id, char name[], char lastName[],float price, char flycode[], int typePassenger, int statusFlight);

/// @brief Funcion para encontrar un pasajero que coincida con el ID que se necesite
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param id identificacion del pasajero a cargar
/// @return retorno del indice del pasajero con el ID solicitado y enviado como parametro
int findPassengerById(sPassenger passengerList[], int size, int id);

/// @brief Funcion para Borrar Pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param id identificacion de el pasajero a borrar
/// @return validacion de que cambios fueron realizados
int removePassenger(sPassenger passengerList[], int size, int id);

/// @brief Funcion que ordena pasajeros por apellido y tipo de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param order criterio de orden del array(1 ascendente, -1 descendente)
/// @return validacion de que cambios fueron realizados
int sortPassengers(sPassenger passengerList[], int size, int order);

/// @brief Funcion para ordenar pasajeros por código de vuelo
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param order criterio de orden para el array de pasajeros (1 ascendente, -1 descendente)
/// @return confirmacion de cambios realizados
int sortPassengersByCode(sPassenger passengerList[], int size, int order);

/// @brief Funcion main
///
/// @return confirmacion de exit
int main(void);



#endif /* ARRAYPASSENGER_H_ */
