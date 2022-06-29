/*
 * TypePassenger.h
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

#include "input.h"

typedef struct
{
	int idType;
	char descriptionType[21];
}sTypePassenger;


/// @brief Funcion para mostrar lista de tipos de pasajeros
///
/// @param typePassenger
/// @param size
void TypePassenger(sTypePassenger typePassenger[], int size);

#endif /* TYPEPASSENGER_H_ */
