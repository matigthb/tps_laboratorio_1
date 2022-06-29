/*
 * nexo.h
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "input.h"
#include "TypePassenger.h"
#include "Passenger.h"
#include "StatusFlight.h"
#include "ArrayPassenger.h"



/// @brief Funcion para pedir el ingreso de un pasajero
///
/// @param unPasajero pasajero a mostrar
/// @param statusList lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typeList lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
/// @return pasajero cargado con todos los campos
sPassenger pedirPasajero(sPassenger unPasajero, sStatusFlight statusList[], int sizeStatus, sTypePassenger typeList[], int sizeType);

/// @brief Funcion para realizar los procesos necesarios que dan de alta a un pasajero
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param typeList lista de tipos de pasajeros
/// @param sizeType tamaño de la lista de pásajeros
/// @param statusList lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados
/// @return confirmacion de cambios realizados
int AltaPasajero(sPassenger passengerList[], int size, sTypePassenger typeList[], int sizeType, sStatusFlight statusList[], int sizeStatus);

/// @brief Funcion que encuentra una descripcion de tipo que coincide con el pasajero
///
/// @param sPassenger passenger pasajero a validar
/// @param sTypePassenger typePassenger lista de tipos de pasajero
/// @param int size tamaño de la lista de tipos de pasajero
/// @return indice de la descripcion de un tipo que coincide con el pasajero recibido
int DescripcionType(sPassenger passenger,sTypePassenger typePassenger[], int size);

/// @brief Funcion que encuentra una descripcion de estado que coincide con el pasajero
///
/// @param sPassenger passenger pasajero a validar
/// @param sStatusFlight statusFlight lista de estados de vuelo
/// @param int size tamaño de la lista de estados de vuelo
/// @return indice de la descripcion de un estado que coincide con el pasajero recibido
int DescripcionStatus(sPassenger passenger,sStatusFlight statusFlight[], int size);

/// @brief Funcion para mostrar un pasajero recibido
///
/// @param sPassenger passenger pasajero a mostrar
/// @param sStatusFlight statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
void mostrarUnPasajero(sPassenger passenger, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType);

/// @brief Funcion para mostrar listados en la opcion 4
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de vuelo
void MostrarListados(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType);

/// @brief Funcion para mostrar los promedios calculados entre los pasajeros designados
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
/// @param totalPasajeros precio total acumulado entre todos los pasajeros cargados
/// @param promedioPasajeros promedio calculado entre todos los pasajeros cargados
void MostrarPromedios(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType, float totalPasajeros, float promedioPasajeros);

/// @brief Funcion para mostrar todos los pasajeros con un filtro de estado activo
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
void printFiltrados(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType);

/// @brief Funcion para mostrar pasajeros en consola
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de lista de tipos de pasajero
/// @param mensaje mensaje para explicar lo que se esta mostrando
/// @return confirmacion de que pasajeros fueron encontrados para hacer el print.
int printPassengers(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus,sTypePassenger typePassenger[], int sizeType, char mensaje[]);

#endif /* NEXO_H_ */
